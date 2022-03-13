#include "Freenove_WS2812_Lib_for_ESP32.h"

//Open Source Hardware Icon Pad
#define TOUCHPAD 14

//For WS2812b Leds
#define WS2812_LEDS_COUNT  6
#define WS2812_LEDS_DIN  33
#define WS2812_CHANNEL   3
Freenove_ESP32_WS2812 strip = Freenove_ESP32_WS2812(WS2812_LEDS_COUNT, WS2812_LEDS_DIN, WS2812_CHANNEL,TYPE_GRB);



void setup() {
  // put your setup code here, to run once:

  //Initializing WS2812 strip
  strip.begin();

}

bool touchState = 0;

void loop() {
  // put your main code here, to run repeatedly:
  if(TouchSens()< 60)
    {
      touchState = !touchState;
      delay(350);
    }
    
    if(touchState)
      rainbowOn();
    else
      rainbowOff();
              

}

int colorCode = 255;
int ledIndex = WS2812_LEDS_COUNT;
void rainbowOn()
{ 
          strip.setLedColor(ledIndex, strip.Wheel((ledIndex * 256 / WS2812_LEDS_COUNT + colorCode) & 255));
          ledIndex = ledIndex > 0 ? --ledIndex : WS2812_LEDS_COUNT;
          colorCode = colorCode > 0  ? (colorCode-2) : 255;   
}

void rainbowOff()
{
   for (int i = 0; i < WS2812_LEDS_COUNT; i++) 
    strip.setLedColor(i,0x00);
}

int TouchSens()
{
  int sample = 0;
  for(int i=0;i<32;i++)
    sample += touchRead(TOUCHPAD);
  sample = sample / 32;
  
  return sample;
}
