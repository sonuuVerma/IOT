/*
 * Real time Sensor Dashboard with trend graph. 
 */
#include "WiFi.h"
#include "ESPAsyncWebServer.h"
#include "index.h"

#include<Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

//For BME280 Sensor
#define SEALEVELPRESSURE_HPA (1013.25)
Adafruit_BME280 bme;

#define LED 2  //On board LED

unsigned bmestatus;

//SSID and Password of your WiFi router
const char* ssid = "Rmn";
const char* password = "singh1313";

AsyncWebServer server(80); //Server on port 80

//===============================================================
// This routine is executed when you open its IP in browser
//===============================================================
void handleRoot(AsyncWebServerRequest *request) {
 String s = MAIN_page; //Read HTML contents
 request->send(200, "text/html", s); //Send web page
}

void handleTemperature(AsyncWebServerRequest *request) {
 int a = analogRead(A0);
 float t = bme.readTemperature();
 String adcValue = String(t);
 digitalWrite(LED,!digitalRead(LED)); //Toggle LED on data request ajax
 request->send(200, "text/plane", adcValue); //Send ADC value only to client ajax request
}
//==============================================================
//                  SETUP
//==============================================================
void setup(void){
  Serial.begin(115200);
  
  WiFi.begin(ssid, password);     //Connect to your WiFi router
  Serial.println("");

  //Onboard LED port Direction output
  pinMode(LED,OUTPUT); 
  bmestatus = bme.begin(0x76);
  
  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  //If connection successful show IP address in serial monitor
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());  //IP address assigned to your ESP
 
  server.on("/",HTTP_GET, handleRoot);      //Which routine to handle at root location. This is display page
  server.on("/readTemperature",HTTP_GET, handleTemperature); //This page is called by java Script AJAX

  server.begin();                  //Start server
  Serial.println("HTTP server started");
}

//==============================================================
//                     LOOP
//==============================================================
void loop(void){
  //server.handleClient();          //Handle client requests
}
