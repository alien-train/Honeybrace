#include <ESP32Servo.h>

Servo myservo;

int kneePos = 20;
int pos = 85;
int servoPin = 18;
int flexPin = A2;
int flexValue;
int bendValue;

void setup() {
  ESP32PWM::allocateTimer(0);
  ESP32PWM::allocateTimer(1);
  ESP32PWM::allocateTimer(2);
  ESP32PWM::allocateTimer(3);

  myservo.setPeriodHertz(50);
  myservo.attach(servoPin, 500, 1950);

  Serial.begin(9600);
}

void loop() {
  flexValue = analogRead(flexPin);
  serial.println(flexPin);

  myservo.write(pos);
  kneePos = map(flexValue, 2000, 3200, 85, 0);
  Serial.println(kneePos);

  if (kneePos < 50){
    for (pos = 85; pos > 20; pos-=1){
      myservo.write(pos);
      delay(15);
    }
    delay(10);
    pos = 85;
    myservo.write(pos);
  }
}
