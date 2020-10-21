#include <OneWire.h>
#include <DallasTemperature.h>
#include <PubSubClient.h>

#include "commands.h"
#include "featureboard.h"

#define MQTT_RETAIN_VALUES 1 // do we retain 1wire values?

#define MAXTEMPDIFFPERSEC 0.5 // what is the allowed temp difference per second which is allowed (to filter bad values)

#define MINREPORTEDS0TIME 5000 // how often s0 Watts are reported (not faster than this)
#define DALLASASYNC 0 //async dallas yes or no (default no, because async seems to break 1wire sometimes with current code)

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature DS18B20(&oneWire);

//global array for 1wire data
dallasDataStruct* actDallasData = 0;
int dallasDevicecount = 0;

//global array for s0 data
s0DataStruct actS0Data[NUM_S0_COUNTERS];

//global array for s0 Settings
s0SettingsStruct actS0Settings[NUM_S0_COUNTERS];

unsigned long nextalldatatime_dallas = 0;

unsigned long dallasTimer = 0;
unsigned int updateAllDallasTime = 30000; // will be set using heishmonSettings
unsigned int dallasTimerWait = 30000; // will be set using heishmonSettings

//volatile pulse detectors for s0
volatile unsigned long new_pulse_s0[2] = {0, 0};

void initDallasSensors(void (*log_message)(char*), unsigned int updateAllDallasTimeSettings, unsigned int dallasTimerWaitSettings) {
  char log_msg[256];
  updateAllDallasTime = updateAllDallasTimeSettings;
  dallasTimerWait = dallasTimerWaitSettings;
  DS18B20.begin();
  dallasDevicecount  = DS18B20.getDeviceCount();
  sprintf(log_msg, "Number of 1wire sensors on bus: %d", dallasDevicecount); log_message(log_msg);
  if ( dallasDevicecount > MAX_DALLAS_SENSORS) {
    dallasDevicecount = MAX_DALLAS_SENSORS;
    sprintf(log_msg, "Reached max 1wire sensor count. Only %d sensors will provide data.", dallasDevicecount); log_message(log_msg);
  }

  //init array
  actDallasData = new dallasDataStruct [dallasDevicecount];
  for (int j = 0 ; j < dallasDevicecount; j++) {
    DS18B20.getAddress(actDallasData[j].sensor, j);
  }

  DS18B20.requestTemperatures();
  for (int i = 0 ; i < dallasDevicecount; i++) {
    actDallasData[i].address[16] = '\0';
    for (int x = 0; x < 8; x++)  {
      // zero pad the address if necessary
      sprintf(&actDallasData[i].address[x * 2], "%02x", actDallasData[i].sensor[x]);
    }
    sprintf(log_msg, "Found 1wire sensor: %s", actDallasData[i].address ); log_message(log_msg);
  }
  if (DALLASASYNC) DS18B20.setWaitForConversion(false); //async 1wire during next loops
}

void readNewDallasTemp(PubSubClient &mqtt_client, void (*log_message)(char*), char* mqtt_topic_base) {
  char log_msg[256];
  char mqtt_topic[256];
  char valueStr[20];
  bool updatenow = false;

  if (millis() > nextalldatatime_dallas) {
    updatenow = true;
    nextalldatatime_dallas = millis() + (1000 * updateAllDallasTime);
  }
  if (!(DALLASASYNC)) DS18B20.requestTemperatures();
  for (int i = 0; i < dallasDevicecount; i++) {
    float temp = DS18B20.getTempC(actDallasData[i].sensor);
    if (temp < -120.0) {
      sprintf(log_msg, "Error 1wire sensor offline: %s", actDallasData[i].address); log_message(log_msg);
    } else {
      float allowedtempdiff = (((millis() - actDallasData[i].lastgoodtime)) / 1000.0) * MAXTEMPDIFFPERSEC;
      if ((actDallasData[i].temperature != -127.0) and ((temp > (actDallasData[i].temperature + allowedtempdiff)) or (temp < (actDallasData[i].temperature - allowedtempdiff)))) {
        sprintf(log_msg, "Filtering 1wire sensor temperature (%s). Delta to high. Current: %.2f Last: %.2f", actDallasData[i].address, temp, actDallasData[i].temperature); log_message(log_msg);
      } else {
        actDallasData[i].lastgoodtime = millis();
        if ((updatenow) || (actDallasData[i].temperature != temp )) {  //only update mqtt topic if temp changed or after each update timer
          actDallasData[i].temperature = temp;
          sprintf(log_msg, "Received 1wire sensor temperature (%s): %.2f", actDallasData[i].address, actDallasData[i].temperature); log_message(log_msg);
          sprintf(valueStr, "%.2f", actDallasData[i].temperature);
          sprintf(mqtt_topic, "%s/%s/%s", mqtt_topic_base, mqtt_topic_1wire, actDallasData[i].address); mqtt_client.publish(mqtt_topic, valueStr, MQTT_RETAIN_VALUES);
        }
      }
    }
  }
}

