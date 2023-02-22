# I<sup>2</sup>C Facilities
Microchip megaAVR I<sup>2</sup>C facilities are defined in the
[`include/picolibrary/microchip/megaavr/i2c.h`](https://github.com/apcountryman/picolibrary-microchip-megaavr/blob/main/include/picolibrary/microchip/megaavr/i2c.h)/[`source/picolibrary/microchip/megaavr/i2c.cc`](https://github.com/apcountryman/picolibrary-microchip-megaavr/blob/main/source/picolibrary/microchip/megaavr/i2c.cc)
header/source file pair.

## Table of Contents
1. [Controller](#controller)

## Controller
The `::picolibrary::Microchip::megaAVR::I2C::Basic_Controller` class implements an
I<sup>2</sup>C basic controller interface for interacting with a Microchip megaAVR TWI
peripheral.
See the [`::picolibrary::I2C::Basic_Controller_Concept`
documentation](https://apcountryman.github.io/picolibrary/i2c.html#controller) for more
information.

The `::picolibrary::Microchip::megaAVR::I2C::Controller` type alias adds I<sup>2</sup>C
controller functionality to `::picolibrary::Microchip::megaAVR::I2C::Basic_Controller`.
See the [`::picolibrary::I2C::Controller_Concept`
documentation](https://apcountryman.github.io/picolibrary/i2c.html#controller) for more
information.
The `::picolibrary::Microchip::megaAVR::I2C::Controller` scan interactive test is defined
in the
[`test/interactive/picolibrary/microchip/megaavr/i2c/controller/scan/main.cc`](https://github.com/apcountryman/picolibrary-microchip-megaavr/blob/main/test/interactive/picolibrary/microchip/megaavr/i2c/controller/scan/main.cc)
source file.
