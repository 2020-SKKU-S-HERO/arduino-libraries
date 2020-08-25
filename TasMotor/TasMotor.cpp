#include "TasMotor.h"

int left = 10;
int right = 11;

TasMotor::TasMotor()
{

}

void TasMotor::init(){
  pinMode(left, OUTPUT);
  pinMode(right, OUTPUT);

}

void TasMotor::setMotor(String in_data){
    Serial.println("in_data: "+ in_data);
    if(in_data == "off")
      {
        digitalWrite(left, LOW);
        digitalWrite(right, LOW);
        Serial.println("stop");
      }
      else if(in_data == "on")
      {
        analogWrite(left, 255);
        digitalWrite(right, LOW);
        Serial.println("go");

      }
}
