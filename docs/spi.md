# Serial Peripheral Interface (SPI) Facilities
Microchip megaAVR SPI facilities are defined in the
[`include/picolibrary/microchip/megaavr/spi.h`](https://github.com/apcountryman/picolibrary-microchip-megaavr/blob/main/include/picolibrary/microchip/megaavr/spi.h)/[`source/picolibrary/microchip/megaavr/spi.cc`](https://github.com/apcountryman/picolibrary-microchip-megaavr/blob/main/source/picolibrary/microchip/megaavr/spi.cc)
header/source file pair.

## Table of Contents
1. [Controller](#controller)

## Controller
picolibrary-microchip-megaavr implements two types of SPI controllers: fixed configuration
and variable configuration.
Fixed configuration controllers should be used when all SPI devices that use a controller
use the same clock (frequency, polarity, and phase) and data exchange bit order
configuration.
Variable configuration controllers should be used when this is not the case.

`::picolibrary::Microchip::megaAVR::SPI::Fixed_Configuration_Basic_Controller` template
class specializations implement an SPI fixed configuration basic controller interface for
interacting with Microchip megaAVR SPI and USART peripherals.
The
`::picolibrary::Microchip::megaAVR::SPI::Fixed_Configuration_Basic_Controller<::picolibrary::Microchip::megaAVR::Peripheral::SPI>`
specialization implements the interface for interacting with an SPI peripheral.
The
`::picolibrary::Microchip::megaAVR::SPI::Fixed_Configuration_Basic_Controller<::picolibrary::Microchip::megaAVR::Peripheral::USART>`
specialization implements the interface for interacting with a USART peripheral.
See the [`::picolibrary::SPI::Basic_Controller_Concept`
documentation](https://apcountryman.github.io/picolibrary/spi.html#controller) for more
information.

`::picolibrary::Microchip::megaAVR::SPI::Variable_Configuration_Basic_Controller` template
class specializations implement an SPI variable configuration basic controller interface
for interacting with Microchip megaAVR SPI and USART peripherals.
The
`::picolibrary::Microchip::megaAVR::SPI::Variable_Configuration_Basic_Controller<::picolibrary::Microchip::megaAVR::Peripheral::SPI>`
specialization implements the interface for interacting with an SPI peripheral.
The
`::picolibrary::Microchip::megaAVR::SPI::Variable_Configuration_Basic_Controller<::picolibrary::Microchip::megaAVR::Peripheral::USART>`
specialization implements the interface for interacting with a USART peripheral.
See the [`::picolibrary::SPI::Basic_Controller_Concept`
documentation](https://apcountryman.github.io/picolibrary/spi.html#controller) for more
information.

The `::picolibrary::Microchip::megaAVR::SPI::Fixed_Configuration_Controller` alias
template adds controller functionality to
`::picolibrary::Microchip::megaAVR::SPI::Fixed_Configuration_Basic_Controller`.
See the [`::picolibrary::SPI::Controller_Concept`
documentation](https://apcountryman.github.io/picolibrary/spi.html#controller) for more
information.
The
`::picolibrary::Microchip::megaAVR::SPI::Fixed_Configuration_Controller<::picolibrary::Microchip::megaAVR::Peripheral::SPI>`
echo interactive test is defined in the
[`test/interactive/picolibrary/microchip/megaavr/spi/fixed_configuration_controller-spi/echo/main.cc`](https://github.com/apcountryman/picolibrary-microchip-megaavr/blob/main/test/interactive/picolibrary/microchip/megaavr/spi/fixed_configuration_controller-spi/echo/main.cc)
source file.
The
`::picolibrary::Microchip::megaAVR::SPI::Fixed_Configuration_Controller<::picolibrary::Microchip::megaAVR::Peripheral::USART>`
echo interactive test is defined in the
[`test/interactive/picolibrary/microchip/megaavr/spi/fixed_configuration_controller-usart/echo/main.cc`](https://github.com/apcountryman/picolibrary-microchip-megaavr/blob/main/test/interactive/picolibrary/microchip/megaavr/spi/fixed_configuration_controller-usart/echo/main.cc)
source file.

The `::picolibrary::Microchip::megaAVR::SPI::Variable_Configuration_Controller` alias
template adds controller functionality to
`::picolibrary::Microchip::megaAVR::SPI::Variable_Configuration_Basic_Controller`.
See the [`::picolibrary::SPI::Controller_Concept`
documentation](https://apcountryman.github.io/picolibrary/spi.html#controller) for more
information.
The
`::picolibrary::Microchip::megaAVR::SPI::Variable_Configuration_Controller<::picolibrary::Microchip::megaAVR::Peripheral::SPI>`
echo interactive test is defined in the
[`test/interactive/picolibrary/microchip/megaavr/spi/variable_configuration_controller-spi/echo/main.cc`](https://github.com/apcountryman/picolibrary-microchip-megaavr/blob/main/test/interactive/picolibrary/microchip/megaavr/spi/variable_configuration_controller-spi/echo/main.cc)
source file.
The
`::picolibrary::Microchip::megaAVR::SPI::Variable_Configuration_Controller<::picolibrary::Microchip::megaAVR::Peripheral::USART>`
echo interactive test is defined in the
[`test/interactive/picolibrary/microchip/megaavr/spi/variable_configuration_controller-usart/echo/main.cc`](https://github.com/apcountryman/picolibrary-microchip-megaavr/blob/main/test/interactive/picolibrary/microchip/megaavr/spi/variable_configuration_controller-usart/echo/main.cc)
source file.
