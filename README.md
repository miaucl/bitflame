# bitflame

Bitflame has two parts, a simulation written in _python_ `.ipynb` to proof the concept, test and generate _GIFs_. The second part is a `C++` implementation targeting the _Arduino_ platform. It is available as _Arduino Library_ and can be imported into any project. It is a pure software library and can be adapted to any display as demonstrated in the `examples`.

* [Python](./python)
* [C++](./arduino)


## Demo

Some demo _GIFs_ create with the _Python_ notebook and _C++_. You can find all example _GIFs_ in the [media folder](media/examples).


### 16x16 Matrix UART (C++)

From examples. _(My 16x16 matrix has some dead pixels, ignore them ;))_

![Real 1](media/examples/real/16x16-matrix-uart.gif)
![Real 2](media/examples/real/7x15-IS31FL3731-high-flames.gif)
![Real 3](media/examples/real/7x15-IS31FL3731-large-flames.gif)

### GIFs from Simulation (Python)

#### Slow Flames

Standard set of parameters.

![Slow 1 (10x10)](media/examples/slow-flames/fire_heat=0.2_o2=0.05_cinder=2.gif)
![Slow 2 (20x20)](media/examples/slow-flames/fire_heat=0.2_o2=0.01_cinder=2.gif)
![Slow 3 (40x40)](media/examples/slow-flames/fire_heat=0.2_o2=0.002_cinder=3.gif)

#### Fast Flames

More noise flames, look less alive but give a nervous feeling for afar.

![Fast 1 (10x10)](media/examples/fast-flames/fire_heat=0.4_o2=0.05_cinder=2.gif)
![Fast 2 (20x20)](media/examples/fast-flames/fire_heat=0.4_o2=0.05_cinder=3.gif)
![Fast 3 (40x40)](media/examples/fast-flames/fire_heat=0.4_o2=0.04_cinder=3.gif)

#### Different Sizes

Display of variations when changing the height with different parameters.

![Size 1 (10x20)](media/examples/different-sizes/fire_10x20_heat=0.2_o2=0.05_cinder=3.gif)
![Size 2 (20x20)](media/examples/different-sizes/fire_20x20_heat=0.2_o2=0.01_cinder=3.gif)
![Size 3 (30x20)](media/examples/different-sizes/fire_30x20_heat=0.2_o2=0.003_cinder=3.gif)
![Size 4 (40x20)](media/examples/different-sizes/fire_40x20_heat=0.2_o2=0.002_cinder=3.gif)
![Size 5 (50x20)](media/examples/different-sizes/fire_50x20_heat=0.2_o2=0.0015_cinder=3.gif)
![Size 6 (60x20)](media/examples/different-sizes/fire_60x20_heat=0.2_o2=0.001_cinder=3.gif)

#### Candles

Small matrices to simulate candles.

![Candle 1 (6x3)](media/examples/candles/fire_6x3_heat=0.2_o2=0.1_cinder=2.gif)
![Candle 2 (8x4)](media/examples/candles/fire_8x4_heat=0.2_o2=0.05_cinder=2.gif)
![Candle 3 (10x6)](media/examples/candles/fire_10x6_heat=0.2_o2=0.02_cinder=3.gif)


#### Large

Some large examples with different parameters.

![Large 1 (100x100)](media/examples/large-fires/fire_100x100_heat=0.2_o2=0.001_cinder=3.gif)
![Large 2 (100x100)](media/examples/large-fires/fire_100x100_heat=0.2_o2=0.0008_cinder=3.gif)
![Large 3 (100x100)](media/examples/large-fires/fire_100x100_heat=0.2_o2=0.0005_cinder=3.gif)

#### Faded

More detailed and more calculation needed.

![Faded 1 (40x40)](media/examples/faded-flames/fire_40x40_heat=0.2_o2=0.002_cinder=3.gif)
![Faded 2 (100x100)](media/examples/faded-flames/fire_100x100_heat=0.2_o2=0.002_cinder=3.gif)
![Faded 3 (120x320)](media/examples/faded-flames/fire_120x320_heat=0.2_o2=0.0008_cinder=3.gif)

***

### Builds

Builds using this library.

#### Fire place

The _C++_ implementation has been used to create a small [Feather](https://www.adafruit.com/feather) powered fire place. The 3D print files are available on [Thingiverse](https://www.thingiverse.com/thing:4698466) together with a list of components used.

![Fire place 1](media/examples/fire-place-build/fire-place-demo-3.gif)
![Fire place 2](media/examples/fire-place-build/fire-place-on.jpeg)
![Fire place 3](media/examples/fire-place-build/fire-place-usb-powerbank.jpeg)

[Link to media folder](media/examples/fire-place-build)
