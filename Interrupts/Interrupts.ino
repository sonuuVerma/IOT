//const int button_pin = 19;
//int button_state;
//
//void setup()
//{
//  pinMode(button_pin, INPUT_PULLDOWN);
//  Serial.begin(9600);
//}
//
//void loop()
//{
//  button_state = digitalRead(button_pin);
//  Serial.println(button_state);
//  //delay(300);
//}


//Hardware interrupts // GPIO


const int button_pin = 19;
volatile int state = LOW;


portMUX_TYPE synch = portMUX_INITIALIZER_UNLOCKED;

void IRAM_ATTR interrupt_handler()
{
  portENTER_CRITICAL(&synch);
  Serial.println("interrupt");
  
  portEXIT_CRITICAL(&synch);
}

void setup()
{
  pinMode(button_pin, INPUT_PULLDOWN);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(button_pin), interrupt_handler ,HIGH);
}

void loop()
{
  Serial.println("insideloop");
  delay(1000);
}




// button counter 



//const int button_pin = 4; 
//int count = 0;
//int button_state;
//int current_button_state;
//void setup() {
//  pinMode(button_pin,INPUT_PULLUP);
//  Serial.begin(9600);
//
//}
//
//void loop() {
//  Serial.println(count);
//  button_state=digitalRead(button_pin);
//  if(button_state == LOW){
//    count++;
//  }
//  delay(10);
//}




// botton counter with interrupt




//const int button_pin = 19; 
//int count = 0;
//
//
////portMUX_TYPE synch = portMUX_INITIALIZER_UNLOCKED;
//
//
//void IRAM_ATTR interrupt_handler()
//{
//  //portENTER_CRITICAL(&synch);
//  //count++;
//  Serial.println("Inside interrupt");
//  //portEXIT_CRITICAL(&synch);
//}
//
//
//void setup() {
//  Serial.begin(9600);
//  pinMode(button_pin,INPUT_PULLDOWN);
//  attachInterrupt(digitalPinToInterrupt(button_pin), interrupt_handler ,RISING);
//  
//
//}
//
//void loop() {
//  Serial.println("Inside loop");
//  //Serial.println(count);
//  delay(1000);
//}
