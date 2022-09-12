# `::picolibrary::Microchip::MCP23008::Push_Pull_IO_Pin` toggle interactive test

## Test Configuration Options
The `::picolibrary::Microchip::MCP23008::Push_Pull_IO_Pin` toggle interactive test
supports the following configuration options:
- `PICOLIBRARY_MICROCHIP_MCP23008_PUSH_PULL_IO_PIN_ENABLE_TOGGLE_INTERACTIVE_TEST`
  (defaults to `OFF`): enable the `::picolibrary::Microchip::MCP23008::Push_Pull_IO_Pin`
  toggle interactive test
    - The following configuration options are available if
      `PICOLIBRARY_MICROCHIP_MCP23008_PUSH_PULL_IO_PIN_ENABLE_TOGGLE_INTERACTIVE_TEST` is
      `ON`:
        - `PICOLIBRARY_MICROCHIP_MCP23008_PUSH_PULL_IO_PIN_TOGGLE_INTERACTIVE_TEST_CONTROLLER_TWI`:
          `::picolibrary::Microchip::MCP23008::Push_Pull_IO_Pin` toggle interactive test
          controller TWI
        - `PICOLIBRARY_MICROCHIP_MCP23008_PUSH_PULL_IO_PIN_TOGGLE_INTERACTIVE_TEST_CONTROLLER_TWI_BIT_RATE_GENERATOR_PRESCALER_VALUE`:
          `::picolibrary::Microchip::MCP23008::Push_Pull_IO_Pin` toggle interactive test
          controller TWI bit rate generator prescaler value
        - `PICOLIBRARY_MICROCHIP_MCP23008_PUSH_PULL_IO_PIN_TOGGLE_INTERACTIVE_TEST_CONTROLLER_TWI_BIT_RATE_GENERATOR_SCALING_FACTOR`:
          `::picolibrary::Microchip::MCP23008::Push_Pull_IO_Pin` toggle interactive test
          controller TWI bit rate generator scaling factor
        - `PICOLIBRARY_MICROCHIP_MCP23008_PUSH_PULL_IO_PIN_TOGGLE_INTERACTIVE_TEST_MCP23008_ADDRESS`
          (defaults to `Address_Numeric{ 0b0100'000 }`):
          `::picolibrary::Microchip::MCP23008::Push_Pull_IO_Pin` toggle interactive test
          MCP23008 address
        - `PICOLIBRARY_MICROCHIP_MCP23008_PUSH_PULL_IO_PIN_TOGGLE_INTERACTIVE_TEST_MCP23008_PIN_MASK`
          (defaults to `1 << 0`): `::picolibrary::Microchip::MCP23008::Push_Pull_IO_Pin`
          toggle interactive test MCP23008 pin mask

## Test Executable Name
`test-interactive-picolibrary-microchip-mcp23008-push_pull_io_pin-toggle`
