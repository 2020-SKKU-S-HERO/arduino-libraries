//길다란 테이프형 LED오면 적용할 코드
//아래 for문이 1번 돌때마다 1을 서버에서 계속 넣어줘야 함
// Serial.available을 Server.available로 바꿔서 수정해주세요.

#include <Servo.h>

#include <FastLED.h>

#define LED_PIN_RED 7         //각각의 LED 제어핀 번호 설정
#define LED_PIN_BLUE 8
#define LED_PIN_GREEN 9
#define NUM_LEDS 20

CRGB ledsr[NUM_LEDS];         //각각 LED마다 LED개수만큼의 배열 생성
CRGB ledsb[NUM_LEDS];
CRGB ledsg[NUM_LEDS];

int left = 10;                //DC모터 제어핀 설정
int right = 11;

int servoPin = 12;            //서보모터 제어핀 설정

Servo servo;

int angle = 0;                //서보모터 초기 위치값



void setup() {
  FastLED.addLeds<WS2812, LED_PIN_RED, GRB>(ledsr, NUM_LEDS);     //위에서 선정한 배열에 LED 핀 번호 입힘
  FastLED.addLeds<WS2812, LED_PIN_BLUE, GRB>(ledsb, NUM_LEDS);
  FastLED.addLeds<WS2812, LED_PIN_GREEN, GRB>(ledsg, NUM_LEDS);
  pinMode(left,OUTPUT);           //DC모터 핀 설정
  pinMode(right,OUTPUT);
  

  servo.attach(servoPin);

  Serial.begin(9600);
}

void loop() {

  char onoff = '0';             // 이 onoff변수에 char 형태로 0 또는 1을 넣어줘야 함. 1을 넣을때에는 타이밍 맞춰서 1을 계속 넣어줘야 LED들이 계속 깜빡거림
  
  if(Serial.available())
  {
    onoff == Serial.read();

    if (onoff == 0)
    {
      Serial.println("status : 0");
      analogWrite(left, LOW);
      digitalWrite(right, LOW);
      servo.write(0);
      for (int i = 0; i < 19; i++)
      {
        ledsr[i] = CRGB(0,0,0);
        ledsb[i] = CRGB(0,0,0);
        ledsg[i] = CRGB(0,0,0);
        FastLED.show();
      }
    }
    else if(onoff == 1)
    {
      Serial.println("status : 1");
      analogWrite(left,255);
      digitalWrite(right,LOW);
      servo.write(30);
      for (int i = 0; i < 19; i++)
      {
        ledsr[i] = CRGB (255,0,0);
        ledsb[i] = CRGB (0,0,255);
        ledsg[i] = CRGB (0,255,0);
        FastLED.show();
        delay(40);
      }
      for (int j = 0; j < 19; j++)
      {
        ledsr[j] = CRGB(0,0,0);
        ledsb[j] = CRGB(0,0,0);
        ledsg[j] = CRGB(0,0,0);
        FastLED.show();
        delay(40);
      }
    }
  }

}
