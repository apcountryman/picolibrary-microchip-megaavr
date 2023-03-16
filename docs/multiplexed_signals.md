# Multiplexed Signals Facilities
Microchip megaAVR multiplexed signals facilities are defined in the
[`include/picolibrary/microchip/megaavr/multiplexed_signals.h`](https://github.com/apcountryman/picolibrary-microchip-megaavr/blob/main/include/picolibrary/microchip/megaavr/multiplexed_signals.h)/[`source/picolibrary/microchip/megaavr/multiplexed_signals.cc`](https://github.com/apcountryman/picolibrary-microchip-megaavr/blob/main/source/picolibrary/microchip/megaavr/multiplexed_signals.cc)
header/source file pair.

## Table of Contents
1. [Namespaces](#namespaces)
1. [SPI Peripheral](#spi-peripheral)
1. [TWI Peripheral](#twi-peripheral)
1. [USART Peripheral](#usart-peripheral)

## Namespaces
Microchip megaAVR multiplexed signals facilities are defined in the following MCU specific
namespaces:
- `::picolibrary::Microchip::megaAVR::Multiplexed_Signals::ATmega328P`
- `::picolibrary::Microchip::megaAVR::Multiplexed_Signals::ATmega2560`

These facilities are defined in these namespaces for source code organization reasons.
Multiplexed Signals facilities for the active MCU type are imported into the
`::picolibrary::Microchip::megaAVR::Multiplexed_Signals` namespace.
Users should access these facilities via the
`::picolibrary::Microchip::megaAVR::Mutliplexed_Signals` namespace.

## SPI Peripheral
Microchip megaAVR SPI peripheral multiplexed signals facilities are defined in the
following MCU specific header/source file pairs:
- [`include/picolibrary/microchip/megaavr/multiplexed_signals/atmega328p/spi.h`](https://github.com/apcountryman/picolibrary-microchip-megaavr/blob/main/include/picolibrary/microchip/megaavr/multiplexed_signals/atmega328p/spi.h)/[`source/picolibrary/microchip/megaavr/multiplexed_signals/atmega328p/spi.cc`](https://github.com/apcountryman/picolibrary-microchip-megaavr/blob/main/source/picolibrary/microchip/megaavr/multiplexed_signals/atmega328p/spi.cc)
- [`include/picolibrary/microchip/megaavr/multiplexed_signals/atmega2560/spi.h`](https://github.com/apcountryman/picolibrary-microchip-megaavr/blob/main/include/picolibrary/microchip/megaavr/multiplexed_signals/atmega2560/spi.h)/[`source/picolibrary/microchip/megaavr/multiplexed_signals/atmega2560/spi.cc`](https://github.com/apcountryman/picolibrary-microchip-megaavr/blob/main/source/picolibrary/microchip/megaavr/multiplexed_signals/atmega2560/spi.cc)

These facilities are defined in these files for source code organization reasons.
Users should access these facilities via the
[`include/picolibrary/microchip/megaavr/multiplexed_signals.h`](https://github.com/apcountryman/picolibrary-microchip-megaavr/blob/main/include/picolibrary/microchip/megaavr/multiplexed_signals.h)
header file.
- To lookup an SPI peripheral's pins PORT peripheral address, use the
  `::picolibrary::Microchip::megaAVR::Multiplexed_Signals::spi_port_address()` function.
- To lookup an SPI peripheral's pins PORT peripheral, use the
  `::picolibrary::Microchip::megaAVR::Multiplexed_Signals::spi_port()` function.
- To lookup an SPI peripheral's SS pin PORT peripheral address, use the
  `::picolibrary::Microchip::megaAVR::Multiplexed_Signals::ss_port_address()` function.
- To lookup an SPI peripheral's SS pin PORT peripheral, use the
  `::picolibrary::Microchip::megaAVR::Multiplexed_Signals::ss_port()` function.
- To lookup an SPI peripheral's SS pin number, use the
  `::picolibrary::Microchip::megaAVR::Multiplexed_Signals::ss_number()` functions.
- To lookup an SPI peripheral's SS pin mask, use the
  `::picolibrary::Microchip::megaAVR::Multiplexed_Signals::ss_mask()` functions.
- To lookup an SPI peripheral's SCK pin PORT peripheral address, use the
  `::picolibrary::Microchip::megaAVR::Multiplexed_Signals::sck_port_address()` function.
- To lookup an SPI peripheral's SCK pin PORT peripheral, use the
  `::picolibrary::Microchip::megaAVR::Multiplexed_Signals::sck_port()` function.
- To lookup an SPI peripheral's SCK pin number, use the
  `::picolibrary::Microchip::megaAVR::Multiplexed_Signals::sck_number()` functions.
- To lookup an SPI peripheral's SCK pin mask, use the
  `::picolibrary::Microchip::megaAVR::Multiplexed_Signals::sck_mask()` functions.
- To lookup an SPI peripheral's MOSI pin PORT peripheral address, use the
  `::picolibrary::Microchip::megaAVR::Multiplexed_Signals::mosi_port_address()` function.
- To lookup an SPI peripheral's MOSI pin PORT peripheral, use the
  `::picolibrary::Microchip::megaAVR::Multiplexed_Signals::mosi_port()` function.
- To lookup an SPI peripheral's MOSI pin number, use the
  `::picolibrary::Microchip::megaAVR::Multiplexed_Signals::mosi_number()` functions.
- To lookup an SPI peripheral's MOSI pin mask, use the
  `::picolibrary::Microchip::megaAVR::Multiplexed_Signals::mosi_mask()` functions.
- To lookup an SPI peripheral's MISO pin PORT peripheral address, use the
  `::picolibrary::Microchip::megaAVR::Multiplexed_Signals::miso_port_address()` function.
- To lookup an SPI peripheral's MISO pin PORT peripheral, use the
  `::picolibrary::Microchip::megaAVR::Multiplexed_Signals::miso_port()` function.
- To lookup an SPI peripheral's MISO pin number, use the
  `::picolibrary::Microchip::megaAVR::Multiplexed_Signals::miso_number()` functions.
- To lookup an SPI peripheral's MISO pin mask, use the
  `::picolibrary::Microchip::megaAVR::Multiplexed_Signals::miso_mask()` functions.

## TWI Peripheral
Microchip megaAVR TWI peripheral multiplexed signals facilities are defined in the
following MCU specific header/source file pairs:
- [`include/picolibrary/microchip/megaavr/multiplexed_signals/atmega328p/twi.h`](https://github.com/apcountryman/picolibrary-microchip-megaavr/blob/main/include/picolibrary/microchip/megaavr/multiplexed_signals/atmega328p/twi.h)/[`source/picolibrary/microchip/megaavr/multiplexed_signals/atmega328p/twi.cc`](https://github.com/apcountryman/picolibrary-microchip-megaavr/blob/main/source/picolibrary/microchip/megaavr/multiplexed_signals/atmega328p/twi.cc)
- [`include/picolibrary/microchip/megaavr/multiplexed_signals/atmega2560/twi.h`](https://github.com/apcountryman/picolibrary-microchip-megaavr/blob/main/include/picolibrary/microchip/megaavr/multiplexed_signals/atmega2560/twi.h)/[`source/picolibrary/microchip/megaavr/multiplexed_signals/atmega2560/twi.cc`](https://github.com/apcountryman/picolibrary-microchip-megaavr/blob/main/source/picolibrary/microchip/megaavr/multiplexed_signals/atmega2560/twi.cc)

These facilities are defined in these files for source code organization reasons.
Users should access these facilities via the
[`include/picolibrary/microchip/megaavr/multiplexed_signals.h`](https://github.com/apcountryman/picolibrary-microchip-megaavr/blob/main/include/picolibrary/microchip/megaavr/multiplexed_signals.h)
header file.
- To lookup a TWI peripheral's pins PORT peripheral address, use the
  `::picolibrary::Microchip::megaAVR::Multiplexed_Signals::twi_port_address()` function.
- To lookup a TWI peripheral's pins PORT peripheral, use the
  `::picolibrary::Microchip::megaAVR::Multiplexed_Signals::twi_port()` function.
- To lookup a TWI peripheral's SCL pin PORT peripheral address, use the
  `::picolibrary::Microchip::megaAVR::Multiplexed_Signals::scl_port_address()` function.
- To lookup a TWI peripheral's SCL pin PORT peripheral, use the
  `::picolibrary::Microchip::megaAVR::Multiplexed_Signals::scl_port()` function.
- To lookup a TWI peripheral's SCL pin number, use the
  `::picolibrary::Microchip::megaAVR::Multiplexed_Signals::scl_number()` functions.
- To lookup a TWI peripheral's SCL pin mask, use the
  `::picolibrary::Microchip::megaAVR::Multiplexed_Signals::scl_mask()` functions.
- To lookup a TWI peripheral's SDA pin PORT peripheral address, use the
  `::picolibrary::Microchip::megaAVR::Multiplexed_Signals::sda_port_address()` function.
- To lookup a TWI peripheral's SDA pin PORT peripheral, use the
  `::picolibrary::Microchip::megaAVR::Multiplexed_Signals::sda_port()` function.
- To lookup a TWI peripheral's SDA pin number, use the
  `::picolibrary::Microchip::megaAVR::Multiplexed_Signals::sda_number()` functions.
- To lookup a TWI peripheral's SDA pin mask, use the
  `::picolibrary::Microchip::megaAVR::Multiplexed_Signals::sda_mask()` functions.

## USART Peripheral
Microchip megaAVR USART peripheral multiplexed signals facilities are defined in the
following MCU specific header/source file pairs:
- [`include/picolibrary/microchip/megaavr/multiplexed_signals/atmega328p/usart.h`](https://github.com/apcountryman/picolibrary-microchip-megaavr/blob/main/include/picolibrary/microchip/megaavr/multiplexed_signals/atmega328p/usart.h)/[`source/picolibrary/microchip/megaavr/multiplexed_signals/atmega328p/usart.cc`](https://github.com/apcountryman/picolibrary-microchip-megaavr/blob/main/source/picolibrary/microchip/megaavr/multiplexed_signals/atmega328p/usart.cc)
- [`include/picolibrary/microchip/megaavr/multiplexed_signals/atmega2560/usart.h`](https://github.com/apcountryman/picolibrary-microchip-megaavr/blob/main/include/picolibrary/microchip/megaavr/multiplexed_signals/atmega2560/usart.h)/[`source/picolibrary/microchip/megaavr/multiplexed_signals/atmega2560/usart.cc`](https://github.com/apcountryman/picolibrary-microchip-megaavr/blob/main/source/picolibrary/microchip/megaavr/multiplexed_signals/atmega2560/usart.cc)

These facilities are defined in these files for source code organization reasons.
Users should access these facilities via the
[`include/picolibrary/microchip/megaavr/multiplexed_signals.h`](https://github.com/apcountryman/picolibrary-microchip-megaavr/blob/main/include/picolibrary/microchip/megaavr/multiplexed_signals.h)
header file.
- To lookup a USART peripheral's pins PORT peripheral address, use the
  `::picolibrary::Microchip::megaAVR::Multiplexed_Signals::usart_port_address()` function.
- To lookup a USART peripheral's pins PORT peripheral, use the
  `::picolibrary::Microchip::megaAVR::Multiplexed_Signals::usart_port()` function.
- To lookup a USART peripheral's XCK pin PORT peripheral address, use the
  `::picolibrary::Microchip::megaAVR::Multiplexed_Signals::xck_port_address()` function.
- To lookup a USART peripheral's XCK pin PORT peripheral, use the
  `::picolibrary::Microchip::megaAVR::Multiplexed_Signals::xck_port()` function.
- To lookup a USART peripheral's XCK pin number, use the
  `::picolibrary::Microchip::megaAVR::Multiplexed_Signals::xck_number()` functions.
- To lookup a USART peripheral's XCK pin mask, use the
  `::picolibrary::Microchip::megaAVR::Multiplexed_Signals::xck_mask()` functions.
- To lookup a USART peripheral's TXD pin PORT peripheral address, use the
  `::picolibrary::Microchip::megaAVR::Multiplexed_Signals::txd_port_address()` function.
- To lookup a USART peripheral's TXD pin PORT peripheral, use the
  `::picolibrary::Microchip::megaAVR::Multiplexed_Signals::txd_port()` function.
- To lookup a USART peripheral's TXD pin number, use the
  `::picolibrary::Microchip::megaAVR::Multiplexed_Signals::txd_number()` functions.
- To lookup a USART peripheral's TXD pin mask, use the
  `::picolibrary::Microchip::megaAVR::Multiplexed_Signals::txd_mask()` functions.
- To lookup a USART peripheral's RXD pin PORT peripheral address, use the
  `::picolibrary::Microchip::megaAVR::Multiplexed_Signals::rxd_port_address()` function.
- To lookup a USART peripheral's RXD pin PORT peripheral, use the
  `::picolibrary::Microchip::megaAVR::Multiplexed_Signals::rxd_port()` function.
- To lookup a USART peripheral's RXD pin number, use the
  `::picolibrary::Microchip::megaAVR::Multiplexed_Signals::rxd_number()` functions.
- To lookup a USART peripheral's RXD pin mask, use the
  `::picolibrary::Microchip::megaAVR::Multiplexed_Signals::rxd_mask()` functions.
