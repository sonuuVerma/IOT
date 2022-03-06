/*
 * Twilight Switch : A twilight switch is an electronic component that allows the automatic activation of a lighting circuit when natural light drops in a given environment
 */


/*
 * Twilight Switch
 */



//int sensorPin = 36;
//int ledPin = 2;
////int relayOut = 25;
//
//void setup(){
//  pinMode(ledPin, OUTPUT);
//  Serial.begin(9600);
//}
//
//void loop(){
//  int sensorVal = map(analogRead(sensorPin),0,4095,0,100);
//  Serial.println(sensorVal);
//
//  if(sensorVal<40){
//    digitalWrite(ledPin, HIGH);
//  }
//  else{
//    digitalWrite(ledPin,LOW);
//  }
//}






// DAC 


/*
#define DACpin 26
void setup(){
  pinMode(DACpin,OUTPUT);
}
void loop(){
  dacWrite(DACpin,225);
}
*/



//Twilight Switch2





#define DACpin 26

int sensorPin = 36;


void setup(){
  Serial.begin(9600);
}

void loop(){
  int sensorVal = map(analogRead(sensorPin),0,4095,255,0);
  Serial.println(sensorVal);
  dacWrite(DACpin,sensorVal);
}




 
