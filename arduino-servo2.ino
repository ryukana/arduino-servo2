#include <Servo.h>
Servo servo1;        //Servo1オブジェクトを作成
Servo servo2;        //Servo2オブジェクトを作成

char inByte = 0;
int nowAction = 0;

void setup() {
  servo1.attach(9);  //D9ピンをサーボ1の信号線として設定
  servo2.attach(8);  //D8ピンをサーボ2の信号線として設定
  // initialize serial communication at 115200 bits per second:
  Serial.begin(115200);
}
void loop() {
  // if we get a valid byte, read analog ins:
  if (Serial.available() > 0) {
    // get incoming byte:
    inByte = Serial.read();
    if (inByte == '0') {
      nowAction = 9;
    } else if (inByte == '1') {
      nowAction = 1;
    } else if (inByte == '2') {
      nowAction = 2;
    } else if (inByte == '3') {
      nowAction = 3;
    } else if (inByte == '4') {
      nowAction = 4;
    } else if (inByte == '5') {
      nowAction = 5;
    } else if (inByte == '6') {
      nowAction = 6;
    } else if (inByte == '9') {
      nowAction = 0;
    } else {
      nowAction - 1;
    }
    delay(100);
  }
  delay(1);        // delay in between reads for stability

  if (nowAction == 0) {
    servo1.write(0); // サーボ1の角度を0°に設定
  } else if (nowAction == 1) {
    servo2.write(73); // サーボ2の角度を0°に設定
  } else if (nowAction == 2) {
    servo2.write(9);//7);//8); // サーボ2の角度を60°に設定
  } else if (nowAction == 3) {
    servo2.write(21);//20);//19); // サーボ2の角度を120°に設定
  } else if (nowAction == 4) {
    servo2.write(33);//32); // サーボ2の角度を180°に設定
  } else if (nowAction == 5) {
    servo2.write(45);//49); // サーボ2の角度を240°に設定
  } else if (nowAction == 6) {
    servo2.write(58);//59); // サーボ2の角度を300°に設定
  } else if (nowAction == 9) {
    servo1.write(90); // サーボ1の角度を90°に設定
  } else {
    // do nothing
  }
}
