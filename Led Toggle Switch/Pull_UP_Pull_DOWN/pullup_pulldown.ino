const int button_pin = 35; 
const int led_pin = 4;

void setup() {
  // put your setup code here, to run once:

  //set the mode of the pin
  pinMode(button_pin,INPUT);
  pinMode(led_pin,OUTPUT);

  //start serial communication
  Serial.begin(9600);

}//close setup

void loop() {
  // put your main code here, to run repeatedly:

  //read the voltage at the Input pin. 
  int sensor_value = digitalRead(button_pin);

  //toggle led 
  //when button pressed turn LED on
  if(sensor_value == HIGH)
  {
    digitalWrite(led_pin,HIGH);
  }
  else
  {
    digitalWrite(led_pin,LOW);
  }//close if else

  //display the value
  Serial.println(sensor_value);

}//close loop
