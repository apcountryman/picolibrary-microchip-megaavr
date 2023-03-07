# Register Facilities
Microchip megaAVR register facilities are defined in the
[`include/picolibrary/microchip/megaavr/register.h`](https://github.com/apcountryman/picolibrary-microchip-megaavr/blob/main/include/picolibrary/microchip/megaavr/register.h)/[`source/picolibrary/microchip/megaavr/register.cc`](https://github.com/apcountryman/picolibrary-microchip-megaavr/blob/main/source/picolibrary/microchip/megaavr/register.cc)
header/source file pair.

## Table of Contents
1. [Register](#register)
1. [Reserved Register](#reserved-register)

## Register
The `::picolibrary::Microchip::megaAVR::Register` class is used to declare a Microchip
megaAVR register that is not reserved.
Register access is restricted to the following operations:
- Conversion to the underlying register type (reading the register)
- Assignment
- Bitwise AND assignment
- Bitwise OR assignment
- Bitwise XOR assignment

## Reserved Register
The `::picolibrary::Microchip::megaAVR::Reserved_Register` class is used to declare a
Microchip megaAVR reserved register.
Reserved registers cannot be accessed.
