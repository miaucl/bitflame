#include "bitflame.h"

#define WIDTH 10
#define HEIGHT 10

#define HEAT 0.2f
#define CO2 0.02f
#define CINDER 1
#define FADE 1

#define MONITOR_LINE_HEIGHT 60 // Change this value if you see the old images scrolling up

Bitflame<HEIGHT, WIDTH> bitflame;

void setup()
{
  Serial.begin(9600);

  while (!Serial) { ; /* wait for serial port to connect. Needed for native USB port only */ }

  Serial.println("Initialize <bitflame> example…");

  // Set parameters
  bitflame.setBitflameHeat(HEAT);
  bitflame.setBitflameCO2(CO2);
  bitflame.setBitflameCinder(CINDER);
  Serial.println("Parameters:");
  Serial.print("\t HEAT: ");
  Serial.println(bitflame.getBitflameHeat(), 4);
  Serial.print("\t CO2: ");
  Serial.println(bitflame.getBitflameCO2(), 4);
  Serial.print("\t CINDER: ");
  Serial.println(bitflame.getBitflameCinder());

  // Init matrix
  bitflame.init();
  Serial.println("Size:");
  Serial.print("\t HEIGHT: ");
  Serial.println(HEIGHT);
  Serial.print("\t WIDTH: ");
  Serial.println(WIDTH);

  // Ready
  while (Serial.available() > 0) Serial.read(); // Flush
  Serial.println();
  Serial.println("Ready, waiting for user input to start…");
  while (Serial.available() == 0) ; // Wait
  while (Serial.available() > 0) Serial.read(); // Flush
  Serial.println("Go!");
  delay(1000);
  printBitflame();
}

void printBitflame()
{
  for (int i = 0; i<MONITOR_LINE_HEIGHT; i++) Serial.println();

  for (int y = 0; y<HEIGHT; y++)
  {
    for (int x = 0; x<WIDTH; x++)
    {
      Serial.print(bitflame.getValue(y, x) ? "x" : ".");
    }
    Serial.println();
  }
  Serial.println();
}

void printBitflameFaded()
{
  for (int i = 0; i<MONITOR_LINE_HEIGHT; i++) Serial.println();

  for (int y = 0; y<HEIGHT; y++)
  {
    for (int x = 0; x<WIDTH; x++)
    {
      double v = bitflame.getFadedValue(y, x);
      if (v > 0.6) Serial.print("* ");
      else if (v > 0.3) Serial.print("- ");
      else if (v > 0.0) Serial.print(". ");
      else Serial.print("  ");
    }
    Serial.println();
  }
  Serial.println();
}

void loop()
{
  Serial.println("Ready, waiting for user input for next frame…");
  while (Serial.available() == 0) ; // Wait
  while (Serial.available() > 0) Serial.read(); // Flush
  bitflame.next();
  if (FADE) printBitflameFaded();
  else printBitflame();
}
