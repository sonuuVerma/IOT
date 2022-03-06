/*
 **
 ***Weather Station with Oled and Bme280 
 **
 */

//#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT);

#define SEALEVELPRESSURE_HPA (1013.25)// variable saves the pressure at the sea level in hectopascal.This variable is used to estimate the altitude for a given pressure by comparing it with the sea level pressure.

Adafruit_BME280 bme; // uses I2C communication protocol by default



void setup() {
  Serial.begin(115200);// to start serial communication not needed to display any thing on screen but for debugging purposes on serial monitor.

/*bme_setup*/

  bool status;
    
  status = bme.begin(0x76);// address 0*76 passed to .begin method to start communication with bme sensor
  if (!status) {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while (1);
  } 
   
  Serial.println("-- BME CONNECTED --");
  Serial.println();

/*oled_setup*/
 
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3c)) {
    Serial.println(F("SSD1306 allocation failed"));
  }
  delay(2000);
  display.clearDisplay();
  display.setTextColor(WHITE);
}

void loop() {

  printValues();
  
}


void printValues()
{
  float t = bme.readTemperature();
  float h = bme.readHumidity();
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from sensor!");
  }

  //clear display
  display.clearDisplay();

  // display temperature
  display.setTextSize(1);
  display.setCursor(0,0);
  display.print("Temperature: ");
  display.setTextSize(2);
  display.setCursor(0,10);
  display.print(t);
  display.print(" ");
  display.setTextSize(1);
  display.cp437(true);//To display the º symbol, we use the Code Page 437 font.
  display.write(167);//º symbol corresponds to character 167.
  display.setTextSize(2);
  display.print("C");
  
  // display humidity
  display.setTextSize(1);
  display.setCursor(0, 35);
  display.print("Humidity: ");
  display.setTextSize(2);
  display.setCursor(0, 45);
  display.print(h);
  display.print(" %"); 
  
  display.display();// need to call display object to actually dispaly something on screen    
}
