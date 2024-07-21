//Written By C.J.Park On 230206 v 1.1
#include <Servo.h>
#include <DFPlayer_Mini_Mp3.h>
#include <SoftwareSerial.h>
SoftwareSerial mySerial(A4, A5);  // RX, TX

#define LED_WORK_RIGHT 2   // IR Right(A1) Workig LED
#define LED_WORK_CENTER 3  // IR Center(A2) Workig LED
#define LED_WORK_LEFT 4    // IR Left(A3) Workig LED
#define LED_EYE 5          // MonoEye Pink LED
#define LED_SHOT 6         // Bullet Shooting LED
#define LED_SIGHT 11       // Sight Aim LED

Servo SERVO_ARM;   //Down: 5; Aim: 45; Recoil:40
Servo SERVO_BASE;  //Right: 45; Center: 90; Left 135

void setup() {
  pinMode(LED_WORK_RIGHT, OUTPUT);
  pinMode(LED_WORK_CENTER, OUTPUT);
  pinMode(LED_WORK_LEFT, OUTPUT);
  pinMode(A1, INPUT);  //IR Sensor Right
  pinMode(A2, INPUT);  //IR Sensor Center
  pinMode(A3, INPUT);  //IR Sensor Left

  SERVO_ARM.attach(9);
  SERVO_BASE.attach(10);
  SERVO_ARM.write(5);
  SERVO_BASE.write(90);

  mySerial.begin(9600);
  mp3_set_serial(mySerial);
  mp3_set_volume(25);
}

void loop() {
  for (int i = 50; i <= 200; i++) {
    analogWrite(LED_EYE, i);
    delay(5);
  }
  for (int i = 200; i >= 50; i--) {
    analogWrite(LED_EYE, i);
    delay(5);
  }

  // Sensor Right-----------------------------------
  if (digitalRead(A1) == LOW) {
    digitalWrite(LED_WORK_RIGHT, HIGH);
    mp3_play(4);
    for (int i = 90; i >= 45; i--) {
      SERVO_BASE.write(i);
      delay(20);
    }
    mp3_stop();

    Machine_Gun();  //Machine Gun Shooting

    mp3_play(4);
    for (int i = 45; i <= 90; i++) {
      SERVO_BASE.write(i);
      delay(30);
    }
    mp3_stop();
    digitalWrite(LED_WORK_RIGHT, LOW);
  }

  // Sensor Center-----------------------------------
  if (digitalRead(A2) == LOW) {
    digitalWrite(LED_WORK_CENTER, HIGH);

    Machine_Gun();  //Machine Gun Shooting

    digitalWrite(LED_WORK_CENTER, LOW);
  }

  // Sensor Left-----------------------------------
  if (digitalRead(A3) == LOW) {
    digitalWrite(LED_WORK_LEFT, HIGH);
    mp3_play(4);
    for (int i = 90; i <= 145; i++) {
      SERVO_BASE.write(i);
      delay(10);
    }
    mp3_stop();

    Machine_Gun();  //Machine Gun Shooting

    mp3_play(4);
    for (int i = 145; i >= 90; i--) {
      SERVO_BASE.write(i);
      delay(30);
    }
    mp3_stop();
    digitalWrite(LED_WORK_LEFT, LOW);
  }
}

// *********Machine Gun Shooting*********
void Machine_Gun() {
  for (int i = 5; i <= 35; i++) {
    SERVO_ARM.write(i);
    delay(10);
  }

  for (int i = 0; i <= 255; i++) {
    analogWrite(LED_SIGHT, i);
    delay(5);
  }

  mp3_play(3);
  for (int i = 0; i < 20; i++) {
    analogWrite(LED_SHOT, 255);
    SERVO_ARM.write(38);
    delay(60);
    analogWrite(LED_SHOT, 0);
    SERVO_ARM.write(35);
    delay(60);
  }
  mp3_stop();

  for (int i = 150; i >= 0; i--) {
    analogWrite(LED_SHOT, i);
    delay(10);
  }
  delay(800);
  analogWrite(LED_SIGHT, 0);
  delay(800);

  for (int i = 35; i >= 5; i--) {
    SERVO_ARM.write(i);
    delay(30);
  }
}