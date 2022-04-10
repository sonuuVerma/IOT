// Creating a Web Server in STA MODE


//#include <WiFi.h>
//#include <WebServer.h>
//
//// SSID & Password
//const char* ssid = "Qeslanet";  // Enter your SSID here
//const char* password = "BenignAlgorithm";  //Enter your Password here
//
//
//WebServer server(80);  // Object of WebServer(HTTP port, 80 is defult)
//
//
//void setup() {
//  Serial.begin(115200);
//  Serial.println("Try Connecting to ");
//  Serial.println(ssid);
//
//
//  // Connect to your wi-fi modem
//  WiFi.begin(ssid, password);
//
//  // Check wi-fi is connected to wi-fi network
//  while (WiFi.status() != WL_CONNECTED) {
//  delay(1000);
//  Serial.print(".");
//  }
//  Serial.println("");
//  Serial.println("WiFi connected successfully");
//  Serial.print("Got IP: ");
//  Serial.println(WiFi.localIP());  //Show ESP32 IP on serial
//
//  server.on("/", handle_root);
//
//  server.begin();// to start server
//  Serial.println("HTTP server started");
//  delay(100); 
//}
//
//void loop() {
//  server.handleClient();
//}
//
//// HTML contents which display on web server
//String HTML = "<!DOCTYPE html>\
//<html>\
//<body>\
//<h1>My First Web Server with ESP32 - Station Mode</h1>\
//</body>\
//</html>";
//
//// Handle root url 
//void handle_root() {
//  server.send(200, "text/html", HTML);
//}






// LED CONTROL





#include <WiFi.h>
#include <WebServer.h>

//Put your SSID & Password

const char* ssid = "Qeslanet";  // Enter SSID here
const char* password = "BenignAlgorithm";  //Enter Password here

WebServer server(80);


uint8_t LEDpin = 4;
bool LEDstatus = LOW;

