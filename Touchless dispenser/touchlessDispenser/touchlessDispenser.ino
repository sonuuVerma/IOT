const int echoPin = 12;
const int trigPin = 13;
const int relayOut = 25;

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(relayOut, OUTPUT);
  Serial.begin(115200);
}
void loop() {
 
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);

  distance = duration * 0.034 / 2;
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  if (distance<=5)
  {
    digitalWrite(relayOut, LOW);
    Serial.print("Pump On");
    delay(250);
    digitalWrite(relayOut, HIGH);
    Serial.print("Pump OFF");
    delay(2000);
  }
  else
  {
    digitalWrite(relayOut, HIGH);
    Serial.print("Pump OFF");
  
  }
  delay(50);
}




//// using HCSR04.h
//
//
//
//#include <HCSR04.h>
//
//// Initialize sensor that uses digital pins 13 and 12.
//int triggerPin = 13;
//int echoPin = 12;
//
//UltraSonicDistanceSensor distanceSensor(triggerPin, echoPin);
//
//void setup () {
//    Serial.begin(9600);  // We initialize serial connection so that we could print values from sensor.
//}
//
//void loop () {
//    // Every 500 miliseconds, do a measurement using the sensor and print the distance in centimeters.
//    double distance = distanceSensor.measureDistanceCm();
//    Serial.println(distance);
//
//    
//    
//}
