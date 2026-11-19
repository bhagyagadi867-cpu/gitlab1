#include <DHT.h>
#include <SoftwareSerial.h>

DHT d(2, DHT11);
SoftwareSerial esp(10, 11);

void setup() {
  Serial.begin(9600);
  esp.begin(9600);
  d.begin();
}

void loop() {
  float t = d.readTemperature();

  if (!isnan(t)) {
    Serial.print("Temperature: ");
    Serial.println(t);

    esp.println(t);
  }

  delay(2000);
}