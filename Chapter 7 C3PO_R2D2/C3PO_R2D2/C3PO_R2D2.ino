//Written By C.J.Park That's what friends are for v 1.0
#include <Servo.h>

#define R2_WHITE 3      //R2D2 Logic LED White
#define R2_SPARK 4      //R2D2 Spark LED Blue
#define R2_RED 5        //R2D2 PSI LED Red
#define R2_Blue 6       //R2D2 PSI LED Blue
#define MONITOR_BLUE 7  //Monitor LED Blue*2
#define C3_YELLOW 8     //C3PO Eye LED Yellow
#define ACTION 2        //Action Select Switch

Servo R2_HEAD;  //R2D2 Head Center:70, Right:100
Servo R2_BODY;  //R2D2 Body Front:70,Center85, Rear:100
Servo C3_BODY;  //C3PO Body Right:70, Left:100

void setup() {
  pinMode(ACTION, INPUT_PULLUP);
  pinMode(R2_SPARK, OUTPUT);
  pinMode(C3_YELLOW, OUTPUT);
  pinMode(MONITOR_BLUE, OUTPUT);

  R2_HEAD.attach(9);
  R2_BODY.attach(10);
  C3_BODY.attach(11);

  R2_HEAD.write(70);  // R2 Head Initial Position
  R2_BODY.write(70);  // R2 Body Initial Position
  C3_BODY.write(70);  // 3PO Initial Position

  analogWrite(R2_Blue, 80);
  digitalWrite(C3_YELLOW, HIGH);
}

void loop() {
  analogWrite(R2_WHITE, 150);
  delay(200);

  for (int i = 70; i <= 100; i++) {  //C3PO Body Left
    R2_HEAD.write(i);
    C3_BODY.write(i);
    delay(40);
  }
  delay(1000);

  analogWrite(R2_Blue, 0);
  analogWrite(R2_RED, 80);
  delay(1000);

  analogWrite(R2_WHITE, 50);
  delay(200);

  for (int i = 100; i >= 70; i--) {  // C3PO Body Right
    R2_HEAD.write(i);
    C3_BODY.write(i);
    delay(40);
  }
  delay(1000);

  analogWrite(R2_RED, 0);
  analogWrite(R2_Blue, 80);
  delay(1000);

  // Action Button Start ----------------------------------------------
  if (digitalRead(ACTION) == LOW) {
    digitalWrite(MONITOR_BLUE, HIGH);  // Monitor LED On
    delay(2000);

    for (int i = 70; i <= 100; i++) {  // R2 Up, Right
      R2_HEAD.write(i);
      R2_BODY.write(i);
      delay(60);
    }
    delay(1000);

    for (int i = 0; i < 5; i++) {  // R2 Saying
      analogWrite(R2_Blue, 0);
      analogWrite(R2_RED, 80);
      delay(200);
      analogWrite(R2_RED, 0);
      analogWrite(R2_Blue, 80);
      delay(300);
    }
    delay(500);

    for (int i = 100; i >= 70; i--) {
      R2_HEAD.write(i);
      R2_BODY.write(i);
      delay(60);
    }
    delay(1000);

    for (int i = 0; i < 15; i++) {  //R2 Strong Spark
      digitalWrite(R2_SPARK, HIGH);
      C3_BODY.write(90);
      delay(40);
      digitalWrite(R2_SPARK, LOW);
      C3_BODY.write(70);
      delay(80);
    }
    delay(500);

    digitalWrite(MONITOR_BLUE, LOW);  // Monitor LED Off
    delay(1000);
  }
}