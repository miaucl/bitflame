/*
 * Test Pattern and some Codesamples, for 16x16 Matrices only.
 *
 * 2018 D. Puppetti / PLAY-ZONE GmbH
 *
 * info@play-zone.ch / https://www.play-zone.ch
 *
 */

#include <MdLep16X16.h>

byte logo[32]=
{
  0x00,0x00,
  0x22,0x78,
  0x36,0x44,
  0x2A,0x44,
  0x22,0x44,
  0x22,0x44,
  0x22,0x78,
  0x00,0x00,
  0x87,0xDF,
  0x84,0x11,
  0x84,0x11,
  0x87,0x91,
  0x84,0x1F,
  0x84,0x10,
  0xF7,0xD0,
  0x00,0x00
};

MdLep16X16 mdLep(0xFF, 0xFF, 0xFF, 0xFF);
byte count =0;

void setup() {
   mdLep.init();
}

void loop() {
  mdLep.loadScreen(logo);//
  delay(1000);

  mdLep.displayOn();
  delay(1000);
  mdLep.displayOff();
  delay(1000);

  mdLep.invertOn();
  delay(1000);
  mdLep.invertOff();
  delay(1000);

  mdLep.mirrorOn();
  delay(1000);
  mdLep.mirrorOff();
  delay(1000);

  mdLep.turnOn();
  delay(1000);
  mdLep.turnOff();
  delay(1000);

  mdLep.fillGram(0xFF);
  delay(1000);
  mdLep.fillGram(0x00);
  delay(1000);

  mdLep.drawPixel(2,3);
  delay(1000);
  mdLep.drawPixel(3,4);
  delay(1000);
  mdLep.clearPixel(2,3);
  delay(1000);
  mdLep.clearPixel(3,4);
  delay(1000);


  mdLep.showASCII(3,8,'M');
  delay(1000);
  mdLep.showASCII(9,8,'D');
  delay(1000);
  mdLep.showASCII(0,0,'L');
  delay(1000);
  mdLep.showASCII(5,0,'E');
  delay(1000);
  mdLep.showASCII(11,0,'P');
  delay(1000);

  mdLep.fillGram(0x00);
  delay(1000);
}
