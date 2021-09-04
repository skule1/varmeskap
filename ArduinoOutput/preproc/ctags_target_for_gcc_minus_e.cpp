# 1 "h:\\prosjekter\\varmeskap\\arduino\\varmeskap\\varmeskap.ino"
/***************************************************************************

  Denne skissen leer tempraturen fra en BMP280, koblet til en Wemos mini32 D1 microkontroller

  I2C adresse BMP280 :0x76

  0-deteksjon kobles til port  IO19

  thyristor-styringen skjer fra port  IO18





***************************************************************************/
# 9 "h:\\prosjekter\\varmeskap\\arduino\\varmeskap\\varmeskap.ino"
#define pinout 14 /*GPIO14, D5*/
int Temp, ValgtTemp = 34;
int val;
int Satt_temp = 40;
//int Max_temp = 60;
int Max_strom = 255;
int t = 0;

#define scr_trig 18
#define pot A0
#define ZERODETECTPIN 19
#define sync 19

bool ZC = 0;
uint16_t alpha;

# 26 "h:\\prosjekter\\varmeskap\\arduino\\varmeskap\\varmeskap.ino" 2
# 27 "h:\\prosjekter\\varmeskap\\arduino\\varmeskap\\varmeskap.ino" 2
# 28 "h:\\prosjekter\\varmeskap\\arduino\\varmeskap\\varmeskap.ino" 2
# 29 "h:\\prosjekter\\varmeskap\\arduino\\varmeskap\\varmeskap.ino" 2
# 30 "h:\\prosjekter\\varmeskap\\arduino\\varmeskap\\varmeskap.ino" 2

#define SCREEN_WIDTH 128 /* OLED display width, in pixels*/
#define SCREEN_HEIGHT 64 /* OLED display height, in pixels*/

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET 4 /* Reset pin # (or -1 if sharing Arduino reset pin)*/
Adafruit_SSD1306 display(128 /* OLED display width, in pixels*/, 64 /* OLED display height, in pixels*/, &Wire, 4 /* Reset pin # (or -1 if sharing Arduino reset pin)*/);

#define BMP_SCK (13)
#define BMP_MISO (12)
#define BMP_MOSI (11)
#define BMP_CS (10)

Adafruit_BMP280 bmp; // I2C
//Adafruit_BMP280 bmp(BMP_CS); // hardware SPI
//Adafruit_BMP280 bmp(BMP_CS, BMP_MOSI, BMP_MISO,  BMP_SCK);

void __attribute__((section(".iram1" "." "16"))) ZC_detect()
{
  ZC = 1;

}

void setup()
{
  Serial.begin(115200);
  Serial.println("h:\\prosjekter\\varmeskap\\arduino\\varmeskap\\varmeskap.ino");
  Serial.print("Kompilert: ");
  Serial.print("Fri Sep 03 15:29:31 2021");
  Serial.println(" Versjon: 1.0.0");

  if (!display.begin(0x02 /*|< Gen. display voltage from 3.3V*/, 0x3C))
  { // Address 0x3D for 128x64
    Serial.println(((reinterpret_cast<const __FlashStringHelper *>(("SSD1306 allocation failed")))));
    for (;;)
      ; // Don't proceed, loop forever
  };


  ledcAttachPin(14 /*GPIO14, D5*/, 1);

  if (!bmp.begin(0x76))
  {
    Serial.println(((reinterpret_cast<const __FlashStringHelper *>(("Could not find a valid BMP280 sensor, check wiring!")))));
    while (1)
      ;
  }

  /* Default settings from datasheet. */
  bmp.setSampling(Adafruit_BMP280::MODE_NORMAL, /* Operating Mode. */
                  Adafruit_BMP280::SAMPLING_X2, /* Temp. oversampling */
                  Adafruit_BMP280::SAMPLING_X16, /* Pressure oversampling */
                  Adafruit_BMP280::FILTER_X16, /* Filtering. */
                  Adafruit_BMP280::STANDBY_MS_500); /* Standby time. */
  // pinMode(pinout, OUTPUT);
  pinMode(18, 0x02);
  pinMode(19, 0x05);
  Serial.println(((reinterpret_cast<const __FlashStringHelper *>(("BMP280 test")))));
  //  digitalWrite(scr_trig, LOW);
  //  attachInterrupt(digitalPinToInterrupt(ZERODETECTPIN), ZC_detect, FALLING);       // Enable external interrupt (INT0)
  attachInterrupt(19, ZC_detect, 0x02); // Enable external interrupt (INT0)
  // attachInterrupt(sync, ZC_detect, FALLING);
}

