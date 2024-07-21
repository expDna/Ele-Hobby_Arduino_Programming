// Written By C.J.Park EVEE v 1.0 230111
#include <Servo.h>
#define TOUCH 2
#define MIC A1

Servo ServoEars;  //Down: 90; Up: 140;
Servo ServoLeg;   //Down: 40; Up: 120;
Servo ServoTail;  //Left: 60; Right: 120;

void setup() {
  pinMode(MIC, INPUT);
  pinMode(TOUCH, INPUT);
  ServoEars.attach(9);
  ServoLeg.attach(10);
  ServoTail.attach(11);

  ServoEars.write(90);
  ServoLeg.write(40);
  ServoTail.write(120);
}

void loop() {
  if (digitalRead(MIC) == HIGH) {
    delay(500);

    //Tail
    for (int i = 120; i >= 60; i--) {
      ServoTail.write(i);
      delay(2);
    }
    for (int i = 60; i <= 120; i++) {
      ServoTail.write(i);
      delay(2);
    }

    for (int i = 120; i >= 60; i--) {
      ServoTail.write(i);
      delay(2);
    }
    for (int i = 60; i <= 120; i++) {
      ServoTail.write(i);
      delay(2);
    }

    for (int i = 120; i >= 60; i--) {
      ServoTail.write(i);
      delay(2);
    }
    for (int i = 60; i <= 120; i++) {
      ServoTail.write(i);
      delay(2);
    }

    //Foreleg Up
    for (int i = 40; i <= 120; i++) {
      ServoLeg.write(i);
      delay(15);
    }

    //Waiting For TOUCH
    while (digitalRead(TOUCH) == LOW) {
    }

    //Ear moving
    for (int i = 90; i <= 140; i++) {
      ServoEars.write(i);
      delay(3);
    }
    for (int i = 140; i >= 90; i--) {
      ServoEars.write(i);
      delay(3);
    }

    for (int i = 90; i <= 140; i++) {
      ServoEars.write(i);
      delay(3);
    }
    for (int i = 140; i >= 90; i--) {
      ServoEars.write(i);
      delay(3);
    }

    for (int i = 90; i <= 140; i++) {
      ServoEars.write(i);
      delay(3);
    }
    for (int i = 140; i >= 90; i--) {
      ServoEars.write(i);
      delay(3);
    }

    //Foreleg Down
    delay(600);
    for (int i = 120; i > 40; i--) {
      ServoLeg.write(i);
      delay(10);
    }
  }
}