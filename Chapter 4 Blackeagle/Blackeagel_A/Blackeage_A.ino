void setup() {
  pinMode(7, OUTPUT);  // Navi Lite Left RED LED
  pinMode(8, OUTPUT);  // Navi Lite Right BLUE LED

  analogWrite(10, 150);  // Cockpit FRONT LED Set 0~255
  delay(1000);
  analogWrite(11, 150);  // Cockpit REAR LED Set 0~255
  delay(1000);

  digitalWrite(7, HIGH);  // Navi Lite Left RED LED
  digitalWrite(8, HIGH);  // Navi Lite Right BLUE LED
}

void loop() {
  int val = analogRead(A1) / 4;
  analogWrite(9, val);  // ENGINE Nozzle LED
}