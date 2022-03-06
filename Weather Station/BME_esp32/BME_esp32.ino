// to work with BME 280 we need to use Adafruit BME280 library
// to work with BME 280 library we need adafruit sensor library (adafruit unified sensor)




/*
bme.readTemperature() – reads temperature in Celsius;
bme.readHumidity() – reads absolute humidity;
bme.readPressure() – reads pressure in hPa (hectoPascal = millibar);
bme.readAltitude(SEALEVELPRESSURE_HPA) – estimates altitude in meters based on the pressure at the sea level.
 */

//#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

#define SEALEVELPRESSURE_HPA (1013.25)// variable saves the pressure at the sea level in hectopascal.This variable is used to estimate the altitude for a given pressure by comparing it with the sea level pressure.

Adafruit_BME280 bme; // Creating an object of adafruitBME_280, so that we can access functions related to it //uses I2C communication protocol by default

unsigned long delayTime;

void setup() {
  pinMode(12,OUTPUT);
  digitalWrite(12,HIGH);
  Serial.begin(115200);//start a serial communication

  bool status;
  
  status = bme.begin(0x76);// address 0*76 passed to bme.begin method to start communication with bme sensor //  This function initializes I2C interface with given I2C Address and checks if the chip ID is correct. It then resets the chip using soft-reset & waits for the sensor for calibration after wake-up.
  if (!status) {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while (1);
  }
  
  Serial.println("-- Default Test --");
  delayTime = 1000;

  Serial.println();
}


void loop() { 
  printValues();
  delay(delayTime);
}


void printValues() {
  Serial.print("Temperature = ");
  Serial.print(bme.readTemperature());
  Serial.println(" *C");
  
  // Convert temperature to Fahrenheit
  /*Serial.print("Temperature = ");
  Serial.print(1.8 * bme.readTemperature() + 32);
  Serial.println(" *F");*/
  
  Serial.print("Pressure = ");
  Serial.print(bme.readPressure() / 100.0F);
  Serial.println(" hPa");
  
  Serial.print("Approx. Altitude = ");
  Serial.print(bme.readAltitude(SEALEVELPRESSURE_HPA));
  Serial.println(" m");
  
  Serial.print("Humidity = ");
  Serial.print(bme.readHumidity());
  Serial.println(" %");
  
  Serial.println();
}


//#include <Adafruit_Sensor.h>
//#include <Adafruit_BME280.h>
//
//Adafruit_BME280 bme;
//
//void setup(){
//  Serial.begin(9600);
//  bme.begin(0x76);
//}
//
//void loop(){
//  Serial.println(bme.readTemperature());
//  delay(1000);
//}
