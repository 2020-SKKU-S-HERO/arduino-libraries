// 0을 넣으면 0도가 되고, 1을 넣으면 30도가 되는 서보모터 제어문
// 이전과 같이 Serial.available을 Serial.server로 바꾸면 된다.
// 해당 문서에서는 아두이노에서 바로 제어하기 위해서 onoff를 char로 했고, 그 값을 0과 1로 했으나, Tas로 변환시에는 String, on off로 바꾸는 것을 잊지 않도록
// 서보모터의 경우 비비탄이 어느정도 속도로 떨어질지 예측하기 어렵기 때문에 nCube에 입력할 때에 LED, 메인DC모터 등과 따로 제어하게 nCube를 입력하면 좋을 것 같다.

#include <Servo.h>

Servo myservo;

void setup() {
  myservo.attach(5); //서보모터 어느 핀에 꽂을건지 설정 여기서는 5번핀
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
      myservo.write(0);       //서보모터의 각도를 0으로 한다.
      delay(15);
    }
    else if(onoff == '1')
    {
      myservo.write(30);      //서보모터의 각도를 30으로 한다. 이 값은 시연을 해보고 수정해보도록 한다.
      delay(15);
    }
  }
}
