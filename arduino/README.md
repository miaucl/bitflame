# bitflame – C++

The `C++` implementation is provided as an _Arduino Library_.

It is independent of any underlying hardware, but for the examples an _Arduino MICRO_ was used.

For more information about the algorithm itself, please have a look at the _Python_ notebook.

## Setup

Download and build an example using the standard Arduino IDE. There are 3 different examples:

* A _step_by_step_ example which uses the serial console as display.
* A _auto_loop_ example which uses the serial console as display.
* A _16x16_matrix_uart_ example which uses a 16x16 matrix controlled by UART.


### Dependencies

The dependency `UART-Matrix` in the libraries folder is only needed for the example _16x16_matrix_uart_.


### Docs

The library contains a single _class_ `Bitflame` which handles one screen.

#### Instance

The class is a template and you have to provide the _WIDTH_ and _HEIGHT_ of the matrix.

```c++
#define WIDTH 16
#define HEIGHT 16

Bitflame<HEIGHT, WIDTH> bitflame;
```

#### Parameters

Usually you would like to change the parameters of the instance. Set the _HEAT_, _CO2_ and _CINDER_ as following:

```c++
#define HEAT 0.2f
#define CO2 0.015f
#define CINDER 2

bitflame.setBitflameHeat(HEAT);
bitflame.setBitflameCO2(CO2);
bitflame.setBitflameCinder(CINDER);
```

and read it like:

```c++
double current_heat = bitflame.getBitflameHeat(HEAT);
double current_co2 = bitflame.getBitflameCO2(CO2);
int current_cinder = bitflame.getBitflameCinder(CINDER);
```

#### Initialize

To initialize (or reset) the matrix, you can use following method:

```c++
bitflame.init();
```


#### Interate

To iterate and calculate the next step, use following function:

```c++
bitflame.step();
```


#### Get values

The values can be read one-by-one as boolean
```c++
boolean v = bitflame.getValue(y, x);
```

or as faded (which takes more time to calculate)
```c++
double v = bitflame.getFadedValue(y, x);
```

where `0<=y<HEIGHT` and `0<=x<WIDTH`.