void loop()
{

  if (ZC) {
    delayMicroseconds(alpha);
    digitalWrite(18, 0x1);
    delay(1);
    digitalWrite(18, 0x0);
    ZC = 0;
    t++;
  }
  //Serial.println(t);
  alpha = 4000;
 } void dd() {

  /*

    Serial.print(F("Temperature = "));

    Serial.print(bmp.readTemperature());

    Serial.println(" *C\t"+String(t));

  */
# 115 "h:\\prosjekter\\varmeskap\\arduino\\varmeskap\\varmeskap.ino"
  display.clearDisplay();

  display.setTextSize(3);
  display.setTextColor(1 /*|< Draw 'on' pixels*/ /*|< Draw 'on' pixels*/);
  display.setCursor(5, 0);
  display.print("Temp: ");
  display.setCursor(0, 30);
  display.print(bmp.readTemperature());// + "'C");
 // display.display();
 //   } void dd() {
  Temp = round(bmp.readTemperature());
  //  } void dd() {
  /*  if (Temp > Satt_temp)

      alpha = 0;

    else

      alpha = map(Temp, Satt_temp - 30, Satt_temp, Max_strom, 0);

    /

    //Temp=40;

    // delay(2000);

    if ((ValgtTemp - Temp) > 0)

    alpha = map(ValgtTemp - Temp, 0, 70, 10000, 1000);

    else

    alpha = 10000;

    Serial.println("Temp: " + String(Temp) + '\t' + String(ValgtTemp - Temp) + "\talpha: " + String(alpha) + "\t" + String(constrain(alpha, 255, 0)));

  */
# 141 "h:\\prosjekter\\varmeskap\\arduino\\varmeskap\\varmeskap.ino"
}
# 1 "h:\\prosjekter\\varmeskap\\arduino\\varmeskap\\varmeskap1.ino"
/***************************************************************************

  Denne skissen leer tempraturen fra en BMP280, koblet til en Wemos mini32 D1 microkontroller

  I2C adresse BMP280 :0x76

  0-deteksjon kobles til port  IO19

  thyristor-styringen skjer fra port  IO18





***************************************************************************/
# 9 "h:\\prosjekter\\varmeskap\\arduino\\varmeskap\\varmeskap1.ino"
#define pinout 14 /*GPIO14, D5*/
int Temp, ValgtTemp = 34;
int val;
int Satt_temp = 40;
//int Max_temp = 60;
int Max_strom = 255;
int t = 0;

#define scr_trig 18
#define pot A0
#define ZERODETECTPIN 19
#define sync 19

bool ZC = 0;
uint16_t alpha;

# 26 "h:\\prosjekter\\varmeskap\\arduino\\varmeskap\\varmeskap1.ino" 2
# 27 "h:\\prosjekter\\varmeskap\\arduino\\varmeskap\\varmeskap1.ino" 2

# 29 "h:\\prosjekter\\varmeskap\\arduino\\varmeskap\\varmeskap1.ino" 2
# 30 "h:\\prosjekter\\varmeskap\\arduino\\varmeskap\\varmeskap1.ino" 2

#define SCREEN_WIDTH 128 /* OLED display width, in pixels*/
#define SCREEN_HEIGHT 64 /* OLED display height, in pixels*/

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET 4 /* Reset pin # (or -1 if sharing Arduino reset pin)*/
Adafruit_SSD1306 display(128 /* OLED display width, in pixels*/, 64 /* OLED display height, in pixels*/, &Wire, 4 /* Reset pin # (or -1 if sharing Arduino reset pin)*/);

#define BMP_SCK (13)
#define BMP_MISO (12)
#define BMP_MOSI (11)
#define BMP_CS (10)

