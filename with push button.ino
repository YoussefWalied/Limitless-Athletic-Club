#include <Servo.h>

Servo servo1;
Servo servo2;

int buttonPin = 12;
int buttonState = 0;
int servo1Pos = 0;
int servo2Pos = 180;
int servoIncrement = 1;

void setup() {
  servo1.attach(8);
  servo2.attach(9);
  pinMode(buttonPin, INPUT_PULLUP);
  servo1.write(servo1Pos);
  servo2.write(servo2Pos);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  
  if (buttonState == LOW) {
    servo1Pos += servoIncrement;
    servo2Pos -= servoIncrement;
    
    if (servo1Pos > 180) {
      servo1Pos = 180;
      servo2Pos = 0;
      servoIncrement = -1;
    } else if (servo1Pos < 0) {
      servo1Pos = 0;
      servo2Pos = 180;
      servoIncrement = 1;
    }
    
    servo1.write(servo1Pos);
    servo2.write(servo2Pos);
    delay(10); // Delay to allow servos to move to new position
  }
}