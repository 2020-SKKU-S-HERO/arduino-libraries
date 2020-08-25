#include "TasLEDbar.h"

#include "FastLED.h"

#define LED_PIN  9
#define  NUM_LEDS  33
CRGB leds[NUM_LEDS];

TasLEDbar::TasLEDbar()
{

}

void TasLEDbar::init()
{
    FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
}

void TasLEDbar::setLEDbar(String in_data)
{
    if(in_data == "off")
    {
        for(int i = 0; i<33; i++)
        {
            leds[i] = CRGB(0,0,0);
            FastLED.show();
        }
    }
    else if (in_data == "on")
    {
        for (int i = 0; i < 33; i++)
        {
            leds[i] = CRGB(255,0,0);
            FastLED.show();
//            delay(40);
        }
  /*    for(int i = 0; i < 33; i++)
        {
            leds[i] = CRGB(0,0,0);
            FastLED.show();
            delay(40);
        }*/
    }
}
