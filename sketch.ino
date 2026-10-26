#include <DHT.h>
#include <WiFi.h>
#include "ThingSpeak.h"
//Channel ID: 3551822
//API Key : 7WYZPFZTU139YDI5
#define DHTPIN 15
#define DHTTYPE DHT22

DHT sensorDHT(DHTPIN, DHTTYPE);

const char* WIFI_Name = "Wokwi-GUEST";
const char* WIFI_Pass = "";

unsigned long channelNumber = 3551822;
const char* apiKey = "7WYZPFZTU139YDI5";

const char* universityID = "12341143";

WiFiClient clientObject;

void setup() {
  Serial.begin(115200);

  sensorDHT.begin();

  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_Name, WIFI_Pass);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.println("Status: Not Connected");
    delay(1000);
  }

  Serial.println("Status: Connected");

  ThingSpeak.begin(clientObject);
}

void loop() {

  float temperature = sensorDHT.readTemperature();
  float humidity = sensorDHT.readHumidity();

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read DHT22!");
    delay(2000);
    return;
  }

  Serial.print("University ID: ");
  Serial.println(universityID);

  Serial.print("Temperature: ");
  Serial.println(temperature);

  Serial.print("Humidity: ");
  Serial.println(humidity);

  ThingSpeak.setField(1, temperature);
  ThingSpeak.setField(2, humidity);

  int stat = ThingSpeak.writeFields(channelNumber, apiKey);

  if (stat == 200) {
    Serial.println("Data Sent to ThingSpeak");
  } else {
    Serial.print("Error: ");
    Serial.println(stat);
  }

  delay(20000);
}
