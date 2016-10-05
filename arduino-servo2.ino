#include <Servo.h> 
Servo servo;        //Servoオブジェクトを作成
int BTReset = 3;
int LED = 13;

char inByte = 0;
int nowAction = 0;

boolean isServoPosiInit = false;
void setup() {
  servo.attach(9);  //D9ピンをサーボの信号線として設定
  // make the Bluetooth Module reset:
  digitalWrite(BTReset, LOW);
  delay(100);
  digitalWrite(BTReset, HIGH);
  delay(500);
   
  // initialize serial communication at 115200 bits per second:
  Serial.begin(115200);

  pinMode(LED, OUTPUT);  // make a LED pin output
}

void loop() {
  // if we get a valid byte, read analog ins:
  if (Serial.available() > 0) {
    // get incoming byte:
    inByte = Serial.read();
    if (inByte == '0') {
      nowAction = 0;
    } else if (inByte == '5') {
      nowAction = 5;
    } else {
      nowAction = 9;
    }
    Serial.println(inByte); 
    delay(100);
  }
  delay(1);        // delay in between reads for stability

  if (nowAction == 0) {
      servo.write(0); // サーボの角度を0°に設定
      digitalWrite(LED, LOW);
  } else {
      servo.write(77); // サーボの角度を90°に設定
      digitalWrite(LED, HIGH);
  }
}
