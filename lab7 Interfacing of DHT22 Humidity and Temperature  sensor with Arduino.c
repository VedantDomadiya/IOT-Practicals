#include <Wire.h>
#include "DHT.h"
#define DHTTYPE DHT22
uint8_t DHTPin = 5; //D1
DHT dht(DHTPin, DHTTYPE);
float Temperature;
float Humidity;

void setup() {
 Serial.begin(9600);
 pinMode(DHTPin, INPUT);
 dht.begin();
}

void loop(){
 Humidity = dht.readHumidity();
 Temperature = dht.readTemperature();
 float Temp_Fahrenheit = dht.readTemperature(true);
 if (isnan(Humidity) || isnan(Temperature) ) {
 Serial.println(F("Failed to read from DHT sensor!"));
 return;
 }
 Serial.print(F("Humidity: "));
 Serial.print(Humidity);
 Serial.println("%");
 Serial.print(F("Temperature: "));
 Serial.print(Temperature);
 Serial.println(F(" °C "));
 Serial.print(F("Temperature in Fahrenheit: "));
 Serial.print(Temp_Fahrenheit);
 Serial.println(F(" °F "));
 delay(5000);
}