void setup() {
  Serial.begin(115200);
  delay(100);
  pinMode(LEDpin, OUTPUT);

  Serial.println("Connecting to ");
  Serial.println(ssid);

  //connect to your local wi-fi network
  WiFi.begin(ssid, password);

  //check wi-fi is connected to wi-fi network
  while (WiFi.status() != WL_CONNECTED) {
  delay(1000);
  Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected..!");
  Serial.print("Got IP: ");  Serial.println(WiFi.localIP());

  server.on("/", handle_OnConnect);
  server.on("/ledon", handle_ledon);
  server.on("/ledoff", handle_ledoff);
  server.onNotFound(handle_NotFound);

  server.begin();
  Serial.println("HTTP server started");
}
void loop() {
  server.handleClient();
  
  if(LEDstatus)
  {digitalWrite(LEDpin, HIGH);}
  else
  {digitalWrite(LEDpin, LOW);}
}

void handle_OnConnect() {
  LEDstatus = LOW;
  Serial.println("GPIO4 Status: OFF");
  server.send(200, "text/html", SendHTML(LEDstatus)); 
}


void handle_ledon() {
  LEDstatus = HIGH;
  Serial.println("GPIO4 Status: ON");
  server.send(200, "text/html", SendHTML(true)); 
}

void handle_ledoff() {
  LEDstatus = LOW;
  Serial.println("GPIO4 Status: OFF");
  server.send(200, "text/html", SendHTML(false)); 
}

void handle_NotFound(){
  server.send(404, "text/plain", "Not found");
}




String SendHTML(uint8_t LEDstat){
  String ptr = "<!DOCTYPE html> <html>\n";

  ptr +="<title>LED Control</title>\n";
  ptr +="</head>\n";

  ptr +="<body>\n";
  ptr +="<h1>ESP32 Web Server</h1>\n";
  ptr +="<h3>Using Station(STA) Mode</h3>\n";


  if(LEDstat)
  {ptr +="<p>LED Status: ON</p><form action=\"/ledoff\"><button type='submit'>OFF</button></form>\n";} 
  else
  {ptr +="<p>LED Status: OFF</p><form action=\"/ledon\"><button type='submit'>ON</button></form>\n";}


  ptr +="</body>\n"; 
  ptr +="</html>\n";
  
  return ptr;
  
}





// LED & RELAY CONTROL






//#include <WiFi.h>
//#include <WebServer.h>
//
////Put your SSID & Password
//
//const char* ssid = "Qeslanet";  // Enter SSID here
//const char* password = "BenignAlgorithm";  //Enter Password here
//
//WebServer server(80);
//
//uint8_t RELAYpin = 25;
//bool RELAYstatus = LOW;
//
//uint8_t LEDpin = 4;
//bool LEDstatus = LOW;
//
//void setup() {
//  Serial.begin(115200);
//  delay(100);
//  pinMode(RELAYpin, OUTPUT);
//  pinMode(LEDpin, OUTPUT);
//
//  Serial.println("Connecting to ");
//  Serial.println(ssid);
//
//  //connect to your local wi-fi network
//  WiFi.begin(ssid, password);
//
//  //check wi-fi is connected to wi-fi network
//  while (WiFi.status() != WL_CONNECTED) {
//  delay(1000);
//  Serial.print(".");
//  }
//  Serial.println("");
//  Serial.println("WiFi connected..!");
//  Serial.print("Got IP: ");  Serial.println(WiFi.localIP());
//
//  server.on("/", handle_OnConnect);
//  server.on("/RELAYon", handle_RELAYon);
//  server.on("/RELAYoff", handle_RELAYoff);
//  server.on("/ledon", handle_ledon);
//  server.on("/ledoff", handle_ledoff);
//  server.onNotFound(handle_NotFound);
//
//  server.begin();
//  Serial.println("HTTP server started");
//}
//void loop() {
//  server.handleClient();
//  if(RELAYstatus)
//  {digitalWrite(RELAYpin, HIGH);}
//  else
//  {digitalWrite(RELAYpin, LOW);}
//  
//  if(LEDstatus)
//  {digitalWrite(LEDpin, HIGH);}
//  else
//  {digitalWrite(LEDpin, LOW);}
//}
//
//void handle_OnConnect() {
//  RELAYstatus = LOW;
//  LEDstatus = LOW;
//  Serial.println("GPIO4 Status: OFF | GPIO25 Status: OFF");
//  server.send(200, "text/html", SendHTML(RELAYstatus,LEDstatus)); 
//}
//
//void handle_RELAYon() {
//  RELAYstatus = HIGH;
//  Serial.println("GPIO4 Status: ON");
//  server.send(200, "text/html", SendHTML(true,LEDstatus)); 
//}
//
//void handle_RELAYoff() {
//  RELAYstatus = LOW;
//  Serial.println("GPIO4 Status: OFF");
//  server.send(200, "text/html", SendHTML(false,LEDstatus)); 
//}
//
//void handle_ledon() {
//  LEDstatus = HIGH;
//  Serial.println("GPIO25 Status: ON");
//  server.send(200, "text/html", SendHTML(RELAYstatus,true)); 
//}
//
//void handle_ledoff() {
//  LEDstatus = LOW;
//  Serial.println("GPIO25 Status: OFF");
//  server.send(200, "text/html", SendHTML(RELAYstatus,false)); 
//}
//
//void handle_NotFound(){
//  server.send(404, "text/plain", "Not found");
//}
//
//
//String SendHTML(uint8_t RELAYstat,uint8_t LEDstat){
//  String ptr = "<!DOCTYPE html> <html>\n";
//  ptr +="<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
//
//  ptr +="<title>LED & RELAY Control</title>\n";
//  ptr +="</head>\n";
//
//  ptr +="<body>\n";
//  ptr +="<h1>ESP32 Web Server</h1>\n";
//  ptr +="<h3>Using Station(STA) Mode</h3>\n";
//
//   if(RELAYstat)
//  {ptr +="<p>RELAY Status: ON</p><a href=\"/RELAYoff\">OFF</a>\n";}
//  else
//  {ptr +="<p>RELAY Status: OFF</p><a href=\"/RELAYon\">ON</a>\n";}
//
//  if(LEDstat)
//  {ptr +="<p>LED Status: ON</p><a href=\"/ledoff\">OFF</a>\n";}
//  else
//  {ptr +="<p>LED Status: OFF</p><a href=\"/ledon\">ON</a>\n";}
//
//  ptr +="</body>\n";
//  
//  ptr +="</html>\n";
//  
//  return ptr;
//  
//}
