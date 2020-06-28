#include <SoftwareSerial.h>;

int sensor_sample = 0;

short xBeeTx = 11;
short xBeeRx = 12;

SoftwareSerial xBeeSerial(xBeeRx, xBeeTx);

void setup() {
  Serial.begin(9600);
  xBeeSerial.begin(9600) ;

}

void loop() {
  sensor_sample = analogRead(A0);
  float voltage = sensor_sample * (5.0 / 1023.0);
  xBeeSerial.println(voltage);
  Serial.println(voltage);
}
