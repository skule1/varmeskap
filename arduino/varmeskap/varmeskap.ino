/***************************************************************************
  Denne skissen leer tempraturen fra en BMP280, koblet til en Wemos mini32 D1 microkontroller
  I2C adresse BMP280 :0x76
  0-deteksjon kobles til port INT0
  thyristor-styringen skjer fra port 8


***************************************************************************/
#define pinout  14  //GPIO14, D5
int Temp;
int val;
int Satt_temp = 40;
//int Max_temp = 60;
int Max_strom=255;

#define scr_trig   8
#define pot       A0
#define ZERODETECTPIN       0

bool ZC = 0;
uint16_t alpha;

#include <Wire.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_BMP280.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64// OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define BMP_SCK  (13)
#define BMP_MISO (12)
#define BMP_MOSI (11)
#define BMP_CS   (10)

Adafruit_BMP280 bmp; // I2C
//Adafruit_BMP280 bmp(BMP_CS); // hardware SPI
//Adafruit_BMP280 bmp(BMP_CS, BMP_MOSI, BMP_MISO,  BMP_SCK);

void ZC_detect() {
  ZC = 1;
}

void setup() {
  Serial.begin(115200);
   Serial.println(__FILE__);
  Serial.print("Kompilert: "); Serial.print(__TIMESTAMP__);
Serial.println(" Versjon: 1.0.0");
  Serial.println(F("BMP280 test"));

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Don't proceed, loop forever
  };

#ifdef ESP32
  ledcAttachPin(pinout, 1);
#endif
  if (!bmp.begin(0x76)) {
    Serial.println(F("Could not find a valid BMP280 sensor, check wiring!"));
    while (1);
  }

  /* Default settings from datasheet. */
  bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,     /* Operating Mode. */
                  Adafruit_BMP280::SAMPLING_X2,     /* Temp. oversampling */
                  Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */
                  Adafruit_BMP280::FILTER_X16,      /* Filtering. */
                  Adafruit_BMP280::STANDBY_MS_500); /* Standby time. */
  pinMode(pinout, OUTPUT);
  pinMode(scr_trig, OUTPUT);
  pinMode(ZERODETECTPIN, INPUT);
  digitalWrite(scr_trig, LOW);
  //  attachInterrupt(digitalPinToInterrupt(ZERODETECTPIN), ZC_detect, FALLING);       // Enable external interrupt (INT0)
  attachInterrupt(ZERODETECTPIN, ZC_detect, FALLING);       // Enable external interrupt (INT0)

}

void loop() {
  if (ZC) {
    delayMicroseconds(alpha);
    digitalWrite(scr_trig, HIGH);
    delay(1);
    digitalWrite(scr_trig, LOW);
    ZC = 0;
    /*    alpha = analogRead(pot) * 10;
        if(alpha > 10000)
          alpha = 10000;*/
  }

  Serial.print(F("Temperature = "));
  Serial.print(bmp.readTemperature());
  Serial.println(" *C");

  display.clearDisplay();
  display.setTextSize(3);
  display.setTextColor(WHITE);
  display.setCursor(5, 0);
  display.print("Temp: ");
  display.setCursor(0, 30);
  display.print(String(bmp.readTemperature()) + "'C");
  display.display();

  Serial.println();
  Temp = round( bmp.readTemperature());
  if (Temp > Satt_temp)
    alpha = 0;
  else
    alpha = map(Temp, Satt_temp - 30, Satt_temp, Max_strom, 0);

  Serial.println("Temp: " + String(Temp) + "\talpha: " + String(alpha) + "\t" + String( constrain(alpha, 255, 0)));

  delay(2000);

}
