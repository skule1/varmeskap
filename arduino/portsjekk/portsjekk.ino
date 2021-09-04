#define gate 18 //triac gate input pin
#define sync1 19 // zero-cross detector ouput positive impulse (pulse length 200us)
#
void setup() {
  // put your setup code here, to run once:
 // pinMode(sync1, INPUT_PULLUP);
  pinMode(sync1, OUTPUT);
  pinMode(gate,OUTPUT);
}

void loop() {
  
digitalWrite(sync1,LOW);
digitalWrite(gate,LOW);
delay(10);
digitalWrite(sync1,HIGH);
digitalWrite(gate,HIGH);
delay(10);
}
