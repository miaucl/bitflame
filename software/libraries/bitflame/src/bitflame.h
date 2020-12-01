/*
  bitflame.h - Bitflame generator functions
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


#ifndef Bitflame_h
#define Bitflame_h

template <int HEIGHT, int WIDTH>
class Bitflame
{
private:
  /**
   * The matrix with the values
   */
  double mat[HEIGHT][WIDTH] = { 0 };

  /**
   * The heat parameter
   */
  double heat = 0.2;
  /**
   * The oxygen parameter
   */
  double oxy = 0.002;
  /**
   * The cinder parameter
   */
  int cinder = 3;


public:
  /**
   * Constructor
   */
  Bitflame();

  /**
   * Get heat parameter
   */
  double getBitflameHeat();

  /**
   * Set heat parameter ">=0"
   */
  void setBitflameHeat(double _heat);

  /**
   * Get oxy parameter
   */
  double getBitflameOxy();

  /**
   * Set oxy parameter ">=0"
   */
  void setBitflameOxy(double oxy);

  /**
   * Get cinder parameter
   */
  int getBitflameCinder();

  /**
   * Set cinder parameter ">=1"
   */
  void setBitflameCinder(int _cinder);


  /**
   * Init the matrix with origin top left
   */
  void init();

  /**
   * Next step of the matrix with origin top left
   */
  void next();

  /**
   * Get a value at a certain position
   */
  double getValue(int y, int x);

};

#include "bitflame.ipp"



#endif
