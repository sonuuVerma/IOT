# define DAC 26


void setup() {
  pinMode(DAC,OUTPUT);
  // put your setup code here, to run once:

}

void loop() {
  
  dacWrite(DAC, 200);

}
