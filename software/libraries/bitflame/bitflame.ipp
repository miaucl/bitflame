/*
  bitflame.ipp - Bitflame generator functions
  Created by Cyrill Lippuner, 2020.
*/

#include "Arduino.h"

#define RAND_0_1 (random(0, 10000) / 10000.0)

template <int HEIGHT, int WIDTH> Bitflame<HEIGHT, WIDTH>::Bitflame()
{
  this->init();
}

template <int HEIGHT, int WIDTH> double Bitflame<HEIGHT, WIDTH>::getBitflameHeat() { return this->heat; }
template <int HEIGHT, int WIDTH> void Bitflame<HEIGHT, WIDTH>::setBitflameHeat(double _heat) { this->heat = _heat; }

template <int HEIGHT, int WIDTH> double Bitflame<HEIGHT, WIDTH>::getBitflameOxy() { return this->oxy; }
template <int HEIGHT, int WIDTH> void Bitflame<HEIGHT, WIDTH>::setBitflameOxy(double _oxy) { this->oxy = _oxy; }

template <int HEIGHT, int WIDTH> int Bitflame<HEIGHT, WIDTH>::getBitflameCinder() { return this->cinder; }
template <int HEIGHT, int WIDTH> void Bitflame<HEIGHT, WIDTH>::setBitflameCinder(int _cinder) { this->cinder = _cinder; }

template <int HEIGHT, int WIDTH> void Bitflame<HEIGHT, WIDTH>::init()
{
  for (int y = 0; y<HEIGHT; y++)
  {
    for (int x = 0; x<WIDTH; x++)
    {
      if (HEIGHT - y <= cinder) this->mat[y][x] = 1;
      else this->mat[y][x] = 0;
    }
  }
}

template <int HEIGHT, int WIDTH> void Bitflame<HEIGHT, WIDTH>::next()
{
  for (int y = 0; y<HEIGHT-cinder; y++)
  {
    for (int x = 0; x<WIDTH; x++)
    {
      if (this->mat[y+1][x] == 0) this->mat[y][x] = 0;

      if (x-1 >= 0 &&    this->mat[y+1][x-1] > 0 && RAND_0_1 < heat) this->mat[y][x] = 1;
      if (               this->mat[y+1][x  ] > 0 && RAND_0_1 < heat) this->mat[y][x] = 1;
      if (x+1 < WIDTH && this->mat[y+1][x+1] > 0 && RAND_0_1 < heat) this->mat[y][x] = 1;
    }
  }

  for (int y = HEIGHT-cinder-1; y>0; y--)
  {
    for (int x = 0; x<WIDTH; x++)
    {
      if (x-1 >= 0 && this->mat[y-1][x-1] > 0 && RAND_0_1 < oxy) this->mat[y][x] = 0;
      if (x-1 >= 0 && this->mat[y  ][x-1] > 0 && RAND_0_1 < oxy) this->mat[y][x] = 0;
      if (x-1 >= 0 && this->mat[y+1][x-1] > 0 && RAND_0_1 < oxy) this->mat[y][x] = 0;

      if (this->mat[y-1][x] > 0 && RAND_0_1 < oxy) this->mat[y][x] = 0;
      if (this->mat[y+1][x] > 0 && RAND_0_1 < oxy) this->mat[y][x] = 0;

      if (x+1 < WIDTH && this->mat[y-1][x+1] > 0 && RAND_0_1 < oxy) this->mat[y][x] = 0;
      if (x+1 < WIDTH && this->mat[y  ][x+1] > 0 && RAND_0_1 < oxy) this->mat[y][x] = 0;
      if (x+1 < WIDTH && this->mat[y+1][x+1] > 0 && RAND_0_1 < oxy) this->mat[y][x] = 0;

    }
  }
}

template <int HEIGHT, int WIDTH> double Bitflame<HEIGHT, WIDTH>::getValue(int y, int x)
{
  return this->mat[y][x];
}
