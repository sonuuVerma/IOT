/********************************** Bouncy Button*************************/

/*



const int button_pin = 35; 
const int led_pin = 4;
boolean last_button_state = LOW; // to keep track of last button state
boolean led_on = false; // to toggle led on or off initially set to false

void setup() {
  // put your setup code here, to run once:

  //set the mode of the pin
  pinMode(button_pin,INPUT);
  pinMode(led_pin,OUTPUT);
  Serial.begin(9600);



}//close setup

void loop() {
  // put your main code here, to run repeatedly:

  Serial.println(last_button_state);

  //read the voltage at the input button pin. 
  int button_state = digitalRead(button_pin); // reading current input from botton 

  
  if(button_state == HIGH & last_button_state == LOW)
  {
    led_on = !led_on; //flip last value
    last_button_state = HIGH;
  }
  else
  {
    last_button_state = button_state;
  }//close if else
  digitalWrite(led_pin,led_on);

}//close loop






*/




/********************Debounced Button********************/





const int button_pin = 14; 
const int led_pin = 13;
boolean last_button_state = LOW; // to keep track of last button state
boolean button_state = LOW; // to keep track of current button value
boolean led_on = false; // to toggle led on or off initially set to false

void setup() {
  // put your setup code here, to run once:

  //set the mode of the pin
  pinMode(button_pin,INPUT);
  pinMode(led_pin,OUTPUT);
  Serial.begin(115200);



}//close setup


boolean debounce(boolean last)
{
  boolean current = digitalRead(button_pin);
  if(last != current)
  {
    delay(10);
    current = digitalRead(button_pin);
  }
  return current;
  
}


void loop() {
  // put your main code here, to run repeatedly:


  button_state = debounce(last_button_state);
  Serial.println(button_state);
  
  if(last_button_state == LOW && button_state == HIGH)
  {
    led_on = !led_on; //flip last value
  }
  last_button_state = button_state;
  digitalWrite(led_pin,led_on);

}//close loop







/***********************************Debounced Button 2******************************/



/*




const int button_pin = 12;    // the number of the pushbutton pin
const int led_pin = 13;      // the number of the LED pin

// Variables will change:
int led_state = LOW;         // the current state of the output pin
int button_state;             // the current reading from the input pin
int last_button_state = LOW;   // the previous reading from the input pin


unsigned long last_debounce_time = 0;  // the last time the output pin was toggled
unsigned long debounce_delay = 50;    // the debounce time; increase if the output flickers

void setup() {
  pinMode(button_pin, INPUT);
  pinMode(led_pin, OUTPUT);

  // set initial LED state
  digitalWrite(led_pin, led_state);

  Serial.begin(9600);
}

void loop() {
  // read the state of the switch into a local variable:
  int reading = digitalRead(button_pin);

  Serial.println(reading);

  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH), and you've waited long enough
  // since the last press to ignore any noise:

  // If the switch changed, due to noise or pressing:
  if (reading != last_button_state) {
    // reset the debouncing timer
    last_debounce_time = millis(); //millis() : this function returns the number of milliseconds the sketch has been running for   
  }

  if ((millis() - last_debounce_time) > debounce_delay) {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != button_state) {
      button_state = reading;

      // only toggle the LED if the new button state is HIGH
      if (button_state == HIGH) {
        led_state = !led_state;
      }
    }
  }

  // set the LED:
  digitalWrite(led_pin, led_state);

  // save the reading. Next time through the loop, it'll be the lastButtonState:
  last_button_state = reading;
}


*/
