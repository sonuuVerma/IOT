/*
 * Reading Analog values
 */



 void setup(){
  Serial.begin(115200);
 }

 void loop(){
  //Serial.println(analogRead(36));

  int sensorVal = map(analogRead(A0),800,1283,0,100); //mapping values from 0-4095 to 0-100
  Serial.println(sensorVal);
  delay(500);
 }
