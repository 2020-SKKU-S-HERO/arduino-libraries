#include <Servo.h>

Servo myservo;

int pos = 0;

void setup() {
  myservo.attach(5); //서보모터 어느 핀에 꽂을건지 설정
  Serial.begin(9600);

  

  Serial.println("Servo start");

}

void loop() {
  char onoff = '0';
  if(Serial.available())
  {
    onoff = Serial.read();

    if(onoff == '0')
    {
      myservo.write(0);
      delay(15);
    }
    else if(onoff == '1')
    {
      myservo.write(30);
      delay(15);
    }
  }
}
