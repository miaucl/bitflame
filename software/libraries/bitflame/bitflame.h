/*
  bitflame.h - Bitflame generator functions
  Created by Cyrill Lippuner, 2020.
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