Adafruit_BMP280 bmp; // I2C
//Adafruit_BMP280 bmp(BMP_CS); // hardware SPI
//Adafruit_BMP280 bmp(BMP_CS, BMP_MOSI, BMP_MISO,  BMP_SCK);
portMUX_TYPE synch = { .owner = 0xB33FFFFF, .count = 0, };

void __attribute__((section(".iram1" "." "17"))) ZC_detect()
{
    vTaskEnterCritical(&synch);
    ZC = 1;
    vTaskExitCritical($synch)
}

void setup()
{
    Serial.begin(115200);
    Serial.println("h:\\prosjekter\\varmeskap\\arduino\\varmeskap\\varmeskap1.ino");
    Serial.print("Kompilert: ");
    Serial.print("Fri Sep 03 15:29:31 2021");
    Serial.println(" Versjon: 1.0.0");

    if (!display.begin(0x02 /*|< Gen. display voltage from 3.3V*/, 0x3C))
    { // Address 0x3D for 128x64
        Serial.println(((reinterpret_cast<const __FlashStringHelper *>(("SSD1306 allocation failed")))));
        for (;;)
            ; // Don't proceed, loop forever
    };


    ledcAttachPin(14 /*GPIO14, D5*/, 1);

    if (!bmp.begin(0x76))
    {
        Serial.println(((reinterpret_cast<const __FlashStringHelper *>(("Could not find a valid BMP280 sensor, check wiring!")))));
        while (1)
            ;
    }

    /* Default settings from datasheet. */
    bmp.setSampling(Adafruit_BMP280::MODE_NORMAL, /* Operating Mode. */
                    Adafruit_BMP280::SAMPLING_X2, /* Temp. oversampling */
                    Adafruit_BMP280::SAMPLING_X16, /* Pressure oversampling */
                    Adafruit_BMP280::FILTER_X16, /* Filtering. */
                    Adafruit_BMP280::STANDBY_MS_500); /* Standby time. */
    // pinMode(pinout, OUTPUT);
    pinMode(18, 0x02);
    pinMode(19, 0x05);
    Serial.println(((reinterpret_cast<const __FlashStringHelper *>(("BMP280 test")))));
    //  digitalWrite(scr_trig, LOW);
    //  attachInterrupt(digitalPinToInterrupt(ZERODETECTPIN), ZC_detect, FALLING);       // Enable external interrupt (INT0)
    attachInterrupt(19, ZC_detect, 0x02); // Enable external interrupt (INT0)
                                                        // attachInterrupt(sync, ZC_detect, FALLING);
}

void loop()
{

    if (ZC)
    {
        delayMicroseconds(alpha);
        digitalWrite(18, 0x1);
        delay(1);
        digitalWrite(18, 0x0);
        ZC = 0;
        t++;
    }
    //Serial.println(t);
    alpha = 4000;
}
void ddl()
{

    /*

    Serial.print(F("Temperature = "));

    Serial.print(bmp.readTemperature());

    Serial.println(" *C\t"+String(t));

  */
# 120 "h:\\prosjekter\\varmeskap\\arduino\\varmeskap\\varmeskap1.ino"
    display.clearDisplay();

    display.setTextSize(3);
    display.setTextColor(1 /*|< Draw 'on' pixels*/ /*|< Draw 'on' pixels*/);
    display.setCursor(5, 0);
    display.print("Temp: ");
    display.setCursor(0, 30);
    display.print(bmp.readTemperature()); // + "'C");
                                          // display.display();
                                          //   } void dd() {
    Temp = round(bmp.readTemperature());
    //  } void dd() {
    /*  if (Temp > Satt_temp)

      alpha = 0;

    else

      alpha = map(Temp, Satt_temp - 30, Satt_temp, Max_strom, 0);

    /

    //Temp=40;

    // delay(2000);

    if ((ValgtTemp - Temp) > 0)

    alpha = map(ValgtTemp - Temp, 0, 70, 10000, 1000);

    else

    alpha = 10000;

    Serial.println("Temp: " + String(Temp) + '\t' + String(ValgtTemp - Temp) + "\talpha: " + String(alpha) + "\t" + String(constrain(alpha, 255, 0)));

  */
# 145 "h:\\prosjekter\\varmeskap\\arduino\\varmeskap\\varmeskap1.ino"
}
