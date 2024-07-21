//Written By C.J.Park On 230206 v 1.1
// *********Long Range Shooting*********
void Long_Shot (){
  for (int i = 5; i <= 35; i++) {
    S_Arm.write(i);
    delay(20);
  }
  delay(500);

  for (int i = 0; i <= 255; i++) {
    analogWrite(L_SIGHT, i);
    delay(7);
  }
  delay(500);

  mp3_play(1);

  analogWrite(L_SHOT, 255);
  for (int i = 50; i >= 35; i--) {
    S_Arm.write(i);
    delay(70);
  }

  for (int i = 255; i >= 0; i--) {
    analogWrite(L_SHOT, i);
    delay(5);
  }
  delay(1000);

  analogWrite(L_SIGHT, 0);
  delay(500);

  for (int i = 35; i >= 5; i--) {
    S_Arm.write(i);
    delay(30);
  } 
}



//Written By C.J.Park On 230206 v 1.1
// *********Burst Mode*********
void Burst (){
  for (int i = 5; i < 35; i++) {
    S_Arm.write(i);
    delay(8);
  }
  delay(300);

  analogWrite(L_SIGHT, 255);
  delay(500);

  for (int i = 0; i < 3; i++) {
    mp3_play(2);
    
    for (int j = 0; j < 3; j++) {
      analogWrite(L_SHOT, 255);
      S_Arm.write(38);
      delay(50);
      analogWrite(L_SHOT, 0);
      S_Arm.write(35);
      delay(50);
    }
    delay(500);
  }

  analogWrite(L_SIGHT, 0);
  delay(500);

  for (int i = 35; i >= 5; i--) {
    S_Arm.write(i);
    delay(30);
  }
}