void dallasLoop(PubSubClient &mqtt_client, void (*log_message)(char*), char* mqtt_topic_base) {
  if ((DALLASASYNC) && (millis() > (dallasTimer - 1000))) {
    DS18B20.requestTemperatures(); // get temperatures for next run 1 second before getting the temperatures (async)
  }
  if (millis() > dallasTimer) {
    log_message((char*)"Requesting new 1wire temperatures");
    dallasTimer = millis() + (1000 * dallasTimerWait);
    readNewDallasTemp(mqtt_client, log_message, mqtt_topic_base);
  }
}

String dallasJsonOutput() {
  String output = "[";
  for (int i = 0; i < dallasDevicecount; i++) {
    output = output + "{";
    output = output + "\"Sensor\": \"" + actDallasData[i].address + "\",";
    output = output + "\"Temperature\": \"" + actDallasData[i].temperature + "\"";
    output = output + "}";
    if (i < dallasDevicecount - 1) output = output + ",";
  }
  output = output + "]";
  return output;
}

String dallasTableOutput() {
  String output = "";
  for (int i = 0; i < dallasDevicecount; i++) {
    output = output + "<tr>";
    output = output + "<td>" + actDallasData[i].address + "</td>";
    output = output + "<td>" + actDallasData[i].temperature + "</td>";
    output = output + "</tr>";
  }
  return output;
}

//These are the interrupt routines. Make them as short as possible so we don't block other interrupts (for example serial data)
ICACHE_RAM_ATTR void onS0Pulse1() {
  new_pulse_s0[0] = millis();
}

ICACHE_RAM_ATTR void onS0Pulse2() {
  new_pulse_s0[1] = millis();
}

void initS0Sensors(s0SettingsStruct s0Settings[], PubSubClient &mqtt_client, char* mqtt_topic_base) {
  //setup s0 port 1
  actS0Settings[0].gpiopin = s0Settings[0].gpiopin;
  actS0Settings[0].ppkwh = s0Settings[0].ppkwh;
  actS0Settings[0].lowerPowerInterval = s0Settings[0].lowerPowerInterval;
  actS0Settings[0].sum_s0_watthour = s0Settings[0].sum_s0_watthour;
  if (actS0Settings[0].sum_s0_watthour) {
    char mqtt_topic[256];
    sprintf(mqtt_topic, "%s/%s/Watthour/1", mqtt_topic_base, mqtt_topic_s0);
    mqtt_client.subscribe(mqtt_topic);
  }
  pinMode(actS0Settings[0].gpiopin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(actS0Settings[0].gpiopin), onS0Pulse1, RISING);
  actS0Data[0].nextReport = millis() + MINREPORTEDS0TIME; //initial report after interval, not directly at boot


  //setup s0 port 2
  actS0Settings[1].gpiopin = s0Settings[1].gpiopin;
  actS0Settings[1].ppkwh = s0Settings[1].ppkwh;
  actS0Settings[1].lowerPowerInterval = s0Settings[1].lowerPowerInterval;
  actS0Settings[1].sum_s0_watthour = s0Settings[1].sum_s0_watthour;
  pinMode(actS0Settings[1].gpiopin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(actS0Settings[1].gpiopin), onS0Pulse2, RISING);
  actS0Data[1].nextReport = millis() + MINREPORTEDS0TIME; //initial report after interval, not directly at boot
  if (actS0Settings[1].sum_s0_watthour) {
    char mqtt_topic[256];
    sprintf(mqtt_topic, "%s/%s/Watthour/2", mqtt_topic_base, mqtt_topic_s0);
    mqtt_client.subscribe(mqtt_topic);
  }  
}

void restore_s0_Watthour(int s0Port,float watthour) {
  Serial1.print(F("Restoring watthour from MQTT on s0 port: ")); Serial1.print(s0Port); Serial1.print(F(" with value: ")); Serial1.println(watthour);
  if ((s0Port = 0) || (s0Port = 1)) actS0Data[s0Port-1].pulses = int(watthour * (actS0Settings[s0Port-1].ppkwh / 1000.0));
}


void s0SettingsCorrupt(s0SettingsStruct s0Settings[], void (*log_message)(char*)) {
  for (int i = 0 ; i < NUM_S0_COUNTERS ; i++) {
    if ((s0Settings[i].gpiopin != actS0Settings[i].gpiopin) || (s0Settings[i].ppkwh != actS0Settings[i].ppkwh) || (s0Settings[i].lowerPowerInterval != actS0Settings[i].lowerPowerInterval)) {
      char log_msg[256];
      sprintf(log_msg, "S0 settings got corrupted, rebooting!" ); log_message(log_msg);
      delay(1000);
      ESP.restart();
    }
  }
}

