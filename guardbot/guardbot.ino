#include "SR04.h"

//Buzzer
int buzzerPin = 3;

//Specifying pins for communicating with the sensor
int trig_pin = 12;
int echo_pin = 11;

//Get instance of an SR04 object representing the sensor
SR04 sensor = SR04(echo_pin, trig_pin);

//Variable for distance
long distance;

void setup() {
  // put your setup code here, to run once:
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
  delay(1000);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  distance=sensor.Distance();
  Serial.println(distance);

  //Beeps if closer than normal range
  if(distance < 40){
    digitalWrite(buzzerPin, HIGH);
    delay(500);
    digitalWrite(buzzerPin, LOW);
    delay(1);
  }
  delay(1);
  
}
