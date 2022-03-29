// timer & millis()



//hw_timer_t * timer = NULL;
//
//void IRAM_ATTR onTimer(){
//  Serial.println(String(millis()));
//}
//
//void setup() {
//  Serial.begin(115200);
//
//  Serial.println("start timer ");
//  timer = timerBegin(0,80,true);  // timer 0, prescaler is dividing by 80 giving time perod of 1 micro second., count up
//  timerAttachInterrupt(timer, &onTimer, true); // edge (not level) triggered 
//  timerAlarmWrite(timer,1000000, true); // 1000000 * 1 us = 1 s, autoreload true
//  timerAlarmEnable(timer); // enable
//}
//
//void loop() {
//  
//}








// timer led







 
//hw_timer_t * timer = NULL;
//volatile int ledstat = 0; 
//
//void IRAM_ATTR onTimer(){
//  ledstat =! ledstat;
//  digitalWrite(4, ledstat);   // turn the LED on or off
//}
//
//void setup() {
//  Serial.begin(115200);
//
//  pinMode(4, OUTPUT);
//  digitalWrite(4, LOW);    
//
//  Serial.println("start timer ");
//  timer = timerBegin(0, 80, true);  // 
//  timerAttachInterrupt(timer, &onTimer, true); // edge  triggered 
//  timerAlarmWrite(timer, 1000000, true); // 1000000 * 1 us = 1 s, autoreload true
//  timerAlarmEnable(timer); // enable
//}
//
//void loop() {
//  
//}








// Multiple timers
//
//
//
//
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
//hw_timer_t * timer0 = NULL;
//hw_timer_t * timer1 = NULL;
//portMUX_TYPE timerMux0 = portMUX_INITIALIZER_UNLOCKED;
//portMUX_TYPE timerMux1 = portMUX_INITIALIZER_UNLOCKED;
//
//volatile int led1stat = 0; 
//volatile int led2stat = 0; 
//
//void IRAM_ATTR onTimer0(){
//  // Critical Code here
//  portENTER_CRITICAL_ISR(&timerMux0);
//  led1stat =! led1stat;
//  digitalWrite(4, led1stat);   // turn the LED on or off
//  portEXIT_CRITICAL_ISR(&timerMux0);
//}
//
//void IRAM_ATTR onTimer1(){
//  // Critical Code here
//  portENTER_CRITICAL_ISR(&timerMux1);
//  led2stat =! led2stat,
//  portEXIT_CRITICAL_ISR(&timerMux1);
//}
//
//void setup() {
//  strip.begin();
//  Serial.begin(115200);
//
//  pinMode(4, OUTPUT);
//  digitalWrite(4, LOW);    // turn the LED off by making the voltage LOW
//
//  Serial.println("start timer 1");
//  timer1 = timerBegin(1, 80, true);  // timer 1, countUp
//  timerAttachInterrupt(timer1, &onTimer1, true); // edge (not level) triggered 
//  timerAlarmWrite(timer1, 2000000, true); // 250000 * 1 us = 250 ms, autoreload true
//
//  Serial.println("start timer 0");
//  timer0 = timerBegin(0, 80, true);  // timer 0, countUp
//  timerAttachInterrupt(timer0, &onTimer0, true); // edge (not level) triggered 
//  timerAlarmWrite(timer0, 250000, true); // 2000000 * 1 us = 2 s, autoreload true
//
//  // at least enable the timer alarms
//  timerAlarmEnable(timer0); // enable
//  timerAlarmEnable(timer1); // enable
//}
//
//void loop() {
//  if(led2stat == 0){
//    for (int j = 0; j < 255; j += 2) {
//      for (int i = 0; i < LEDS_COUNT; i++) {
//        strip.setLedColorData(i, strip.Wheel((i * 256 / LEDS_COUNT + j) & 255));
//        }
//        strip.show();
//        delay(2);
//        }
//      }
//      else{
//        for (int i = 0; i < LEDS_COUNT; i++) {
//        strip.setLedColorData(i,0,0,0);
//        }
//        strip.show();
//        delay(2);
//        }  
//}
//
//
//
//




// PWM 



//
//
//
//// the number of the LED pin
//const int ledPin = 4;  
//
//// setting PWM properties
//const int freq = 5000;
//const int ledChannel = 0;
//const int resolution = 8;
// 
//void setup(){
//  // configure LED PWM functionalitites
//  ledcSetup(ledChannel, freq, resolution);
//  
//  // attach the channel to the GPIO to be controlled
//  ledcAttachPin(ledPin, ledChannel);
//}
// 
//void loop(){
//  // increase the LED brightness
//  for(int dutyCycle = 0; dutyCycle <= 255; dutyCycle++){   
//    // changing the LED brightness with PWM
//    ledcWrite(ledChannel, dutyCycle);
//    delay(15);
//  }
//
//  // decrease the LED brightness
//  for(int dutyCycle = 255; dutyCycle >= 0; dutyCycle--){
//    // changing the LED brightness with PWM
//    ledcWrite(ledChannel, dutyCycle);   
//    delay(15);
//  }
//}
//





// PWM Buzzer




 
//int freq = 5000;
//int channel = 0;
//int resolution = 8;
//  
//void setup() {
//  
//
//  ledcSetup(channel, freq, resolution);
//  ledcAttachPin(27, channel);
//  
//}
//  
//void loop() {
//  
//  
//  for (int dutyCycle = 0; dutyCycle <= 255; dutyCycle=dutyCycle+10){
//    ledcWrite(channel, dutyCycle);
//    delay(1000);
//  }
//}
