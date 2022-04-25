// This code works with mqtt3.thingspeak.com with added device functionality.

#include <WiFi.h>
#include<PubSubClient.h>

int sensorVal;
//int sensorPin = 36;//<Define your Pin>

const char* ssid ="Verma";
const char* passwd = "verma8771";
//char userName[] = "SonuVerma"; // anything you want
//char passKey[] = "2WCG40CIFIQOITNX"; // profile key or user api key
char writeApiKey[] = "95WRVVH8YUQP"; // channel api key
long channelId = 1713709; // channel id

//experimenatl
char userName[] = "EBweOwsTOSczopHB0GA"; // anything you want
char passKey[] = "aK0fB/zz406TCEciEOC0N"; // profile key or user api key
char clientId[] = "EBweOwsTOEzopHB0GAwo";


static const char alphanum[] = "0123456789"
                                "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                                "abcdefghijklmnopqrstuvwxyz"; // for generation of client ID

WiFiClient client;

const char* server = "mqtt3.thingspeak.com";

PubSubClient mqttClient(client); // init PubSub

unsigned long lastConnectionTime = 0;
const unsigned long postingInterval = 20 * 1000; // post data every 20 sec (1000ms = 1s)


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  int status = WL_IDLE_STATUS;
  
  Serial.println("Esp32 started..!");
  
  while(status != WL_CONNECTED){
    status = WiFi.begin(ssid, passwd);
    status = WL_CONNECTED;
    delay(5000);
    }

    Serial.println("Connected to Wifi...");
    mqttClient.setServer(server, 1883);
    Serial.print("mqttClient State: "); Serial.println(mqttClient.state());

}

void loop() {
  // put your main code here, to run repeatedly:
  if(!mqttClient.connected()){
    
    reconnect();
    
    }

    mqttClient.loop();

    if(millis() - lastConnectionTime > postingInterval){
      
      mqttPublishFeed();
      Serial.print("mqttClient State: "); Serial.println(mqttClient.state());
    }
    
}

// reconnect function
void reconnect(){
//  char clientId[9];
//   char clientId[] = "HDkcJh81PTo0IyEOKRMsECk";

  while(!mqttClient.connected()){
    Serial.println("Trying to get connection...");
//    for(int i=0; i<8; i++){
//      clientId[i] = alphanum[random(51)];
//      }
//      clientId[8]='\0';
//      Serial.println(clientId);
      delay(2000);
      
  if(mqttClient.connect(clientId,userName,passKey)){
      Serial.println("Connected..!");
      bool PubSub_Status = mqttClient.connected();
      Serial.print("mqttClient.connected after mqttClient.connect: "); Serial.println(PubSub_Status);
      Serial.print("mqttClient State: "); Serial.println(mqttClient.state());
      }
  else{
      Serial.print("failed, rc=");
      Serial.print(mqttClient.state());
      Serial.println("try again in 5 sec");
      delay(5000);
      }
    }
  }

  void mqttPublishFeed(){
    // provide data generation mechanism below
    sensorVal = random(100); // we can put analog/digital read but for exeperiments we use random function
    String data = String("field1=") + String(sensorVal, DEC) + String("&field2=") + String(sensorVal- random(sensorVal), DEC)+"&status=MQTTPUBLISH";
    int length = data.length();
    const char *msgBuffer;
    msgBuffer = data.c_str();
    Serial.println(msgBuffer);

//    String topicString = "channels/" + String(channelId) + "/publish/" + String(writeApiKey);
    String topicString = "channels/" + String(channelId) + "/publish";
    length = topicString.length();
    const char *topicBuffer;
    topicBuffer = topicString.c_str();
    Serial.println(topicBuffer);
    bool mqttpublish = mqttClient.publish(topicBuffer, msgBuffer);
    Serial.print("mqttClient.publish status: "); Serial.println(mqttpublish);
    bool PubSub_Status = mqttClient.connected();
    Serial.print("mqttClient.connected after publish: "); Serial.println(PubSub_Status);

    lastConnectionTime = millis();
    
    }
