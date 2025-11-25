#include <WiFi.h>
#include "secrets.h"
#include <WiFiClientSecure.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>
#include "DHTesp.h"
#include <time.h>

const int DHT_PIN = 15;
DHTesp dhtSensor;

#define AWS_IOT_PUBLISH_TOPIC   "iotfrontier/pub"
#define AWS_IOT_SUBSCRIBE_TOPIC "iotfrontier/sub"

String h;
String t;

void messageHandler(char* topic, byte* payload, unsigned int length);

WiFiClientSecure net;
PubSubClient client(net);

void connectAWS()
{
  Serial.println("Connecting to Wi-Fi");

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi Connected!");

  net.setCACert(AWS_CERT_CA);
  net.setCertificate(AWS_CERT_CRT);
  net.setPrivateKey(AWS_CERT_PRIVATE);

  client.setServer(AWS_IOT_ENDPOINT, 8883);
  client.setCallback(messageHandler);

  Serial.println("Connecting to AWS IOT");

  while (!client.connect(THINGNAME))
  {
    Serial.print(".");
    delay(200);
  }

  Serial.println("\nAWS IoT Connected!");

  client.subscribe(AWS_IOT_SUBSCRIBE_TOPIC);
}

void publishMessage()
{
  JsonDocument doc;
  doc["humidity"] = h;
  doc["temperature"] = t;

  char jsonBuffer[256];
  serializeJson(doc, jsonBuffer);

  client.publish(AWS_IOT_PUBLISH_TOPIC, jsonBuffer);
}

void messageHandler(char* topic, byte* payload, unsigned int length)
{
  Serial.print("incoming: ");
  Serial.println(topic);

  JsonDocument doc;
  deserializeJson(doc, payload, length);

  const char* message = doc["message"];
  Serial.println(message);
}

void setup() {
  Serial.begin(115200);

  Serial.print("Connecting to WiFi");
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  while (WiFi.status() != WL_CONNECTED) {
    delay(200);
    Serial.print(".");
  }
  Serial.println(" connected");
  configTime(-5 * 3600, 0, "pool.ntp.org");   // Perú UTC-5


  dhtSensor.setup(DHT_PIN, DHTesp::DHT22);

  connectAWS();
}

void loop() {
  if (!client.connected()) {
    connectAWS();
  }

  client.loop();
  
  time_t now = time(nullptr);
  

  TempAndHumidity data = dhtSensor.getTempAndHumidity();

  h = String(data.humidity, 1);
  t = String(data.temperature, 2);

  char* ts = ctime(&now);
  ts[strlen(ts)-1] = '\0';   // elimina el salto de línea al final

  Serial.println("----");
  Serial.print("Timestamp: ");
  Serial.println(ts);

  Serial.println("Temp: " + String(t) + "°C");
  Serial.println("Humidity: " + String(h) + "%");

  publishMessage();

  delay(5005);
}
