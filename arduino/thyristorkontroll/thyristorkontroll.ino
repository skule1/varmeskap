#define gate 18 //triac gate input pin
#define sync 19 // zero-cross detector ouput positive impulse (pulse length 200us)
#define pot A0

bool ZC = 0;
uint16_t alpha = 0;
int t = 0;

void ICACHE_RAM_ATTR ZC_detect()
//void ZC_detect()
// ICACHE_RAM_ATTR void ZC_detect()
{
ZC=1;

}


void setup(void)
{
  Serial.begin(115200);
  pinMode(sync, INPUT_PULLUP);
  attachInterrupt(sync, ZC_detect, FALLING);
  pinMode(gate, OUTPUT);
  //digitalWrite(gate, LOW);
  // attachInterrupt(digitalPinToInterrupt(sync), ZC_detect, FALLING);       // Enable external interrupt (INT0)
}


void loop()
{
 if (ZC)

  { delayMicroseconds(alpha);
    digitalWrite(gate, HIGH);
    delayMicroseconds(300);
    digitalWrite(gate, LOW);
    ZC = 0;
  }
Serial.println("test2");
// Serial.println("t:\t" + String(t) + "\t" + String(ZC));
  // for (alpha=0;alpha<10000;alpha+100)
  //alpha=18;
  //alpha=alpha+1;
  //if (alpha>10000) alpha=0;
  alpha = 5000;
    

  }
