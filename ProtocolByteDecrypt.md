## Protocol byte decrypt info:

|  Topic# | Byte# | Possible Value | Value decrypt | Value Description |
| :---- | ---- | ---- | ----- | ----:|
|   | 00 | 71 |   | Header  |
|   | 01 | c8 | Data length ( Packet length = Data length + 3 )  |  Header |
|   | 02 | 01|   | Header  |
|   | 03 | 10 |   | Header   |
|  TOP0+TOP2 | 04 | 56 | Force DHW status 56=off,96=on, 55 = heat pump off, 56= heat pump on, Service Setup: Water pump on=65, Air Purge=75, Pump Down=F0?| Force dhw, Heat pump on/off, Service setup (Water Flow, Air Purge , Pump Down) |
|  TOP19+TOP13+TOP68 | 05 | 55 | Holiday mode off/on (bit3and4), weekly shedule off/on (bit 1and2) force heater off/on (bit5and6) Dry Concrete off/on (bit7and8) | Holiday mode, Sheduler status, force heater state , Dry Concrete |
|  TOP4 | 06 | 62 | 52 Heat, 53 Cool, 59 Auto(Heat), 5A Auto(Cool), 61 DHW, 62 Heat+DHW, 63 Cool+DHW, 69 Auto(Heat)+DHW, 6A Auto(Cool)+DHW  | Mode status   |
|  TOP18+TOP17 | 07 | 49 | Left 5 bits = quiet level (0b01001 = Off, 0b01010 = level 1, 0b01011 = level 2, 0b01100 - level 3, 0b10001 = scheduled) last 3 bits is powermode level (0b001= Off, 0b010 - power mode 30min, 0b011 -60min, 0b100-90 min) | Quiet Mode status + Powerful mode status |
|  TOP | 08 | 00 |   | 0 byte |
|  TOP58+TOP59 | 09 | 05 | HEX values - should be Low Byte (2nd value)Water heater off + DHW heater off=55, Water heater on + DHWs heater off=56, Water Heater off + DHW heater on=59, Weater heater on + DHW heater on=5A | Heaters enable allowed status|
|  TOP | 10 | 00 |   | 0 byte |
|  TOP | 11 | 00 |   | 0 byte |
|  TOP | 12 | 00 |   | 0 byte |
|  TOP | 13 | 00 |   | 0 byte |
|  TOP | 14 | 00 |   | 0 byte |
|  TOP | 15 | 00 |   | 0 byte |
|  TOP | 16 | 00 |   | 0 byte |
|  TOP | 17 | 00 |   | 0 byte |
|  TOP | 18 | 00 |   | 0 byte |
|  TOP | 19 | 00 |   | 0 byte |
|  TOP | 20 | 19 | (hex) Water as medium Antifreezing off Optional PCB off=15, Antifreezing off Optional PCB on=16, Antifreezing on Optional PCB off=19, Antifreezing on Optional PCB on=1A, Glikol as medium High byte from 1 changes to 9, Antifreezing on Optional PCB off and External out temp on=29 (+10 for all values if External temp sensor selected) | Optional PCB, Anti freezing, Colling Medium,External outdoor temp sensor |
|  TOP | 21 | 15 |  (hex) 15 - 1 Zone and Z1 as room , 19 - 1 Zone and Z1 as pool, 16 - 2 Zones and Z2 as room, 26 - 2 Zones ,Z2 as pool| No. of Zones and Zone Destination |
|  TOP | 22 | 11 |First digit -Z2 ,Second digit Z1 (hex) 1 - water temperature,2 - External Thermostat, 3 - Internal Thermostat, , 4 - Thermistor  | Zone & sensor settings ( system setup - Installer ) | 
|  TOP | 23 | 55 | (hex) Off (same for compressor )=55, On=56, External compressor On=95  | External and External compressor Switch |
|  TOP | 24 | 16 | (hex) DHW connected (no solar) =16, DHW not connected=15, no buffer(DHW connected)=16, DHW+Buffer=1A, DHW as buffer for Solar=26, Buffer tank as Buffer for solar=36  | DHW Connection and Buffer + Solar status |
|  TOP | 25 | 5e | (hex) DHW Heater internal and 3kW=95, DHW Heater external and 3kW=96, DHW Heater internal and 6kW=99, DHW Heater external and 6kW=9A, DHW Heater internal and 9kW=9D, DHW Heater External and 9KW -9E, DHW Heater external and 9KW + Heater pad Type A on=AE, DHW Heater external and 9KW + Heater pad Type B on=BE  | Power of internal heater + DHW heater Internal/External + Heater for external pad |
|  TOP | 26 | 55 | (hex) Biwalent Off=55, Biwalent alternative =56, Biwalent parallel=5A | Biwalent settings |
|  TOP | 27 | 05 | SG Ready Control on/off (bit5and6) ,Demand Control on/off (bit7and8)  | SG Ready Control, Demand Control |
|  TOP76+TOP81 | 28 | 09 | (hex) 09 - Compensation curve heat and direct cool, 05 - both compensation curves , 0a - direct heat and direct cool, 06 - heat direct, cool compensation curve  | Operation Setup -Installer -water temperature heating on status and cooling |
|  TOP | 29 | 00 |   | 0 byte |
|  TOP | 30 | 00 |   | 0 byte |
|  TOP | 31 | 00 |   | 0 byte |
|  TOP | 32 | 00 |   | 0 byte |
|  TOP | 33 | 00 |   | 0 byte |
|  TOP | 34 | 00 |   | 0 byte |
|  TOP | 35 | 00 |   | 0 byte |
|  TOP | 36 | 00 |   | 0 byte |
|  TOP | 37 | 00 |   | 0 byte |
|  TOP27 | 38 | 80 | Convert to DEC 128-128 = 0  | Zone 1 water shift set or direct mode value Temperature For Heat Mode [°C] |
|  TOP28 | 39 | 8f | Convert to DEC 143-128 = 15 in direct mode set temp or shift value  | Zone 1 water shift set Temperature For Cool Mode [°C] |
|  TOP34 | 40 | 80 | Convert to DEC 128-128 = 0  | Zone 2 water shift or direct mode set Temperature For Heat Mode [°C] |
|  TOP35 | 41 | 8a | Convert to DEC 138-128 = 10  | Zone 2 water shift or direct mode set Temperature For Cool Mode [°C] |
|  TOP9 | 42 | b2 | Convert to DEC 178-128 = 50  | DHW Target Temperature [°C] |
|  TOP45 | 43 | 71 | Convert to DEC 113-128 =-15   | Heat Shift for Holiday mode [°K]  |
|  TOP25 | 44 | 71 | Convert to DEC 113-128 =-15  | Heat Shift for DHW mode [°K] |
|  TOP | 45 | 97 | (hex) 96 = 97  | Maximum set pump speed |
|  TOP | 46 | 99 | Convert to DEC 153-128 = 25  | Dry concrete target temperature for actual stage [°C] |
|  TOP | 47 | 00 |   | 0 byte |
|  TOP | 48 | 00 |   | 0 byte |
|  TOP | 49 | 00 |   | 0 byte |
|  TOP | 50 | 00 |   | 0 byte |
|  TOP | 51 | 00 |   | 0 byte |
|  TOP | 52 | 00 |   | 0 byte |
|  TOP | 53 | 00 |   | 0 byte |
|  TOP | 54 | 00 |   | 0 byte |
|  TOP | 55 | 00 |   | 0 byte |
|  TOP | 56 | 00 |   | 0 byte |
|  TOP | 57 | 00 |   | 0 byte |
|  TOP | 58 | 80 | Convert to DEC-128   | Delta T for Pool [°K] |
|  TOP | 59 | 85 | Convert to DEC-128  | Delta T for buffer tank [°K]|
|  TOP | 60 | 15 | Convert to DEC X-1   | Time set for external heaters 20min-3h, step 5min. |
|  TOP | 61 | 8a | Convert to DEC-128  | ? Possible Solar Connection Set delta T for tank ON (DHW or Buffer) |
|  TOP | 62 | 85 | Convert to DEC-128 | ? Possible Solar Connection Set delta T for tank OFF (DHW or Buffer)| 
|  TOP | 63 | 85 | Convert to DEC-128 | ? Possible Set Antifreeze for solar |
|  TOP | 64 | d0 | Convert to DEC-128 | ? Possible Set Hi limit for solar |
|  TOP | 65 | 7b | Convert to DEC-128  | Outdoor Temperature to turn on Bivalent device -15-35[°C]|
|  TOP | 66 | 78 | Convert to DEC-128  | ? Possible Control pattern in Bivalent set temperature source to start the bivalent heat source |
|  TOP | 67 | 1f | Convert to DEC X-1  | ?  Possible Bivalent Delay timer to start the bivalent heat source |
|  TOP | 68 | 7e | Convert to DEC-128  | ?  Possible Controll pattern in Bivalent set temperature source to stop the bivalent heat source |
|  TOP | 69 | 1f | Convert to DEC X-1  | ? Possible Bivalent Delay timer to stop the bivalent heat source |
|  TOP | 70 | 1f | Convert to DEC X-1  | ? Possible Bivalent Control pattern for DHW delay timer to start the bivalent source  |
|  TOP | 71 | 79 | Convert to DEC X-1  |SG Setting 1 Heating Capacity  |
|  TOP | 72 | 79 | Convert to DEC X-1  |SG Setting 1 DHW Capacity  |
|  TOP | 73 | 8d | Convert to DEC X-1  |SG Setting 2 Heating Capacity  |
|  TOP | 74 | 8d | Convert to DEC X-1  |SG Setting 2 DHW Capacity  |
|  TOP29 | 75 | 9e | Convert to DEC 158-128 =30 | Z1 Heating Curve Outlet Water Temperature Highest Set [°C] |
|  TOP30 | 76 | 96 | Convert to DEC 150-128 =22 | Z1 Heating Curve Outlet Water Temperature Lowest Set [°C] |
|  TOP32 | 77 | 71 | Convert to DEC 113-128 =-15 | Z1 Heating Curve Outside Temperature Lowest Set [°C] |
|  TOP31 | 78 | 8f | Convert to DEC 143-128 =15  | Z1 Heating Curve Outside Temperature Highest Set [°C] |
|  TOP82 | 79 | b7 | Convert to DEC 183-128 =55  | Z2 Heating Curve Outlet Water Temperature Highest Set [°C] |
|  TOP83 | 80 | a3 | Convert to DEC-128 | Z2 Heating Curve Outlet Water Temperature Lowest Set [°C] |
|  TOP84 | 81 | 7b | Convert to DEC-128 | Z2 Heating Curve Outside Temperature Lowest Set [°C] |
|  TOP85 | 82 | 8f | Convert to DEC-128 | Z2 Heating Curve Outside Temperature Highest Set [°C] |
|  TOP77 | 83 | 8e | Convert to DEC-128  | Outdoor Temperature to stop heating 5-35 [°C] |
|  TOP23 | 84 | 80 | Convert to DEC 133-128 =5 | Floor heating set Delta [°K] |
|  TOP78 | 85 | 80 | Convert to DEC 128-128=0 | Outdoor temperature for heater ON [°C]  |
|  TOP72 | 86 | 8f | Convert to DEC-128 | Z1 Cooling Curve Outlet Water Temperature Highest Set [°C]|
|  TOP73 | 87 | 8a | Convert to DEC-128 | Z1 Cooling Curve Outlet Water Temperature Lowest Set [°C]|
|  TOP74 | 88 | 94 | Convert to DEC-128 | Z1 Cooling Curve Outside Temperature Lowest Set [°C] |
|  TOP75 | 89 | 9e | Convert to DEC-128 | Z1 Cooling Curve Outside Temperature Highest Set [°C] |
|  TOP86 | 90 | 8a | Convert to DEC-128 | Z2 Cooling Curve Outlet Water Temperature Lowest Set [°C]|
|  TOP87 | 91 | 8a | Convert to DEC-128 | Z2 Cooling Curve Outlet Water Temperature Highest Set [°C]|
|  TOP88 | 92 | 94 | Convert to DEC-128 | Z2 Cooling Curve Outside Temperature Lowest Set [°C] |
|  TOP89 | 93 | 9e | Convert to DEC-128 | Z2 Cooling Curve Outside Temperature Highest Set [°C] |
|  TOP24 | 94 | 82 | Convert to DEC 130-128 =2  | Floor cooling set delta [°C] |
|  TOP79 | 95 |  90  | Convert to DEC 144-128=16|  Outdoor temperature for (heat to cool)   [°C]  |
|  TOP80 | 96 | 8b | Convert to DEC 139-128=11|  Outdoor temperature for (cool to heat) [°C] |
|  TOP | 97 | 05 | Donvert to DEC (X-1) x 30   | DHW settings - Room operation max time [min] |
|  TOP | 98 | 65 | Convert to DEC 101-1=100   | DHW heat up time (max) [min] |
|  TOP22 | 99 | 78 | Convert to DEC 120-128=-8 | DHW Delta for re-heat  [°K] |
|  TOP70 | 100 | c1 |  Convert to DEC 193-128=65  | Sterilization boiling temperature [°C] |
|  TOP71 | 101 | 0b |  Convert to DEC 11 - 1 = 10 | Sterilization max operation time [min] |
|  TOP | 102 | 00 |   | 0 byte |
|  TOP | 103 | 00 |   | 0 byte |
|  TOP | 104 | 00 |   | 0 byte |
|  TOP | 105 | 00 |   | 0 byte |
|  TOP | 106 | 00 |   | 0 byte |
|  TOP | 107 | 00 |   | 0 byte |
|  TOP | 108 | 00 |   | 0 byte |
|  TOP | 109 | 00 |   | 0 byte |
|  TOP | 110 | 55 |   | ? |
|  TOP20+TOP26 | 111 | 56 |  right 2 bits: 0b10=DHW 0b01=Room 3-Way Valve. Next 2 bits (from right) is defrosting state (0b01 = defrosting not active, 0b10 = defrosting active) | 3 way valve + Defrost status |
|  TOP60+TOP61 | 112 | 55 |  Hex 59 - external active, 55 - external and internal not active, 56 - internal active (room or DHW) | Heater status |
|  TOP44 | 113 | 21 | Hex B1 - F type error, A1 - H type error. After H error reset value 21, F error reset 31  | Error code type |
|  TOP44 | 114 | 53 | F45 error in HEX 56, calulation 45 treat as HEX and convert to DEC 69 + 17 = 86 (Hex 56) | Error code number |
|  TOP | 115 | 15 |   | ? |
|  TOP | 116 | 5a |   | ? |
|  TOP69 | 117 | 05 | No sterilization -05 , Sterilization active  -09  | Sterilization status |
|  TOP | 118 | 12 |   | ? |
|  TOP | 119 | 12 |   | ? |
|  TOP | 120 | 19 |   | ? |
|  TOP | 121 | 00 |   | 0 byte |
|  TOP | 122 | 00 |   | 0 byte |
|  TOP | 123 | 00 |   | 0 byte |
|  TOP | 124 | 00 |   | 0 byte |
|  TOP | 125 | 00 |   | 0 byte |
|  TOP | 126 | 00 |   | 0 byte |
|  TOP | 127 | 00 |   | 0 byte |
|  TOP | 128 | 00 |   | 0 byte |
|  TOP | 129 | e2 |   | ? |
|  TOP | 130 | ce |   | ? |
|  TOP | 131 | 0d |   | ? |
|  TOP92 | 132 | 71 |  look in HeatPumpType.md | Heat pump model |
|  TOP | 133 | 81 |   | ? |
|  TOP | 134 | 72 |   | ? |
|  TOP | 135 | ce |   | ? |
|  TOP | 136 | 0c |   | ? |
|  TOP | 137 | 92 |   | ? |
|  TOP | 138 | 81 |   | ? |
|  TOP56 | 139 | b0 |  Convert to DEC-128 | Zone1: Actual (Zone 1) Temperature [°C] |
|  TOP57 | 140 | 00 |  Convert to DEC-128 |  Zone2: Actual (Zone 2) Temperature [°C] |
|  TOP10 | 141 | aa |  Convert to DEC-128 | Actual DHW Temperature [°C] |
|  TOP14 | 142 | 7c |  Convert to DEC-128 | Actual Outdoor Temperature [°C] |
|  TOP5 | 143 | ab |  Convert to DEC-128 | Inlet Water Temperature [°C] |
|  TOP6 | 144 | b0 |  Convert to DEC-128 | Outlet Water Temperature [°C] |
|  TOP36 | 145 | 32 |  Convert to DEC-128 | Zone1: Water Temperature [°C] |
|  TOP37 | 146 | 32 |  Convert to DEC-128 | Zone2: Water Temperature [°C] |
|  TOP42 | 147 | 9c |  Convert to DEC-128 | Zone1: Water Temperature (Target) [°C] |
|  TOP43 | 148 | b6 |  Convert to DEC-128 | Zone2: Water Temperature (Target) [°C]  |
|  TOP46 | 149 | 32 |  Convert to DEC-128 | Buffer: Water Temperature [°C] |
|  TOP47 | 150 | 32 |  Convert to DEC-128 | Solar: Water Temperature [°C]  |
|  TOP48 | 151 | 32 |  Convert to DEC-128| Pool: Water Temperature [°C] |
|  TOP | 152 | 80 | Convert to DEC 128-128 = 0  | Water shift set or direct mode value Temperature For Heat Mode [°C] including Delta T for Buffer |
|  TOP7 | 153 | b7 |  Convert to DEC-128 | Outlet Water Temperature (Target) [°C] |
|  TOP49 | 154 | af |  Convert to DEC-128 | Outlet 2 heat exchanger water temperature [°C] |
|  TOP50 | 155 | cd |  Convert to DEC-128 | Discharge Temperature [°C] |
|  TOP33 | 156 | 9a |  Convert to DEC-128 | Room Thermostat Internal Sensor Temperature [°C] |
|  TOP51 | 157 | ac |  Convert to DEC-128 | Indoor Piping Temperature [°C] |
|  TOP21 | 158 | 79 |  Convert to DEC-128 | Outdoor Piping Temperature [°C] |
|  TOP52 | 159 | 80 |  Convert to DEC-128 | Defrost Temperature [°C] |
|  TOP53 | 160 | 77 |  Convert to DEC-128 | Eva Outlet Temperature [°C] |
|  TOP54 | 161 | 80 |  Convert to DEC-128 | Bypass Outlet Temperature [°C] |
|  TOP55 | 162 | ff |  Convert to DEC-128 | Ipm Temperature [°C]  |
|  TOP64 | 163 | 91 |  Convert to DEC (x-1)/5 |  High Pressure [Kgf/Cm2] |
|  TOP66 | 164 | 01 |  Convert to DEC x-1 | Low Pressure [Kgf/Cm2] |
|  TOP67 | 165 | 29 |  Convertto DEC (X-1)/5 | Outdoor Current [A] |
|  TOP8 | 166 | 59 | Convert to DEC x-1  | Compressor Frequency [Hz] |
|  TOP | 167 | 00 |   | 0 byte |
|  TOP | 168 | 00 |   | 0 byte |
|  TOP1 | 169 | 3b | Convert to DEC (X -1)/256 | 2nd Value for Pump Flow Rate [L/Min]  |
|  TOP1 | 170 | 0b | Convert to DEC | 1st Value for Pump Flow Rate [L/Min] |
|  TOP65 | 171 | 1c | Convert to DEC (X-1) X 50 | Pump Speed [R/Min] |
|  TOP93 | 172 | 51 | Convert to DEC X-1   | Pump Duty [Duty] |
|  TOP62 | 173 | 59 | Convert to DEC (X-1) X10  | Fan 1 Motor Speed [R/Min |
|  TOP63 | 174 | 01 | Convert to DEC (X-1) X10  | Fan 2 Motor Speed [R/Min] |
|  TOP | 175 | 36 |   | ? |
|  TOP | 176 | 79 |   | ? |
|  TOP | 177 | 01 | Convert to DEC -1  | ? Posible Time for Mixing vave 1 Zone2 [seconds]|
|  TOP | 178 | 01 | Convert to DEC -1  | ? Posible Time for Mixing vave 2 Zone2 [seconds] |
|  TOP12 | 179 | c3 | combine both bytes (180 byte) 08 (179 byte) be = 08be= 2238(DEC) - 1 = 2237  | number of operations |
|  TOP12 | 180 | 02 |  look at 179 | number of operations |
|  TOP | 181 | 00 |   | 0 byte |
|  TOP11 | 182 | dd | combine both bytes (183) 0b  (182) 25 = 2853 - 1 = 2852  | Operating time in h |
|  TOP11 | 183 | 02 | look at 182  | Operating time in h |
|  TOP | 184 | 00 |   | 0 byte |
|  TOP90 | 185 | 05 | combine both bytes (186) 00  (185) 0005 = 5 - 1 = 4  | Room Heater operation time in h |
|  TOP90 | 186 | 00 |  look at 185   | Room Heater operation time in h |
|  TOP | 187 | 00 |   | 0 byte |
|  TOP91 | 188 | 01 | combine both bytes (189) 00  (188) 0001 = 1 - 1 = 0   | DHW Heater operation time in h  |
|  TOP91 | 189 | 00 | look at 188 | DHW Heater operation time in h |
|  TOP | 190 | 00 |   | 0 byte |
|  TOP | 191 | 06 | Convert to DEC X-1  | ? Possible heat pump power in Kw |
|  TOP | 192 | 01 | (hex) simple model=1, T-CAP=2  | ? Possible Heat pump indicator for T-CAP  |
|  TOP16 | 193 | 01 | Convert to DEC (x-1) / 5   | Energy Consumption for Heat in [kw]  |
|  TOP15 | 194 | 01 | Convert to DEC (x-1) / 5   | Energy Generation for Heat in [kw] |
|  TOP38 | 195 | 01 | Convert to DEC (x-1) / 5   | Energy Consumption for Cool in [kw] |
|  TOP39 | 196 | 01 | Convert to DEC (x-1) / 5   | Energy Generation for Cool in [kw] |
|  TOP40 | 197 | 0a | Convert to DEC (x-1) / 5   | Energy Consumption for DHW in [kw] |
|  TOP41 | 198 | 14 | Convert to DEC (x-1) / 5   | Energy Generation for DHW in [kw] |
|  TOP | 199 | 00 |   | byte 0 |
|  TOP | 200 | 00 |   | byte 0 |
|  TOP | 201 | 00 |   | byte 0 |
|  TOP | 202 | 79 |  CHECKSUM |  |




To get decimal values you must convert from hexadecimal and do some calulation depending on value. Most of them need just -128(DEC). \
As example 43 byte value to get DHW set temperature b1 (HEX) = 177(DEC) - 128 = 49 C  \
Panasonic query, answer and commands are using 8-bit Checksum to verify serial data ( sum(all bytes) & 0xFF == 0 ). Last byte is checksum value.


## Query Examples:

Panasonic query:

`71 6c 01 10 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 12`

Panasonic answer example:

`71 c8 01 10 56 55 62 49 00 05 00 00 00 00 00 00
00 00 00 00 19 15 11 55 16 5e 55 05 09 00 00 00
00 00 00 00 00 00 80 8f 80 8a b2 71 71 97 99 00
00 00 00 00 00 00 00 00 00 00 80 85 15 8a 85 85
d0 7b 78 1f 7e 1f 1f 79 79 8d 8d 9e 96 71 8f b7
a3 7b 8f 8e 85 80 8f 8a 94 9e 8a 8a 94 9e 82 90
8b 05 65 78 c1 0b 00 00 00 00 00 00 00 00 55 56
55 21 53 15 5a 05 12 12 19 00 00 00 00 00 00 00
00 e2 ce 0d 71 81 72 ce 0c 92 81 b0 00 aa 7c ab
b0 32 32 9c b6 32 32 32 80 b7 af cd 9a ac 79 80
77 80 ff 91 01 29 59 00 00 3b 0b 1c 51 59 01 36
79 01 01 c3 02 00 dd 02 00 05 00 00 01 00 00 06
01 01 01 01 01 0a 14 00 00 00 77`

Quiet mode 1

`f1 6c 01 10 00 00 00 10 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 82`

Quiet mode 2

`f1 6c 01 10 00 00 00 18 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 7a`

Quiet mode 3

`f1 6c 01 10 00 00 00 20 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 72`

Quiet off

`f1 6c 01 10 00 00 00 08 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 8a`

Set -2C

`f1 6c 01 10 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 7e 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 14`

set -1C

`f1 6c 01 10 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 7f 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 13`

Set 0C

`f1 6c 01 10 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 80 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 12`

set -3C

`f1 6c 01 10 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 7d 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 15`

set -4C

`f1 6c 01 10 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 7c 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 16`

Set -5C

`f1 6c 01 10 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 7b 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 17`

set +1C

`f1 6c 01 10 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 81 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 11`

set +2C

`f1 6c 01 10 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 82 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 10`

set +3C

`f1 6c 01 10 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 83 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 0f`

set +4C

`f1 6c 01 10 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 84 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 0e`

set +5C

`f1 6c 01 10 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 85 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 0d`

set DHW to 48C

`f1 6c 01 10 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 b0 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 e2`

set DHW to 47C

`f1 6c 01 10 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 af 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 e3`

set DHW to 49C

`f1 6c 01 10 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 b1 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 e1`

set DHW to 40C

`f1 6c 01 10 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 a8 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 ea`

set DHW to max 75C

`f1 6c 01 10 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 ca 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 c8`

heat on - DHW off

`f1 6c 01 10 02 00 52 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 3e`

heat off - DHW off (all off command)

`f1 6c 01 10 01 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 91`

heat off - DHW on

`f1 6c 01 10 02 00 21 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 6f`

heat on - DHW on

`f1 6c 01 10 02 00 62 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 2e`

set cool to 19C

`f1 6c 01 10 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 93 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 ff`

set cool to 18C

`f1 6c 01 10 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 92 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00`

set cool to 6C 

`f1 6c 01 10 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 86 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 0c`


cool mode

`f1 6c 01 10 00 00 03 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 8f`


auto mode

`f1 6c 01 10 00 00 08 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 8a`


heat mode

`f1 6c 01 10 00 00 02 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 90`

From service cloud commands:

DHW mode only

`f1 6c 01 10 42 54 21 49 00 05 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 80 94 00 00 b1 71 71 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 e6`


heat only

`f1 6c 01 10 42 54 12 49 00 05 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 80 94 00 00 b1 71 71 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 f5`



cool only

`f1 6c 01 10 42 54 13 49 00 05 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 80 94 00 00 b1 71 71 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 f4`

auto

`f1 6c 01 10 42 54 18 49 00 05 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 80 94 00 00 b1 71 71 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 ef`

heat + dhw

`f1 6c 01 10 42 54 22 49 00 05 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 80 94 00 00 b1 71 71 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 e5`


cool + dhw

`f1 6c 01 10 42 54 23 49 00 05 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 80 94 00 00 b1 71 71 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 e4`


auto + dhw


`f1 6c 01 10 42 54 28 49 00 05 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 80 94 00 00 b1 71 71 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 df`


holiday mode ON

`f1 6c 01 10 42 64 22 49 00 05 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 80 94 00 00 b1 71 71 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 d5`


holiday mode OFF

`f1 6c 01 10 42 54 22 49 00 05 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 80 94 00 00 b1 71 71 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 e5`


powerful 30 min

`f1 6c 01 10 42 54 22 4a 00 05 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 80 94 00 00 b1 71 71 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 e4`


powerful 60 min

`f1 6c 01 10 42 54 22 4b 00 05 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 80 94 00 00 b1 71 71 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 e3`



powerful 90 min


`f1 6c 01 10 42 54 22 4c 00 05 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 80 94 00 00 b1 71 71 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 e2`


powerful off


`f1 6c 01 10 42 54 22 49 00 05 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 80 94 00 00 b1 71 71 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 e5`



force DHW on

`f1 6c 01 10 82 54 21 49 00 05 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 80 94 00 00 b1 71 71 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 a6`


Force DHW OFF

`f1 6c 01 10 42 54 21 49 00 05 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 80 94 00 00 b1 71 71 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 e6`

Heat pump Power ON

`f1 6c 01 10 42 54 12 49 00 05 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 94 9c 00 00 b1 80 80 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 bb`

Heat pump Power OFF

`f1 6c 01 10 41 54 22 49 00 05 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 80 8a 00 00 b1 80 80 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 d2`

Command sequence to set Zone & Sensor

Set Internal Thermostat

`f1 6c 01 10 01 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 91`

`f1 6c 01 10 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 19 05 03 55 16 12 55 05 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 15 8a 85 85
d0 7b 78 1f 7e 1f 1f 79 79 8d 8d 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 47`


`f1 6c 01 10 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 19 05 03 55 16 12 55 05 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 15 8a 85 85
d0 7b 78 1f 7e 1f 1f 79 79 8d 8d 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 47`

`f1 6c 01 10 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 92`


Set Water Temperature

sends off command  (same pattern with other setting commands)

`f1 6c 01 10 01 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 91`

sets value

`f1 6c 01 10 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 19 05 01 55 16 12 55 05 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 15 8a 85 85
d0 7b 78 1f 7e 1f 1f 79 79 8d 8d 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 49`

this should be confirmation (same pattern with other setting commands)

`f1 6c 01 10 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 92`


Room Sensor External

`f1 6c 01 10 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 19 05 02 55 16 12 55 05 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 15 8a 85 85
d0 7b 78 1f 7e 1f 1f 79 79 8d 8d 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 48`

Room Sensor Thermistor

`f1 6c 01 10 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 19 05 04 55 16 12 55 05 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 15 8a 85 85
d0 7b 78 1f 7e 1f 1f 79 79 8d 8d 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 46`

Operation Setup --> Installer

Water temperature for heating on Compensationio Curve

`f1 6c 01 10 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 09 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 9e 96 71 8f 00
00 00 00 89 85 80 8a 8a 94 9e 8a 00 00 00 82 94
8b 05 65 78 c1 0b 00 00 00 00 00 00 00 00 a8`
 

Heat Direct

`f1 6c 01 10 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 0a 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 9e 96 71 8f b7
00 00 00 89 85 80 8a 8a 94 9e 8a 00 00 00 82 94
8b 05 65 78 c1 0b 00 00 00 00 00 00 00 00 f0`



Water temperature for Cooling on Compensation curve set

`f1 6c 01 10 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 05 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 9e 96 71 8f 00
00 00 00 89 85 80 8a 8a 94 9e 00 00 00 00 82 94
8b 05 65 78 c1 0b 00 00 00 00 00 00 00 00 36`

Cool Direct

`f1 6c 01 10 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 09 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 9e 96 71 8f 00
00 00 00 89 85 80 8a 8a 94 9e 8f 00 00 00 82 94
8b 05 65 78 c1 0b 00 00 00 00 00 00 00 00 a3`

set Delta T for heating 6c

`f1 6c 01 10 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 09 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 9e 96 71 8f 00
00 00 00 89 86 80 8a 8a 94 9e 8f 00 00 00 82 94
8b 05 65 78 c1 0b 00 00 00 00 00 00 00 00 a2`

outdoor temperature for heating off 10C

`f1 6c 01 10 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 09 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 9e 96 71 8f 00
00 00 00 8a 85 80 8a 8a 94 9e 8f 00 00 00 82 94
8b 05 65 78 c1 0b 00 00 00 00 00 00 00 00 a2`


delta T for cooling 3C

`f1 6c 01 10 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 09 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 9e 96 71 8f 00
00 00 00 8a 85 80 8a 8a 94 9e 8f 00 00 00 83 94
8b 05 65 78 c1 0b 00 00 00 00 00 00 00 00 a1`


cool zone1 temperature set dircet 20C

`f1 6c 01 10 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 09 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 9e 96 71 8f 00
00 00 00 8a 85 80 94 8a 94 9e 8f 00 00 00 83 94
8b 05 65 78 c1 0b 00 00 00 00 00 00 00 00 97`

Auto mode
Outdoor temperature mode for (heat to cool) 21C

`f1 6c 01 10 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 09 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 9e 96 71 8f 00
00 00 00 8a 85 80 8a 8a 94 9e 8f 00 00 00 83 95
8b 05 65 78 c1 0b 00 00 00 00 00 00 00 00 a0`


for cool to heat set 12C

`f1 6c 01 10 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 09 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 9e 96 71 8f 00
00 00 00 8a 85 80 8a 8a 94 9e 8f 00 00 00 83 95
8c 05 65 78 c1 0b 00 00 00 00 00 00 00 00 9f`

DHW settings

Room Operation time maximum 90 min

`f1 6c 01 10 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 09 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 9e 96 71 8f 00
00 00 00 8a 85 80 8a 8a 94 9e 8f 00 00 00 83 95
8c 04 65 78 c1 0b 00 00 00 00 00 00 00 00 a0`

DHW heat up DHW maximum 105 min

`f1 6c 01 10 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 09 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 9e 96 71 8f 00
00 00 00 8a 85 80 8a 8a 94 9e 8f 00 00 00 83 95
8c 05 6a 78 c1 0b 00 00 00 00 00 00 00 00 9a`

sterilization boiling temp set 66C

`f1 6c 01 10 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 09 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 9e 96 71 8f 00
00 00 00 8a 85 80 8a 8a 94 9e 8f 00 00 00 83 95
8c 05 6a 78 c2 0b 00 00 00 00 00 00 00 00 99`

set sterilization time 15 min

`f1 6c 01 10 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 09 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 9e 96 71 8f 00
00 00 00 8a 85 80 8a 8a 94 9e 8f 00 00 00 83 95
8c 05 6a 78 b7 10 00 00 00 00 00 00 00 00 9f`

better to use these instead from user cloud

quiet off


`f1 6c 01 10 42 54 22 49 00 05 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 80 94 00 00 b1 71 71 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 e5`


quiet 1


`f1 6c 01 10 42 54 22 51 00 05 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 80 94 00 00 b1 71 71 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 dd`


quiet 2

`f1 6c 01 10 42 54 22 59 00 05 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 80 94 00 00 b1 71 71 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 d5`



quiet 3

`f1 6c 01 10 42 54 22 61 00 05 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 80 94 00 00 b1 71 71 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 cd`

Force defrost request

`f1 6c 01 10 42 54 22 49 02 05 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 80 94 00 00 b1 71 71 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 e3`

Sterilization request

`f1 6c 01 10 42 54 22 49 04 05 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 80 94 00 00 b1 71 71 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 e1`

Weekly timer on (byte 5 changes)

`f1 6c 01 10 42 94 22 49 00 05 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 7b 94 00 00 b1 71 71 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 aa`

Weekly timer off (byte 5 changes)

`f1 6c 01 10 42 54 22 49 00 05 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 7b 94 00 00 b1 71 71 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 ea`

Quiet timer on (byte 7 changes)

`f1 6c 01 10 42 94 22 89 00 05 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 7b 94 00 00 b1 71 71 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 6a`


Quiet timer off (byte 7 changes)

`f1 6c 01 10 42 54 22 49 00 05 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 7b 94 00 00 b1 71 71 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 ea`

DHW heater on (byte 9 changes)

`f1 6c 01 10 42 54 22 49 00 09 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 7b 94 00 00 b1 71 71 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 e6`

DHW heater off (byte 9 changes)

`f1 6c 01 10 42 54 22 49 00 05 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 7b 94 00 00 b1 71 71 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 ea`

Error reset (reboot)

`f1 6c 01 10 00 00 00 00 01 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 91
`
