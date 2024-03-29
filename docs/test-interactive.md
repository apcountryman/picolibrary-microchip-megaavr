# Interactive Tests

## Table of Contents
1. [Configuration Requirements](#configuration-requirements)
1. [avrdude Configuration Options](#avrdude-configuration-options)
1. [Test Targets](#test-targets)
1. [Tests](#tests)

## Configuration Requirements
picolibrary-microchip-megaavr interactive tests have the following project configuration
requirements:
- `PICOLIBRARY_MICROCHIP_MEGAAVR_ENABLE_INTERACTIVE_TESTING` must be `ON`
- `PICOLIBRARY_MICROCHIP_MEGAAVR_INTERACTIVE_TESTING_LOG_USART` must be configured
- `PICOLIBRARY_MICROCHIP_MEGAAVR_INTERACTIVE_TESTING_LOG_USART_CLOCK_GENERATOR_OPERATING_SPEED`
  must be configured
- `PICOLIBRARY_MICROCHIP_MEGAAVR_INTERACTIVE_TESTING_LOG_USART_CLOCK_GENERATOR_SCALING_FACTOR`
  must be configured

## avrdude Configuration Options
picolibrary-microchip-megaavr interactive tests support the following avrdude
configuration options:
- `PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_RESET_ENABLED` (defaults to `OFF`): reset AVR
  before executing avrdude
- `PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_CONFIGURATION_FILE` (optional): avrdude
  configuration file
- `PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_PORT`: avrdude port
- `PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_PROGRAM_FLASH`: flash programming avrdude
  arguments
- `PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_VERBOSITY` (defaults to `VERBOSE`): avrdude
  verbosity
- `PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_VERIFY_FLASH`: flash verification avrdude
  arguments

## Test Targets
Each picolibrary-microchip-megaavr interactive test has the following targets:
- `<test executable name>`: executable creation target
- `<test executable name>-hex-flash`: Flash programming/verification hex file creation
  target
- `<test executable name>-program-flash`: Flash programming target
- `<test executable name>-verify-flash`: Flash verification target

## Tests
- [`::picolibrary::Adafruit::PID781::Driver` hello world interactive test](test-interactive/picolibrary/adafruit/pid781/driver/hello_world.md)
- [`::picolibrary::Asynchronous_Serial::Reliable_Unbuffered_Output_Stream` hello world interactive test](test-interactive/picolibrary/asynchronous_serial/reliable_unbuffered_output_stream/hello_world.md)
- [`::picolibrary::Microchip::MCP23008::Internally_Pulled_Up_Input_Pin` state interactive test](test-interactive/picolibrary/microchip/mcp23008/internally_pulled_up_input_pin/state.md)
- [`::picolibrary::Microchip::MCP23008::Open_Drain_IO_Pin` toggle interactive test](test-interactive/picolibrary/microchip/mcp23008/open_drain_io_pin/toggle.md)
- [`::picolibrary::Microchip::MCP23008::Push_Pull_IO_Pin` toggle interactive test](test-interactive/picolibrary/microchip/mcp23008/push_pull_io_pin/toggle.md)
- [`::picolibrary::Microchip::MCP23S08::Internally_Pulled_Up_Input_Pin` state interactive test](test-interactive/picolibrary/microchip/mcp23s08/internally_pulled_up_input_pin/state.md)
- [`::picolibrary::Microchip::MCP23S08::Open_Drain_IO_Pin` toggle interactive test](test-interactive/picolibrary/microchip/mcp23s08/open_drain_io_pin/toggle.md)
- [`::picolibrary::Microchip::MCP23S08::Push_Pull_IO_Pin` toggle interactive test](test-interactive/picolibrary/microchip/mcp23s08/push_pull_io_pin/toggle.md)
- [`::picolibrary::Microchip::MCP3008::Blocking_Single_Sample_Converter` sample interactive test](test-interactive/picolibrary/microchip/mcp3008/blocking_single_sample_converter/sample.md)
- [`::picolibrary::Microchip::megaAVR::Asynchronous_Serial::Transmitter` hello world interactive test](test-interactive/picolibrary/microchip/megaavr/asynchronous_serial/transmitter/hello_world.md)
- [`::picolibrary::Microchip::megaAVR::GPIO::Internally_Pulled_Up_Input_Pin` state interactive test](test-interactive/picolibrary/microchip/megaavr/gpio/internally_pulled_up_input_pin/state.md)
- [`::picolibrary::Microchip::megaAVR::GPIO::Open_Drain_IO_Pin` toggle interactive test](test-interactive/picolibrary/microchip/megaavr/gpio/open_drain_io_pin/toggle.md)
- [`::picolibrary::Microchip::megaAVR::GPIO::Push_Pull_IO_Pin` toggle interactive test](test-interactive/picolibrary/microchip/megaavr/gpio/push_pull_io_pin/toggle.md)
- [`::picolibrary::Microchip::megaAVR::I2C::Controller` scan interactive test](test-interactive/picolibrary/microchip/megaavr/i2c/controller/scan.md)
- [`::picolibrary::Microchip::megaAVR::SPI::Fixed_Configuration_Controller<Peripheral::SPI>` echo interactive test](test-interactive/picolibrary/microchip/megaavr/spi/fixed_configuration_controller-spi/echo.md)
- [`::picolibrary::Microchip::megaAVR::SPI::Fixed_Configuration_Controller<Peripheral::USART>` echo interactive test](test-interactive/picolibrary/microchip/megaavr/spi/fixed_configuration_controller-usart/echo.md)
- [`::picolibrary::Microchip::megaAVR::SPI::Variable_Configuration_Controller<Peripheral::SPI>` echo interactive test](test-interactive/picolibrary/microchip/megaavr/spi/variable_configuration_controller-spi/echo.md)
- [`::picolibrary::Microchip::megaAVR::SPI::Variable_Configuration_Controller<Peripheral::USART>` echo interactive test](test-interactive/picolibrary/microchip/megaavr/spi/variable_configuration_controller-usart/echo.md)
- [`::picolibrary::Texas_Instruments::TCA9548A::Driver` scan interactive test](test-interactive/picolibrary/texas_instruments/tca9548a/driver/scan.md)
- [`::picolibrary::WIZnet::W5500::IP::Network_Stack` ping interactive test](test-interactive/picolibrary/wiznet/w5500/ip/network_stack/ping.md)
- [`::picolibrary::WIZnet::W5500::IP::TCP::Client` echo interactive test](test-interactive/picolibrary/wiznet/w5500/ip/tcp/client/echo.md)
- [`::picolibrary::WIZnet::W5500::IP::TCP::Server` echo interactive test](test-interactive/picolibrary/wiznet/w5500/ip/tcp/server/echo.md)
- [`::picolibrary::WIZnet::W5500::IP::UDP::Socket` echo interactive test](test-interactive/picolibrary/wiznet/w5500/ip/udp/socket/echo.md)
