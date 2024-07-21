void setup() {
  pinMode(7, OUTPUT);  // Navi Lite Left RED LED
  pinMode(8, OUTPUT);  // Navi Lite Right BLUE LED
}

void loop() {
  int val = analogRead(A1) / 4;
  analogWrite(9, val);   // ENGINE Nozzle LED
  analogWrite(10, val);  // Cockpit FRONT LED
  analogWrite(11, val);  // Cockpit REAR LED

  digitalWrite(7, HIGH);  // Navi Lite Left RED LED
  digitalWrite(8, HIGH);  // Navi Lite Right BLUE LED
  delay(100);
  digitalWrite(7, LOW);  // Navi Lite Left RED LED
  digitalWrite(8, LOW);  // Navi Lite Right BLUE LED
  delay(600);
}