#include "TasMotor.h"

bool TasMotor::init(){
  int left = 13;
  int right = 12;
  pinMode(left, OUTPUT);
  pinMode(right, OUTPUT);

}

bool TasMotor::setMotor(char in_data){
    if(in_data == '1')
      {
        analogWrite(left, 100);
        digitalWrite(right, LOW);
        Serial.println("left");
      }
      else if(in_data == '2')
      {
        digitalWrite(left, LOW);
        digitalWrite(right, HIGH);
        Serial.println("right");

      }
      else if(in_data == '3')
      {
        digitalWrite(left, LOW);
        digitalWrite(right, LOW);
        Serial.println("stop");
      }
      else if(in_data == '4')
      {
        digitalWrite(left, HIGH);
        digitalWrite(right, LOW);
        Serial.println("right");

      }
}
