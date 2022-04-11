#include "WiFi.h"
#include "ESPAsyncWebServer.h"
 

const char* ssid = "";
const char* password =  "";

//Using asynchronous webserver implementation 
AsyncWebServer server(80);
 
void setup(){
  Serial.begin(115200);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
  
  //Make sure we have been assigned an IP
  Serial.println(WiFi.localIP());

  //Setting up the Endpoint Handler. An example of anonymous function
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(200, "text/plain", "Query String Demo");
  });
  
  server.on("/commandCenter", HTTP_GET,handleCommand);
  //server.on("/readSensor", HTTP_OPTIONS, sendCrossOriginHeader);
  server.on("/readSensor", HTTP_GET,handleSensorRead);
  server.begin();
}

void handleCommand(AsyncWebServerRequest *request)
{
  int paramLn = request->params();
  Serial.println(String(paramLn) + " numbers of parameters received");

 for(int i=0;i<paramLn;i++)
 {
    AsyncWebParameter *p = request->getParam(i);
    Serial.print("Param name: ");
    Serial.println(p->name());
    Serial.print("Param value: ");
    Serial.println(p->value());
 }
 
 request->send(200, "text/plain", "Parameters Parsed correctly");
}

void sendCrossOriginHeader(AsyncWebServerRequest *request){
    Serial.println(F("sendCORSHeader"));
 
    request->send(204);
}

void handleSensorRead(AsyncWebServerRequest *request)
{
  
  int val = map(analogRead(A0),0,4095,0,100);

  //Response Header to qualify CORS
  AsyncWebServerResponse *response = request->beginResponse(200, "text/plain", String(val));
  response->addHeader("Access-Control-Allow-Origin", "*");
  response->addHeader("Access-Control-Max-Age", "600");
  response->addHeader("Access-Control-Allow-Methods", F("PUT,POST,GET,OPTIONS"));
  response->addHeader("Access-Control-Allow-Headers", "*");
  request->send(response);
  
}

void loop(){
  
  }
