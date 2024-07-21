//Batmobile Code B V1.0 Written By C.J.Park 230709
int led_pin[6] = {3, 5, 6, 9, 10, 11};

#define LED_W1 7  // On Warm White LED1
#define LED_W2 8  // On Warm White LED2
#define LED_W3 12 // On Warm White LED1
#define LED_W4 4  // Car Head Light,  Blue Wire

int delayTime = 3; // Initial Time = 3,  Slow

void setup() {
  pinMode(LED_W1, OUTPUT);  // 
  pinMode(LED_W2, OUTPUT);  // 
  pinMode(LED_W3, OUTPUT);  // 
  pinMode(LED_W4, OUTPUT);  // 

  digitalWrite(LED_W1, HIGH);  // On Warm White LED1
  digitalWrite(LED_W2, HIGH);  // On Warm White LED2
  digitalWrite(LED_W3, HIGH);  // On Warm White LED3
  digitalWrite(LED_W4, HIGH);  // Car Head Light

  randomSeed(analogRead(A0));
}

void loop() {
  int chosen_led = random(6);

  for(int i = 0; i <= 255; i++) { // LED Fade In
    analogWrite(led_pin[chosen_led], i);
    delay(delayTime);
  }
  for(int i = 255; i >= 0; i--) { // LED Fade Out
    analogWrite(led_pin[chosen_led], i);
    delay(delayTime);
  }
}