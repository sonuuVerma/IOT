// ESP32 Touch Test


//void setup()
//{
//  Serial.begin(115200);
//}
//
//void loop()
//{
//  Serial.println(touchRead(14));  // get value using GPIO14
//  delay(500);
//}







#define TOUCHPAD 14

bool touchState = 0;


void setup(){
  Serial.begin(115200);
}

void loop(){
  Serial.println(touchState);
  if(TouchSens()< 60)
    {
      touchState = !touchState;
      delay(350);
    }
}




int TouchSens()
{
  int sample = 0;
  for(int i=0;i<32;i++)
    sample += touchRead(TOUCHPAD);
  sample = sample / 32;
  
  return sample;
}