void s0Loop(PubSubClient &mqtt_client, void (*log_message)(char*), char* mqtt_topic_base, s0SettingsStruct s0Settings[]) {

  //check for corruption
  s0SettingsCorrupt(s0Settings, log_message);

  unsigned long millisThisLoop = millis();

  for (int i = 0 ; i < NUM_S0_COUNTERS ; i++) {
    //first handle new detected pulses
    noInterrupts();
    unsigned long new_pulse = new_pulse_s0[i];
    interrupts();
    unsigned long pulseInterval = new_pulse - actS0Data[i].lastPulse;
    if (pulseInterval > 50L) { //50ms debounce filter, this also prevents division by zero to occur a few lines further down the road if pulseInterval = 0
      if (actS0Data[i].lastPulse > 0) { //Do not calculate watt for the first pulse since reboot because we will always report a too high watt. Better to show 0 watt at first pulse.
        actS0Data[i].watt = (3600000000.0 / pulseInterval) / actS0Settings[i].ppkwh;
      }
      actS0Data[i].lastPulse = new_pulse;
      actS0Data[i].pulses++;
      if ((actS0Data[i].nextReport - millisThisLoop) > MINREPORTEDS0TIME) { //loop was in standby interval
        actS0Data[i].nextReport = 0; // report now
      }
      Serial1.print(F("S0 port ")); Serial1.print(i); Serial1.print(F(" detected pulse. Pulses since last reset: ")); Serial1.println(actS0Data[i].pulses);
    }

    //then report after nextReport
    if (millisThisLoop > actS0Data[i].nextReport) {

      unsigned long lastePulseInterval = millisThisLoop - actS0Data[i].lastPulse;
      unsigned long calcMaxWatt = (3600000000.0 / lastePulseInterval) / actS0Settings[i].ppkwh;

      if (actS0Data[i].watt < ((3600000.0 / actS0Settings[i].ppkwh) / actS0Settings[i].lowerPowerInterval) ) { //watt is lower than possible in lower power interval time
        //Serial1.println(F("===In standby mode==="));
        actS0Data[i].nextReport = millisThisLoop + 1000 * actS0Settings[i].lowerPowerInterval;
        if ((actS0Data[i].watt) / 2 > calcMaxWatt) {
          //Serial1.println(F("===Previous standby watt is too high. Lowering watt, divide by two==="));
          actS0Data[i].watt = calcMaxWatt / 2;
        }
      }
      else {
        actS0Data[i].nextReport = millisThisLoop + MINREPORTEDS0TIME;
        if (actS0Data[i].watt > calcMaxWatt) {
          //Serial1.println(F("===Previous watt is too high. Setting watt to max possible watt==="));
          actS0Data[i].watt = calcMaxWatt;
        }
      }

      float Watthour = (actS0Data[i].pulses * ( 1000.0 / actS0Settings[i].ppkwh));
      if (!actS0Settings[i].sum_s0_watthour) actS0Data[i].pulses = 0; //per message we report new wattHour, so pulses should be zero at start new message

      //report using mqtt
      char log_msg[256];
      char mqtt_topic[256];
      char valueStr[20];
      sprintf(log_msg, "Measured Watthour on S0 port %d: %.2f", (i + 1),  Watthour ); log_message(log_msg);
      sprintf(valueStr, "%.2f", Watthour);
      sprintf(mqtt_topic, "%s/%s/Watthour/%d", mqtt_topic_base, mqtt_topic_s0, (i + 1)); mqtt_client.publish(mqtt_topic, valueStr, MQTT_RETAIN_VALUES);
      sprintf(log_msg, "Calculated Watt on S0 port %d: %u", (i + 1), actS0Data[i].watt); log_message(log_msg);
      sprintf(valueStr, "%u",  actS0Data[i].watt);
      sprintf(mqtt_topic, "%s/%s/Watt/%d", mqtt_topic_base, mqtt_topic_s0, (i + 1)); mqtt_client.publish(mqtt_topic, valueStr, MQTT_RETAIN_VALUES);
    }
  }
}

String s0TableOutput() {
  String output = "";
  for (int i = 0; i < NUM_S0_COUNTERS; i++) {
    output = output + "<tr>";
    output = output + "<td>" + (i + 1) + "</td>";
    output = output + "<td>" + actS0Data[i].watt + "</td>";
    output = output + "<td>" + (actS0Data[i].pulses * ( 1000.0 / actS0Settings[i].ppkwh)) + "</td>";
    output = output + "</tr>";
  }
  return output;
}

String s0JsonOutput() {
  String output = "[";
  for (int i = 0; i < NUM_S0_COUNTERS; i++) {
    output = output + "{";
    output = output + "\"S0 port\": \"" + (i + 1) + "\",";
    output = output + "\"Watt\": \"" + actS0Data[i].watt + "\",";
    output = output + "\"Watthour\": \"" + (actS0Data[i].pulses * ( 1000.0 / actS0Settings[i].ppkwh)) + "\"";
    output = output + "}";
    if (i < NUM_S0_COUNTERS - 1) output = output + ",";
  }
  output = output + "]";
  return output;
}
