#include "TasLEDbar.h"

#include "FastLED.h"

TasLEDbar::TasLEDbar()
{
    
}

void TasLEDbar::init()
{
    int LED_PIN = 9;
    int NUM_LEDS = 33;

    CRGB leds[NUM_LEDS];

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
    else if (onoff == "on")
    {
        for (int i = 0; i < 33; i++)
        {
            leds[i] = CRGB(255,0,0);
            FastLED.show();
            delay(40);
        }
        for(int i = 0; i < 33; i++)
        {
            leds[i] = CRGB(0,0,0);
            FastLED.show();
            delay(40);
        }
    }
}
