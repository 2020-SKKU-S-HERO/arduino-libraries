#include "TasMotor.h"

bool TasMotor::init(){
  int left = 10;
  int right = 11;
  pinMode(left, OUTPUT);
  pinMode(right, OUTPUT);

}

bool TasMotor::setMotor(char in_data){
    if(in_data == '0')
      {
        analogWrite(left, LOW);
        digitalWrite(right, LOW);
        Serial.println("stop");
      }
      else if(in_data == '1')
      {
        analogWrite(left, 255);
        digitalWrite(right, LOW);
        Serial.println("go");

      }
}
