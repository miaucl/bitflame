/*
 * Displays a simple Text-Pattern on 32x16 / 16x16 Matrices
 *
 * 2018 D. Puppetti / PLAY-ZONE GmbH
 *
 * info@play-zone.ch / https://www.play-zone.ch
 *
 */

#include <MdLep16X16.h>

MdLep16X16 mdLep(0xFF, 0xFF, 0xFF, 0xFF);// Current 1.3 Boards always init with 0xFF

void setup() {
  mdLep.init();
  mdLep.fillGram(0x00);
  delay(100);
}
void loop() {
  mdLep.fillGram(0x00);
  delay(1000);
  mdLep.fillGram(0xaa);
  delay(1000);
  mdLep.fillGram(0x55);
  delay(1000);
  mdLep.fillGram(0xff);
  delay(2000);
}
