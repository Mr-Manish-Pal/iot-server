#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "Manish";
const char* password = "11111111";

WebServer server(80);

int irValue = 0;
int mqValue = 0;

unsigned long lastUpdate = 0;

// ================= DASHBOARD =================
void handleRoot()
{
  String page = "<!DOCTYPE html><html><head>";
  page += "<meta http-equiv='refresh' content='2'>";
  page += "<title>ESP32 Dashboard</title>";
  page += "<style>";
  page += "body{background:#111;color:white;font-family:Arial;text-align:center;padding-top:40px;}";
  page += ".box{width:350px;margin:auto;background:#222;padding:20px;border-radius:10px;}";
  page += ".value{font-size:32px;font-weight:bold;color:#00ff88;}";
  page += "</style></head><body>";

  page += "<div class='box'>";
  page += "<h1>ESP32 SENSOR SERVER</h1>";

  page += "<p>IR SENSOR</p>";
  page += "<div class='value'>" + String(irValue) + "</div>";

  page += "<br>";

  page += "<p>MQ135 VALUE</p>";
  page += "<div class='value'>" + String(mqValue) + "</div>";

  page += "<br>";

  page += "<p>LAST UPDATE</p>";
  page += "<div class='value'>" + String((millis() - lastUpdate) / 1000) + " sec</div>";

  page += "</div></body></html>";

  server.send(200, "text/html", page);
}

// ================= RECEIVE DATA =================
void handleUpdate()
{
  if (server.hasArg("ir"))
    irValue = server.arg("ir").toInt();

  if (server.hasArg("mq"))
    mqValue = server.arg("mq").toInt();

  lastUpdate = millis();

  Serial.print("IR = ");
  Serial.print(irValue);

  Serial.print(" | MQ135 = ");
  Serial.println(mqValue);

  server.send(200, "text/plain", "OK");
}

// ================= SETUP =================
void setup()
{
  Serial.begin(115200);
  delay(1000);

  Serial.println();
  Serial.println("================================");
  Serial.println("ESP32 SERVER STARTING");
  Serial.println("================================");

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  Serial.print("Connecting");

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("================================");
  Serial.println("WIFI CONNECTED");
  Serial.print("IP ADDRESS: ");
  Serial.println(WiFi.localIP());
  Serial.println("================================");

  server.on("/", handleRoot);
  server.on("/update", handleUpdate);

  server.begin();

  Serial.println("WEB SERVER STARTED");
  Serial.println("READY");
}

// ================= LOOP =================
void loop()
{
  server.handleClient();
}