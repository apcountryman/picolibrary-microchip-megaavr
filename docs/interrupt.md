# Interrupt Facilities
Microchip megaAVR interrupt facilities are defined in the
[`include/picolibrary/microchip/megaavr/interrupt.h`](https://github.com/apcountryman/picolibrary-microchip-megaavr/blob/main/include/picolibrary/microchip/megaavr/interrupt.h)/[`source/picolibrary/microchip/megaavr/interrupt.cc`](https://github.com/apcountryman/picolibrary-microchip-megaavr/blob/main/source/picolibrary/microchip/megaavr/interrupt.cc)
header/source file pair.

## Table of Contents
1. [Controller](#controller)

## Controller
The `::picolibrary::Microchip::megaAVR::Interrupt::Controller` class implements an
interrupt controller interface for interacting with the Microchip megaAVR global interrupt
enable.
See the [`::picolibrary::Interrupt::Controller_Concept`
documentation](https://apcountryman.github.io/picolibrary/interrupt.html#controller) for
more information.
