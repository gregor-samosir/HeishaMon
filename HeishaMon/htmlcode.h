static const char webHeader[] PROGMEM  =
  "<!DOCTYPE html>"
  "<html>"
  "<title>Heisha monitor</title>"
  "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">"
  "<link rel=\"stylesheet\" href=\"https://www.w3schools.com/w3css/4/w3.css\">"
  "<link rel=\"stylesheet\" href=\"https://www.w3schools.com/w3css/4/w3pro.css\">"
  "<link rel=\"stylesheet\" href=\"https://www.w3schools.com/lib/w3-theme-red.css\">"
  "<link rel=\"stylesheet\" href=\"https://www.w3schools.com/w3css/4/w3.css\">"
  "<style>"
  "  .w3-btn { margin-bottom:10px; }"
  "</style>";

static const char refreshMeta[] PROGMEM = "<meta http-equiv=\"refresh\" content=\"5; url=/\" />";
static const char webBodyStart[] PROGMEM =
  "<body>"
  "<button class=\"w3-button w3-red w3-xlarge w3-left\" onclick=\"openLeftMenu()\">&#9776;</button>"
  "<header class=\"w3-container w3-card w3-theme\"><h1>Heisha monitor</h1></header>";

static const char webFooter[] PROGMEM  = "</body></html>";
static const char menuJS[] PROGMEM =
  "<script>"
  "  function openLeftMenu() {"
  "   var x = document.getElementById(\"leftMenu\");"
  "   if (x.style.display === \"none\") {"
  "     x.style.display = \"block\";"
  "   } else {"
  "     x.style.display = \"none\";"
  "   }"
  " }"
  "</script>";

static const char refreshJS[] PROGMEM =
  "<script src=\"https://ajax.googleapis.com/ajax/libs/jquery/3.4.1/jquery.min.js\"></script>"
  "<script>"
  " $(document).ready(function(){refreshTable();});"
  " function refreshTable(){"
  "   $('#heishavalues').load('/tablerefresh', function(){setTimeout(refreshTable, 30000);});"
  "   $('#dallasvalues').load('/tablerefresh?1wire', function(){});"
  "   $('#s0values').load('/tablerefresh?s0', function(){});"
  " }"
  "</script>";

static const char selectJS[] PROGMEM =
  "<script>"
  "function openTable(tableName) {"
  "  var i;"
  "  var x = document.getElementsByClassName(\"heishatable\");"
  "  for (i = 0; i < x.length; i++) {"
  "    x[i].style.display = \"none\";"
  "  }"
  "  document.getElementById(tableName).style.display = \"block\";"
  "}"
  "</script>";

static const char settingsJS[] PROGMEM =
  "<script type=\"text/javascript\">"
  "    function ShowHideDallasTable(dallasEnabled) {"
  "        var dallassettings = document.getElementById(\"dallassettings\");"
  "        dallassettings.style.display = dallasEnabled.checked ? \"table\" : \"none\";"
  "    }"
  "    function ShowHideS0Table(s0enabled) {"
  "        var s0settings = document.getElementById(\"s0settings\");"
  "        s0settings.style.display = s0enabled.checked ? \"table\" : \"none\";"
  "    }"
  "    function changeMinWatt(port) {"
  "        var ppkwh = document.getElementById('s0_ppkwh_'+port).value;"
  "        var interval = document.getElementById('s0_interval_'+port).value;"
  "        document.getElementById('s0_minwatt_'+port).innerHTML = Math.round((3600 * 1000 / ppkwh) / interval);"
  "    }"
  "</script>";

static const char webBodyRoot1[] PROGMEM =
  "<div class=\"w3-sidebar w3-bar-block w3-card w3-animate-left\" style=\"display:none\" id=\"leftMenu\">"
  "<a href=\"/reboot\" class=\"w3-bar-item w3-button\">Reboot</a>"
  "<a href=\"/firmware\" class=\"w3-bar-item w3-button\">Firmware</a>"
  "<a href=\"/settings\" class=\"w3-bar-item w3-button\">Settings</a>"
  "<a href=\"/togglelog\" class=\"w3-bar-item w3-button\">Toggle mqtt log</a>"
  "<a href=\"/togglehexdump\" class=\"w3-bar-item w3-button\">Toggle hexdump log</a>"
  "<hr><div class=\"w3-text-grey\">Version: ";

