/*
  bitflame.ipp - Bitflame generator functions
  Created by Cyrill Lippuner, 2020.
*/
/**
 MIT License

 Copyright (c) 2020 Cyrill Lippuner

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 SOFTWARE.
*/

#include "Arduino.h"

#define RAND_0_1 (random(0, 10000) / 10000.0)

template <int HEIGHT, int WIDTH> Bitflame<HEIGHT, WIDTH>::Bitflame()
{
  this->init();
}

template <int HEIGHT, int WIDTH> double Bitflame<HEIGHT, WIDTH>::getBitflameHeat() { return this->heat; }
template <int HEIGHT, int WIDTH> void Bitflame<HEIGHT, WIDTH>::setBitflameHeat(double _heat) { this->heat = _heat; }

template <int HEIGHT, int WIDTH> double Bitflame<HEIGHT, WIDTH>::getBitflameCO2() { return this->CO2; }
template <int HEIGHT, int WIDTH> void Bitflame<HEIGHT, WIDTH>::setBitflameCO2(double _CO2) { this->CO2 = _CO2; }

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
      if (x-1 >= 0 && this->mat[y-1][x-1] > 0 && RAND_0_1 < CO2) this->mat[y][x] = 0;
      if (x-1 >= 0 && this->mat[y  ][x-1] > 0 && RAND_0_1 < CO2) this->mat[y][x] = 0;
      if (x-1 >= 0 && this->mat[y+1][x-1] > 0 && RAND_0_1 < CO2) this->mat[y][x] = 0;

      if (this->mat[y-1][x] > 0 && RAND_0_1 < CO2) this->mat[y][x] = 0;
      if (this->mat[y+1][x] > 0 && RAND_0_1 < CO2) this->mat[y][x] = 0;

      if (x+1 < WIDTH && this->mat[y-1][x+1] > 0 && RAND_0_1 < CO2) this->mat[y][x] = 0;
      if (x+1 < WIDTH && this->mat[y  ][x+1] > 0 && RAND_0_1 < CO2) this->mat[y][x] = 0;
      if (x+1 < WIDTH && this->mat[y+1][x+1] > 0 && RAND_0_1 < CO2) this->mat[y][x] = 0;

    }
  }
}

template <int HEIGHT, int WIDTH> boolean Bitflame<HEIGHT, WIDTH>::getValue(int y, int x)
{
  return this->mat[y][x];
}

template <int HEIGHT, int WIDTH> double Bitflame<HEIGHT, WIDTH>::getFadedValue(int y, int x)
{
  // If empty, keep it zero
  if (!this->mat[y][x]) return 0.0;

  // Else calculate the fade value
  int a = 0;
  int v = 0;
  if (y-1 >= 0)
  {
    a++;
    if (this->mat[y-1][x]) v++;

    if (x-1 >= 0)
    {
      a++;
      if (this->mat[y-1][x-1]) v++;
    }
    if (x+1 >= 0)
    {
      a++;
      if (this->mat[y-1][x+1]) v++;
    }
  }
  if (y+1 >= 0)
  {
    a++;
    if (this->mat[y+1][x]) v++;

    if (x-1 >= 0)
    {
      a++;
      if (this->mat[y+1][x-1]) v++;
    }
    if (x+1 >= 0)
    {
      a++;
      if (this->mat[y+1][x+1]) v++;
    }
  }
  if (x-1 >= 0)
  {
    a++;
    if (this->mat[y][x-1]) v++;
  }
  if (x+1 >= 0)
  {
    a++;
    if (this->mat[y][x+1]) v++;
  }
  return ((double)v)/((double)a);
}
