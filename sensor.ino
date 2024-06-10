#include <ArduinoJson.h>
#include <ArduinoJson.hpp>


#include <DHT.h>
#include <DHT_U.h>

#define DHTTYPE DHT11
const int sensor_pin = 2;
DHT dht(sensor_pin, DHTTYPE);

float temperature;
float humidity;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(sensor_pin,INPUT);
  dht.begin();
}

void loop() {
  //put your main code here, to run repeatedly:
  delay(2000);

  temperature = dht.readTemperature();
  humidity = dht.readHumidity();

  JsonDocument data_object;

  data_object["temp"] = temperature;
  data_object["humidity"] = humidity;
  serializeJson(data_object,Serial);
}
