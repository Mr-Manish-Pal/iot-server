#include <WiFi.h>
#include <HTTPClient.h>

#define IR_PIN 18
#define MQ_PIN 32

const char* ssid = "Manish";
const char* password = "11111111";

// ESP32 #2 Server IP
const char* serverIP = "10.193.65.33";

unsigned long previousMillis = 0;
const long interval = 1000;

void setup()
{
  Serial.begin(115200);

  pinMode(IR_PIN, INPUT);

  Serial.println();
  Serial.println("ESP32 SENSOR NODE");

  WiFi.begin(ssid, password);

  Serial.print("Connecting");

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("WiFi Connected");
  Serial.print("My IP: ");
  Serial.println(WiFi.localIP());
}

void loop()
{
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval)
  {
    previousMillis = currentMillis;

    int irValue = digitalRead(IR_PIN);
    int mqValue = analogRead(MQ_PIN);

    Serial.print("IR: ");
    Serial.print(irValue);

    Serial.print("   MQ135: ");
    Serial.println(mqValue);

    if (WiFi.status() == WL_CONNECTED)
    {
      HTTPClient http;

      String url =
      "http://" +
      String(serverIP) +
      "/update?ir=" +
      String(irValue) +
      "&mq=" +
      String(mqValue);

      http.begin(url);

      int httpCode = http.GET();

      Serial.print("HTTP Response: ");
      Serial.println(httpCode);

      http.end();
    }
  }
}