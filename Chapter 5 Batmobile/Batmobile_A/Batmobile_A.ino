// Batmobile Code A
#define LED_R1 3   // PWM, Red LED1
#define LED_R2 5   // PWM, Red LED2
#define LED_R3 6   // PWM, Red LED3
#define LED_Y1 9   // PWM, Warm White LED1
#define LED_Y2 10  // PWM, Warm White LED2
#define LED_Y3 11  // PWM, Warm White LED3

#define LED_W1 7   // On Warm White LED1
#define LED_W2 8   // On Warm White LED2
#define LED_W3 12  // On Warm White LED3
#define LED_W4 4   // Car Head Light,  Blue Wire

int delayTime = 3; // Initial Time = 3,  Slow

void setup() {
  pinMode(LED_W1, OUTPUT);
  pinMode(LED_W2, OUTPUT);
  pinMode(LED_W3, OUTPUT);
  pinMode(LED_W4, OUTPUT);

  digitalWrite(LED_W1, HIGH);  // On Warm White LED1
  digitalWrite(LED_W2, HIGH);  // On Warm White LED2
  digitalWrite(LED_W3, HIGH);  // On Warm White LED3
  digitalWrite(LED_W4, HIGH);  // Car Head Light
}

void loop() {
  for(int i = 0; i <= 255; i++) { // LED R1 Fade In
    analogWrite(LED_R1, i);
    delay(delayTime);
  }
  for(int i = 255; i >= 0; i--) { // LED R1 Fade Out
    analogWrite(LED_R1, i);
    delay(delayTime);
  }

  for(int i = 0; i <= 255; i++) { // LED Y1 Fade In
    analogWrite(LED_Y1, i);
    delay(delayTime);
  }
  for(int i = 255; i >= 0; i--) { // LED Y1 Fade Out
    analogWrite(LED_Y1, i);
    delay(delayTime);
  }
  
  for(int i = 0; i <= 255; i++) { // LED R2 Fade In
    analogWrite(LED_R2, i);
    delay(delayTime);
  }
  for(int i = 255; i >= 0; i--) { // LED R2 Fade Out
    analogWrite(LED_R2, i);
    delay(delayTime);
  }
  
  for(int i = 0; i <= 255; i++) { // LED Y2 Fade In
    analogWrite(LED_Y2, i);
    delay(delayTime);
  }
  for(int i = 255; i >= 0; i--) { // LED Y2 Fade Out
    analogWrite(LED_Y2, i);
    delay(delayTime);
  }
  
  for(int i = 0; i <= 255; i++) { // LED R3 Fade In
    analogWrite(LED_R3, i);
    delay(delayTime);
  }
  for(int i = 255; i >= 0; i--) { // LED R3 Fade Out
    analogWrite(LED_R3, i);
    delay(delayTime);
  }
  
  for(int i = 0; i <= 255; i++) { // LED Y3 Fade In
    analogWrite(LED_Y3, i);
    delay(delayTime);
  }
  for(int i = 255; i >= 0; i--) { // LED Y3 Fade Out
    analogWrite(LED_Y3, i);
    delay(delayTime);
  }
}