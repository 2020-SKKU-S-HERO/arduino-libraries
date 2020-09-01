#include "TasFan.h"

int fan = A1;

TasFan::TasFan()
{

}

void TasFan::init(){
  pinMode(fan, OUTPUT);
  //Serial.println("fan start");
}

void TasFan::setFan(String in_data){
  Serial.println("Fan Start!!");
  if(in_data == "off")
 {
   Serial.println("off");
   analogWrite(fan, 0);

 }
 else if(in_data == "on")
 {
   Serial.println("on");
   analogWrite(fan,255);
 }
}
