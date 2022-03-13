//#include "Freenove_WS2812_Lib_for_ESP32.h"
//
//#define LEDS_COUNT 5
//#define LEDS_PIN 33
//#define CHANNEL 0
//
//Freenove_ESP32_WS2812 strip = Freenove_ESP32_WS2812(LEDS_COUNT, LEDS_PIN, CHANNEL, TYPE_GRB);
//
//
//void setup() {
//  strip.begin();  
//}
//void loop() {
//      strip.setLedColorData(2, strip.Wheel(85));
//      strip.show();
//      strip.setLedColorData(1, strip.Wheel(85));
//      strip.show();
//  
//}

#include "Freenove_WS2812_Lib_for_ESP32.h"

//

#define LEDS_COUNT  6
#define LEDS_PIN  33
#define CHANNEL   0

Freenove_ESP32_WS2812 strip = Freenove_ESP32_WS2812(LEDS_COUNT, LEDS_PIN);


void setup() {
  // put your setup code here, to run once:

  //Initializing WS2812 strip
  strip.begin();

}


void loop() {
  for (int j = 0; j < 255; j += 2) {
    for (int i = 0; i < LEDS_COUNT; i++) {
      strip.setLedColorData(i, strip.Wheel((i * 256 / LEDS_COUNT + j) & 255));
    }
    strip.show();
    delay(2);
  }  
}





//#include "Freenove_WS2812_Lib_for_ESP32.h"
//
//#define LEDS_COUNT 6
//#define LEDS_PIN 33
//#define CHANNEL 0
//
//Freenove_ESP32_WS2812 strip = Freenove_ESP32_WS2812(LEDS_COUNT, LEDS_PIN, CHANNEL, TYPE_GRB);
//
//
//
//
//hw_timer_t * timer = NULL;
//volatile uint8_t ledstat = 0; 
//
//void IRAM_ATTR onTimer(){
//  ledstat =! ledstat;
//}
//
//void setup() {
//  strip.begin();
//    
//  Serial.begin(115200);
//  
//
//
//  Serial.println("start timer ");
//  timer = timerBegin(0, 80, true);  // timer 0, MWDT clock period = 12.5 ns * TIMGn_Tx_WDT_CLK_PRESCALE -> 12.5 ns * 80 -> 1000 ns = 1 us, countUp
//  timerAttachInterrupt(timer, &onTimer, true); // edge (not level) triggered 
//  timerAlarmWrite(timer, 3000000, true); // 1000000 * 1 us = 1 s, autoreload true
//  timerAlarmEnable(timer); // enable
//}
//
//void loop() {
//
//  Serial.println(ledstat);
//  if(ledstat == 0){
//    strip.setLedColorData(1,0,0,0);
//    strip.show();
//  }
//  else{
//    strip.setLedColorData(1,255,255,255);
//    strip.show();
//  }
//}
