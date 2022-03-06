/*******************Oled with esp32****************/

// to work with oleds we need to install some libraries mainly adafruitssd1306(for working with oleds with 1306 driver chip) and adafruit gfx(for displaying patterns)

//Some functions to handle oled display 
/*
display.clearDisplay() – all pixels are off
display.drawPixel(x,y, color) – plot a pixel in the x,y coordinates
display.setTextSize(n) – set the font size, supports sizes from 1 to 8
display.setCursor(x,y) – set the coordinates to start writing text
display.print(“message”) – print the characters at location x,y
display.display() – call this method for the changes to make effect
*/


/**************************************************************************************************************************************************************************************************************************************/


/*
  Hello World 
*/

/*
#include <Adafruit_GFX.h> //for displaying patterns
#include <Adafruit_SSD1306.h> //for working with oleds with 1306 driver chip
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
//initialising display object with the width and height defined earlier with I2C communication protocol (&Wire).
// The (-1) parameter means that your OLED display doesn’t have a RESET pin. 
//If your OLED display does have a RESET pin, it should be connected to a GPIO. 
//In that case, you should pass the GPIO number as a parameter.
void setup() {
  Serial.begin(115200); // initiailze serial monitor
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for some oleds. // SSD1306_SWITCHCAPVCC to turn on internal circitry on
    Serial.println(F("SSD1306 allocation failed"));    
}
  
  delay(1000);
  display.clearDisplay();//clear the display buffer
  display.setTextSize(1);//Set the font size 
  display.setTextColor(WHITE);
  display.setCursor(20, 20);//position where the text starts
  // Display static text
  display.println("hello world"); //send the text to the display 
  display.display();//display the text on the screen.
}
void loop() {  
  
}
*/


/**************************************************************************************************************************************************************************************************************************************/


/*
  Scrolling Text
*/


/*
startscrollright(0x00, 0x0F): scroll text from left to right
startscrollleft(0x00, 0x0F): scroll text from right to left
startscrolldiagright(0x00, 0x07): scroll text from left bottom corner to right upper corner
startscrolldiagleft(0x00, 0x07): scroll text from right bottom corner to left upper corner
*/





//#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT);

void setup() {
  Serial.begin(115200);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
  }
  delay(2000);
  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  // Display static text
  display.println("Scrolling Hello");
  display.display(); 
  delay(100);
 
}

void loop() {
  // Scroll in various directions, pausing in-between:
  display.startscrollright(0x00, 0x0F);
  delay(2000);
  display.stopscroll();
  delay(1000);
  display.startscrollleft(0x00, 0x0F);
  delay(2000);
  display.stopscroll();
  delay(1000);
  display.startscrolldiagright(0x00, 0x07);
  delay(2000);
  display.startscrolldiagleft(0x00, 0x07);
  delay(2000);
  display.stopscroll();
  delay(1000);
}





 
