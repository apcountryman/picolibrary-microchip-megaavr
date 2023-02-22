# General Purpose Input/Output (GPIO) Facilities
Microchip megaAVR GPIO facilities are defined in the
[`include/picolibrary/microchip/megaavr/gpio.h`](https://github.com/apcountryman/picolibrary-microchip-megaavr/blob/main/include/picolibrary/microchip/megaavr/gpio.h)/[`source/picolibrary/microchip/megaavr/gpio.cc`](https://github.com/apcountryman/picolibrary-microchip-megaavr/blob/main/source/picolibrary/microchip/megaavr/gpio.cc)
header/source file pair.

## Table of Contents
1. [Pin](#pin)
1. [Internally Pulled-Up Input Pin](#internally-pulled-up-input-pin)
1. [Open-Drain Input/Output (I/O) Pin](#open-drain-inputoutput-io-pin)
1. [Push-Pull I/O Pin](#push-pull-io-pin)

## Pin
The `::picolibrary::Microchip::megaAVR::GPIO::Pin` class is used to interact with a
Microchip megaAVR microcontroller pin.
- To check if a pin is associated with a GPIO port, use the `bool` conversion operator.
- To configure a pin to act as an internally pulled-up input, use the
  `::picolibrary::Microchip::megaAVR::GPIO::Pin::configure_pin_as_internally_pulled_up_input()`
  member function.
- To configure a pin to act as an open-drain I/O pin, use the
  `::picolibrary::Microchip::megaAVR::GPIO::Pin::configure_pin_as_open_drain_io()` member
  function.
- To configure a pin to act as a push-pull I/O pin, use the
  `::picolibrary::Microchip::megaAVR::GPIO::Pin::configure_pin_as_push_pull_io()` member
  function.
- To check if an internally pulled-up input pin's internal pull-up resistor is disabled,
  use the `::picolibrary::Microchip::megaAVR::GPIO::Pin::pull_up_is_disabled()` member
  function.
- To check if an internally pulled-up input pin's internal pull-up resistor is enabled,
  use the `::picolibrary::Microchip::megaAVR::GPIO::Pin::pull_up_is_enabled()` member
  function.
- To disable an internally pulled-up input pin's internal pull-up resistor, use the
  `::picolibrary::Microchip::megaAVR::GPIO::Pin::disable_pull_up()` member function.
- To enable an internally pulled-up input pin's internal pull-up resistor, use the
  `::picolibrary::Microchip::megaAVR::GPIO::Pin::enable_pull_up()` member function.
- To check if a pin is in the low state, use the
  `::picolibrary::Microchip::megaAVR::GPIO::Pin::is_low()` member function.
- To check if a pin is in the high state, use the
  `::picolibrary::Microchip::megaAVR::GPIO::Pin::is_high()` member function.
- To transition an open-drain I/O pin to the low state, use the
  `::picolibrary::Microchip::megaAVR::GPIO::Pin::transition_open_drain_io_to_low()` member
  function.
- To transition a push-pull I/O pin to the low state, use the
  `::picolibrary::Microchip::megaAVR::GPIO::Pin::transition_push_pull_io_to_low()` member
  function.
- To transition an open-drain I/O pin to the high state, use the
  `::picolibrary::Microchip::megaAVR::GPIO::Pin::transition_open_drain_io_to_high()`
  member function.
- To transition a push-pull I/O pin to the high state, use the
  `::picolibrary::Microchip::megaAVR::GPIO::Pin::transition_push_pull_io_to_high()` member
  function.
- To toggle the state of an open-drain I/O pin, use the
  `::picolibrary::Microchip::megaAVR::GPIO::Pin::toggle_open_drain_io()` member function.
- To toggle the state of a push-pull I/O pin, use the
  `::picolibrary::Microchip::megaAVR::GPIO::Pin::toggle_push_pull_io()` member function.

## Internally Pulled-Up Input Pin
The `::picolibrary::Microchip::megaAVR::GPIO::Internally_Pulled_Up_Input_Pin` class
implements a GPIO internally pulled-up input pin interface for interacting with a
Microchip megaAVR microcontroller pin.
See the [`::picolibrary::GPIO::Internally_Pulled_Up_Input_Pin_Concept`
documentation](https://apcountryman.github.io/picolibrary/gpio.html#internally-pulled-up-input-pin)
for more information.
The `::picolibrary::Microchip::megaAVR::GPIO::Internally_Pulled_Up_Input_Pin` state
interactive test is defined in the
[`test/interactive/picolibrary/microchip/megaavr/gpio/internally_pulled_up_input_pin/state/main.cc`](https://github.com/apcountryman/picolibrary-microchip-megaavr/blob/main/test/interactive/picolibrary/microchip/megaavr/gpio/internally_pulled_up_input_pin/state/main.cc)
source file.

## Open-Drain Input/Output (I/O) Pin
The `::picolibrary::Microchip::megaAVR::GPIO::Open_Drain_IO_Pin` class implements a GPIO
open-drain I/O pin interface for interacting with a Microchip megaAVR microcontroller pin.
See the [`::picolibrary::GPIO::IO_Pin_Concept`
documentation](https://apcountryman.github.io/picolibrary/gpio.html#io-pin)
for more information.
The `::picolibrary::Microchip::megaAVR::GPIO::Open_Drain_IO_Pin` toggle interactive test
is defined in the
[`test/interactive/picolibrary/microchip/megaavr/gpio/open_drain_io_pin/toggle/main.cc`](https://github.com/apcountryman/picolibrary-microchip-megaavr/blob/main/test/interactive/picolibrary/microchip/megaavr/gpio/open_drain_io_pin/toggle/main.cc)
source file.

## Push-Pull I/O Pin
The `::picolibrary::Microchip::megaAVR::GPIO::Push_Pull_IO_Pin` class implements a GPIO
push-pull I/O pin interface for interacting with a Microchip megaAVR microcontroller pin.
See the [`::picolibrary::GPIO::IO_Pin_Concept`
documentation](https://apcountryman.github.io/picolibrary/gpio.html#io-pin)
for more information.
The `::picolibrary::Microchip::megaAVR::GPIO::Push_Pull_IO_Pin` toggle interactive test is
defined in the
[`test/interactive/picolibrary/microchip/megaavr/gpio/push_pull_io_pin/toggle/main.cc`](https://github.com/apcountryman/picolibrary-microchip-megaavr/blob/main/test/interactive/picolibrary/microchip/megaavr/gpio/push_pull_io_pin/toggle/main.cc)
source file.
