#include "bitflame.h"
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_IS31FL3731.h>

#define WIDTH 15
#define HEIGHT 7

#define HEAT 0.2f
#define CO2 0.03f
#define CINDER 1

#define PERIOD 100 //ms

#define MAX_INTESITY 80 // of 0-255

Bitflame<HEIGHT, WIDTH> bitflame;

Adafruit_IS31FL3731_Wing ledmatrix = Adafruit_IS31FL3731_Wing();


// Last timestamp
long t = 0;

void setup()
{
  Serial.begin(9600);

  // Set parameters
  bitflame.setBitflameHeat(HEAT);
  bitflame.setBitflameCO2(CO2);
  bitflame.setBitflameCinder(CINDER);

  // Init matrix
  bitflame.init();


  // Init LED Matrix
  if (! ledmatrix.begin())
  {
    Serial.println("IS31 not found");
    while (1);
  }

  // Init led 13
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);

  // Ready
  printBitflame();
  t = millis();
}

void printBitflame()
{
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));

  for (int y = 0; y<HEIGHT; y++)
  {
    for (int x = 0; x<WIDTH; x++)
    {
      ledmatrix.drawPixel(x, y, (int)(bitflame.getFadedValue(y, x) * MAX_INTESITY));
    }
  }
}


void loop()
{
  bitflame.next();
  printBitflame();
  int d = millis() - t;
  Serial.println(d);
  if (d < PERIOD) delay(PERIOD - d); // Wait if needed
  t = millis();
}
