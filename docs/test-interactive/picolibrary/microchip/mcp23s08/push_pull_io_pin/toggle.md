# `::picolibrary::Microchip::MCP23S08::Push_Pull_IO_Pin` toggle interactive test

## Test Configuration Options
The `::picolibrary::Microchip::MCP23S08::Push_Pull_IO_Pin` toggle interactive test
supports the following configuration options:
- `PICOLIBRARY_MICROCHIP_MCP23S08_PUSH_PULL_IO_PIN_ENABLE_TOGGLE_INTERACTIVE_TEST`
  (defaults to `OFF`): enable the `::picolibrary::Microchip::MCP23S08::Push_Pull_IO_Pin`
  toggle interactive test
    - The following configuration options are available if
      `PICOLIBRARY_MICROCHIP_MCP23S08_PUSH_PULL_IO_PIN_ENABLE_TOGGLE_INTERACTIVE_TEST` is
      `ON`
        - `PICOLIBRARY_MICROCHIP_MCP23S08_PUSH_PULL_IO_PIN_TOGGLE_INTERACTIVE_TEST_CONTROLLER_SPI`:
          `::picolibrary::Microchip::MCP23S08::Push_Pull_IO_Pin` toggle interactive test
          controller SPI
        - `PICOLIBRARY_MICROCHIP_MCP23S08_PUSH_PULL_IO_PIN_TOGGLE_INTERACTIVE_TEST_CONTROLLER_SPI_CLOCK_RATE`:
          `::picolibrary::Microchip::MCP23S08::Push_Pull_IO_Pin` toggle interactive test
          controller SPI clock rate
        - `PICOLIBRARY_MICROCHIP_MCP23S08_PUSH_PULL_IO_PIN_TOGGLE_INTERACTIVE_TEST_CONTROLLER_SPI_CLOCK_POLARITY`:
          `::picolibrary::Microchip::MCP23S08::Push_Pull_IO_Pin` toggle interactive test
          controller SPI clock polarity
        - `PICOLIBRARY_MICROCHIP_MCP23S08_PUSH_PULL_IO_PIN_TOGGLE_INTERACTIVE_TEST_CONTROLLER_SPI_CLOCK_PHASE`:
          `::picolibrary::Microchip::MCP23S08::Push_Pull_IO_Pin` toggle interactive test
          controller SPI clock phase
        - `PICOLIBRARY_MICROCHIP_MCP23S08_PUSH_PULL_IO_PIN_TOGGLE_INTERACTIVE_TEST_DEVICE_SELECTOR_PORT`:
          `::picolibrary::Microchip::MCP23S08::Push_Pull_IO_Pin` toggle interactive test
          device selector PORT
        - `PICOLIBRARY_MICROCHIP_MCP23S08_PUSH_PULL_IO_PIN_TOGGLE_INTERACTIVE_TEST_DEVICE_SELECTOR_MASK`:
          `::picolibrary::Microchip::MCP23S08::Push_Pull_IO_Pin` toggle interactive test
          device selector mask
        - `PICOLIBRARY_MICROCHIP_MCP23S08_PUSH_PULL_IO_PIN_TOGGLE_INTERACTIVE_TEST_MCP23S08_ADDRESS`
          (defaults to `Address_Numeric{ 0b01000'00 }`):
          `::picolibrary::Microchip::MCP23S08::Push_Pull_IO_Pin` toggle interactive test
          MCP23S08 address
        - `PICOLIBRARY_MICROCHIP_MCP23S08_PUSH_PULL_IO_PIN_TOGGLE_INTERACTIVE_TEST_MCP23S08_PIN_MASK`
          (defaults to `1 << 0` `::picolibrary::Microchip::MCP23S08::Push_Pull_IO_Pin`
          toggle interactive test MCP23S08 pin mask

## Test Executable Name
`test-interactive-picolibrary-microchip-mcp23s08-push_pull_io_pin-toggle`
