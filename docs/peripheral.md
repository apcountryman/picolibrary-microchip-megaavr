# Peripheral Facilities

## Table of Contents
1. [Peripherals](#peripherals)
    1. [PORT](#port)
    1. [SPI](#spi)
    1. [TWI](#twi)
    1. [USART](#usart)
1. [Peripheral Instances](#peripheral-instances)
    1. [ATmega328/P](#atmega328p)
    1. [ATmega2560](#atmega2560)

## Peripherals
The layout of each Microchip megaAVR peripheral's registers is defined by the class named
after the peripheral (e.g. the layout of the SPI peripheral's registers is defined by the
`::picolibrary::Microchip::megaAVR::Peripheral::SPI` class).
Peripheral registers are accessed via the member variables named after the registers (e.g.
the SPI peripheral's SPCR register is accessed via the
`::picolibrary::Microchip::megaAVR::Peripheral::SPI::spcr` member variable).
Peripheral register information is defined in member classes named after the registers
(e.g. SPI peripheral SPCR register information is defined in the
`::picolibrary::Microchip::megaAVR::Peripheral::SPI::SPCR` member class).
Peripheral register field constants are defined in the following member structures:
- `Size`: field sizes (e.g. the size of the SPR field of the SPI peripheral's SPCR
  register is defined by the
  `::picolibrary::Microchip::megaAVR::Peripheral::SPI::SPCR::Size::SPR` constant)
- `Bit`: field bit positions (e.g. the position of the SPR field of the SPI peripheral's
  SPCR register is defined by the
  `::picolibrary::Microchip::megaAVR::Peripheral::SPI::SPCR::Bit::SPR` constant)
- `Mask`: field bit masks (e.g. the mask for the SPR field of the SPI peripheral's SPCR
  register is defined by the
  `::picolibrary::Microchip::megaAVR::Peripheral::SPI::SPCR::Mask::SPR` constant)

### PORT
The `::picolibrary::Microchip::megaAVR::Peripheral::PORT` class defines the layout of the
Microchip megaAVR PORT peripheral.
The `::picolibrary::Microchip::megaAVR::Peripheral::PORT` class is defined in the
[`include/picolibrary/microchip/megaavr/peripheral/port.h`](https://github.com/apcountryman/picolibrary-microchip-megaavr/blob/main/include/picolibrary/microchip/megaavr/peripheral/port.h)/[`source/picolibrary/microchip/megaavr/peripheral/port.cc`](https://github.com/apcountryman/picolibrary-microchip-megaavr/blob/main/source/picolibrary/microchip/megaavr/peripheral/port.cc)
header/source file pair.

### SPI
The `::picolibrary::Microchip::megaAVR::Peripheral::SPI` class defines the layout of the
Microchip megaAVR SPI peripheral and information about its registers.
The `::picolibrary::Microchip::megaAVR::Peripheral::SPI` class is defined in the
[`include/picolibrary/microchip/megaavr/peripheral/spi.h`](https://github.com/apcountryman/picolibrary-microchip-megaavr/blob/main/include/picolibrary/microchip/megaavr/peripheral/spi.h)/[`source/picolibrary/microchip/megaavr/peripheral/spi.cc`](https://github.com/apcountryman/picolibrary-microchip-megaavr/blob/main/source/picolibrary/microchip/megaavr/peripheral/spi.cc)
header/source file pair.

### TWI
The `::picolibrary::Microchip::megaAVR::Peripheral::TWI` class defines the layout of the
Microchip megaAVR TWI peripheral and information about its registers.
The `::picolibrary::Microchip::megaAVR::Peripheral::TWI` class is defined in the
[`include/picolibrary/microchip/megaavr/peripheral/twi.h`](https://github.com/apcountryman/picolibrary-microchip-megaavr/blob/main/include/picolibrary/microchip/megaavr/peripheral/twi.h)/[`source/picolibrary/microchip/megaavr/peripheral/twi.cc`](https://github.com/apcountryman/picolibrary-microchip-megaavr/blob/main/source/picolibrary/microchip/megaavr/peripheral/twi.cc)
header/source file pair.

### USART
The `::picolibrary::Microchip::megaAVR::Peripheral::USART` class defines the layout of the
Microchip megaAVR USART peripheral and information about its registers.
The `::picolibrary::Microchip::megaAVR::Peripheral::USART` class is defined in the
[`include/picolibrary/microchip/megaavr/peripheral/usart.h`](https://github.com/apcountryman/picolibrary-microchip-megaavr/blob/main/include/picolibrary/microchip/megaavr/peripheral/usart.h)/[`source/picolibrary/microchip/megaavr/peripheral/usart.cc`](https://github.com/apcountryman/picolibrary-microchip-megaavr/blob/main/source/picolibrary/microchip/megaavr/peripheral/usart.cc)
header/source file pair.

The `::picolibrary::Microchip::megaAVR::Peripheral::USART` class has a different structure
than other Microchip megaAVR peripheral classes due to the Microchip megaAVR USART
peripheral's multiple operating modes (normal mode and SPI host mode).
Classes and variables that would be members of the
`::picolibrary::Microchip::megaAVR::Peripheral::USART` class are instead members of the
`::picolibrary::Microchip::megaAVR::Peripheral::USART::Normal` and
`::picolibrary::Microchip::megaAVR::Peripheral::USART::SPI_Host` member classes.
A USART peripheral's `::picolibrary::Microchip::megaAVR::Peripheral::USART::Normal`
instance is accessed via the
`::picolibrary::Microchip::megaAVR::Peripheral::USART::normal` member variable.
A USART peripheral's `::picolibrary::Microchip::megaAVR::Peripheral::USART::SPI_Host`
instance is accessed via the
`::picolibrary::Microchip::megaAVR::Peripheral::USART::spi_host` member variable.

## Peripheral Instances
Microchip megaAVR MCU specific peripheral instances are defined in MCU specific namespaces
and header/source file pairs (e.g. ATmega2560 peripheral instances are defined in the
`::picolibrary::Microchip::megaAVR::Peripheral::ATmega2560` namespace which is defined in
the
[`include/picolibrary/microchip/megaavr/peripheral/atmega2560.h`](https://github.com/apcountryman/picolibrary-microchip-megaavr/blob/main/include/picolibrary/microchip/megaavr/peripheral/atmega2560.h)/[`source/picolibrary/microchip/megaavr/peripheral/atmega2560.cc`](https://github.com/apcountryman/picolibrary-microchip-megaavr/blob/main/source/picolibrary/microchip/megaavr/peripheral/atmega2560.cc)
header/source file pair).
Peripheral instance definitions for the active MCU type are imported into the
`::picolibrary::Microchip::megaAVR::Peripheral` namespace and can be accessed via the
[`include/picolibrary/microchip/megaavr/peripheral.h`](https://github.com/apcountryman/picolibrary-microchip-megaavr/blob/main/include/picolibrary/microchip/megaavr/peripheral.h)
header file.

### ATmega328/P
Microchip ATmega328/P peripheral instances are defined in the
[`include/picolibrary/microchip/megaavr/peripheral/atmega328p.h`](https://github.com/apcountryman/picolibrary-microchip-megaavr/blob/main/include/picolibrary/microchip/megaavr/peripheral/atmega328p.h)/[`source/picolibrary/microchip/megaavr/peripheral/atmega328p.cc`](https://github.com/apcountryman/picolibrary-microchip-megaavr/blob/main/source/picolibrary/microchip/megaavr/peripheral/atmega328p.cc)
header/source file pair.
The following peripheral instances are defined (listed alphabetically):
- `::picolibrary::Microchip::megaAVR::Peripheral::ATmega328P::PORTB`
- `::picolibrary::Microchip::megaAVR::Peripheral::ATmega328P::PORTC`
- `::picolibrary::Microchip::megaAVR::Peripheral::ATmega328P::PORTD`
- `::picolibrary::Microchip::megaAVR::Peripheral::ATmega328P::SPI0`
- `::picolibrary::Microchip::megaAVR::Peripheral::ATmega328P::TWI0`
- `::picolibrary::Microchip::megaAVR::Peripheral::ATmega328P::USART0`

### ATmega2560
Microchip ATmega2560 peripheral instances are defined in the
[`include/picolibrary/microchip/megaavr/peripheral/atmega2560.h`](https://github.com/apcountryman/picolibrary-microchip-megaavr/blob/main/include/picolibrary/microchip/megaavr/peripheral/atmega2560.h)/[`source/picolibrary/microchip/megaavr/peripheral/atmega2560.cc`](https://github.com/apcountryman/picolibrary-microchip-megaavr/blob/main/source/picolibrary/microchip/megaavr/peripheral/atmega2560.cc)
header/source file pair.
The following peripheral instances are defined (listed alphabetically):
- `::picolibrary::Microchip::megaAVR::Peripheral::ATmega2560::PORTA`
- `::picolibrary::Microchip::megaAVR::Peripheral::ATmega2560::PORTB`
- `::picolibrary::Microchip::megaAVR::Peripheral::ATmega2560::PORTC`
- `::picolibrary::Microchip::megaAVR::Peripheral::ATmega2560::PORTD`
- `::picolibrary::Microchip::megaAVR::Peripheral::ATmega2560::PORTE`
- `::picolibrary::Microchip::megaAVR::Peripheral::ATmega2560::PORTF`
- `::picolibrary::Microchip::megaAVR::Peripheral::ATmega2560::PORTG`
- `::picolibrary::Microchip::megaAVR::Peripheral::ATmega2560::PORTH`
- `::picolibrary::Microchip::megaAVR::Peripheral::ATmega2560::PORTJ`
- `::picolibrary::Microchip::megaAVR::Peripheral::ATmega2560::PORTK`
- `::picolibrary::Microchip::megaAVR::Peripheral::ATmega2560::PORTL`
- `::picolibrary::Microchip::megaAVR::Peripheral::ATmega2560::SPI0`
- `::picolibrary::Microchip::megaAVR::Peripheral::ATmega2560::TWI0`
- `::picolibrary::Microchip::megaAVR::Peripheral::ATmega2560::USART0`
- `::picolibrary::Microchip::megaAVR::Peripheral::ATmega2560::USART1`
- `::picolibrary::Microchip::megaAVR::Peripheral::ATmega2560::USART2`
- `::picolibrary::Microchip::megaAVR::Peripheral::ATmega2560::USART3`