static const char webBodyRoot2[] PROGMEM =
  "<br><a href=\"https://github.com/Egyras/HeishaMon\">Heishamon software</a></div><hr></div>"
  "<div class=\"w3-bar w3-red\">"
  "<button class=\"w3-bar-item w3-button\" onclick=\"openTable('Heatpump')\">Heatpump</button>";

static const char webBodyRootDallasTab[] PROGMEM = "<button class=\"w3-bar-item w3-button\" onclick=\"openTable('Dallas')\">Dallas 1-wire</button>";
static const char webBodyRootS0Tab[] PROGMEM = "<button class=\"w3-bar-item w3-button\" onclick=\"openTable('S0')\">S0 kWh meters</button>";

static const char webBodyEndDiv[] PROGMEM = "</div>";

static const char webBodyRootStatusWifi[] PROGMEM =   "<div class=\"w3-container w3-left\"><br>Wifi signal: ";
static const char webBodyRootStatusMemory[] PROGMEM =   "%<br>Memory free: ";
static const char webBodyRootStatusReceived[] PROGMEM =  "%<br>Correct received data: ";
static const char webBodyRootStatusUptime[] PROGMEM =   "%<br>Uptime: ";

static const char webBodyRootHeatpumpValues[] PROGMEM =
  "<div id=\"Heatpump\" class=\"w3-container w3-center heishatable\">"
  "<h2>Current heatpump values</h2>"
  "<table class=\"w3-table-all\"><thead><tr class=\"w3-red\"><th>Topic</th><th>Name</th><th>Value</th><th>Description</th></tr></thead><tbody id=\"heishavalues\"><tr><td>...Loading...</td><td></td></r></tbody></table></div>";

static const char webBodyRootDallasValues[] PROGMEM =
  "<div id=\"Dallas\" class=\"w3-container w3-center heishatable\" style=\"display:none\">"
  "<h2>Current Dallas 1-wire values</h2>"
  "<table class=\"w3-table-all\"><thead><tr class=\"w3-red\"><th>Sensor</th><th>Temperature</th></tr></thead><tbody id=\"dallasvalues\"><tr><td>...Loading...</td><td></td></tr></tbody></table></div>";

static const char webBodyRootS0Values[] PROGMEM =
  "<div id=\"S0\" class=\"w3-container w3-center heishatable\" style=\"display:none\">"
  "<h2>Current S0 kWh meters values</h2>"
  "<table class=\"w3-table-all\"><thead><tr class=\"w3-red\"><th>S0 port</th><th>Watt</th><th>Watthour</th></tr></thead><tbody id=\"s0values\"><tr><td>...Loading...</td><td></td></tr></tbody></table></div>";


static const char webBodyFactoryResetWarning[] PROGMEM =
  "<div class=\"w3-container w3-center\">"
  "<p>Removing configuration. To reconfigure please connect to WiFi hotspot after reset.</p>"
  "</div>";

static const char webBodyRebootWarning[] PROGMEM =
  "<div class=\"w3-container w3-center\">"
  "<p>Rebooting</p>"
  "</div>";

static const char webBodySettingsResetPasswordWarning[] PROGMEM =
  "<div class=\"w3-container w3-center\">"
  "<h3>------- wrong current password -------</h3>"
  "<h3>-- do factory reset if password lost --</h3>"
  "</div>";

static const char webBodySettingsSaveMessage[] PROGMEM =
  "<div class=\"w3-container w3-center\">"
  "<h3>--- saved ---</h3>"
  "<h3>-- rebooting --</h3>"
  "</div>";

static const char webBodySettings1[] PROGMEM =
  "<div class=\"w3-sidebar w3-bar-block w3-card w3-animate-left\" style=\"display:none\" id=\"leftMenu\">"
  "<a href=\"/\" class=\"w3-bar-item w3-button\">Home</a>"
  "<a href=\"/reboot\" class=\"w3-bar-item w3-button\">Reboot</a>"
  "<a href=\"/firmware\" class=\"w3-bar-item w3-button\">Firmware</a>"
  "<a href=\"/togglelog\" class=\"w3-bar-item w3-button\">Toggle mqtt log</a>"
  "<a href=\"/togglehexdump\" class=\"w3-bar-item w3-button\">Toggle hexdump log</a>"
  "</div>";
