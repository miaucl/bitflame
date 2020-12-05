#include "bitflame.h"
#include <MdLep16X16.h>

#define WIDTH 16
#define HEIGHT 16

#define HEAT 0.2f
#define CO2 0.015f
#define CINDER 2

#define PERIOD 100 //ms

Bitflame<HEIGHT, WIDTH> bitflame;

MdLep16X16 mdLep(0xFF, 0xFF, 0xFF, 0xFF);


uint16_t screen[16] = { 0 };

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
  mdLep.init();
  delay(100);
  mdLep.displayOn();
  mdLep.invertOff();
  mdLep.mirrorOn();
  delay(100);
  mdLep.turnOff();
  delay(100);
  mdLep.fillGram(0xFF);
  delay(100);

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
    uint16_t row = 0x0000;
    for (int x = 0; x<WIDTH; x++)
    {
      if (bitflame.getValue(y, x))
      {
        // Make sure the first byte is at the left and the MSB is (0,0)
        if (x < WIDTH / 2) row |= (1 << ((WIDTH / 2) - x - 1));
        else row |= (1 << ((WIDTH * 3 / 2) - x - 1));
      }
    }

    screen[y] = row;
  }

  // Cast the 16 times 2-byte array to a 32 times 1-byte array.
  mdLep.loadScreen((byte*) &screen);
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
