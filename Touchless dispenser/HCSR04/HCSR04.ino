//const int echoPin = 12; // attach pin GPIO12 ESP to pin Echo of HC-SR04
//const int trigPin = 13; //attach pin GPIO13 ESP to pin Trig of HC-SR04
//
//// defines variables
//long duration; // variable for the duration of sound wave travel
//float distance; // variable for the distance measurement
//
//void setup() {
//  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
//  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
//  Serial.begin(115200); // // Serial Communication is starting with 115200 of baudrate speed
//  Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
//}
//void loop() {
//  // Clears the trigPin condition
//  digitalWrite(trigPin, LOW);
//  delayMicroseconds(2);
//  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
//  digitalWrite(trigPin, HIGH);
//  delayMicroseconds(10);
//  digitalWrite(trigPin, LOW);
//  // Reads the echoPin, returns the sound wave travel time in microseconds
//  duration = pulseIn(echoPin, HIGH);
//  // Calculating the distance
//  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
//  // Displays the distance on the Serial Monitor
//  Serial.print("Distance: ");
//  Serial.print(distance);
//  Serial.println(" cm");
//  delay(500);
//}





// using HCSR04.h


#include <HCSR04.h>

// Initialize sensor that uses digital pins 13 and 12.
int triggerPin = 13;
int echoPin = 12;
UltraSonicDistanceSensor distanceSensor(triggerPin, echoPin);

void setup () {
    Serial.begin(9600);  // We initialize serial connection so that we could print values from sensor.
}

void loop () {
    // Every 500 miliseconds, do a measurement using the sensor and print the distance in centimeters.
    long distance = distanceSensor.measureDistanceCm();
    Serial.println(distance);
    delay(500);
}
