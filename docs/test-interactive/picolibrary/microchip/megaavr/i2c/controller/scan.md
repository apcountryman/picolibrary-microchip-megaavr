# `::picolibrary::Microchip::megaAVR::I2C::Controller` scan interactive test

## Table of Contents
1. [Test Configuration Options](#test-configuration-options)
1. [Test Executable Name](#test-executable-name)

## Test Configuration Options
The `::picolibrary::Microchip::megaAVR::I2C::Controller` scan interactive test supports
the following configuration options:
- `PICOLIBRARY_MICROCHIP_MEGAAVR_I2C_CONTROLLER_ENABLE_SCAN_INTERACTIVE_TEST` (defaults to
  `OFF`): enable the `::picolibrary::Microchip::megaAVR::I2C::Controller` scan interactive
  test
    - The following configuration options are available if
      `PICOLIBRARY_MICROCHIP_MEGAAVR_I2C_CONTROLLER_ENABLE_SCAN_INTERACTIVE_TEST` is `ON`:
        - `PICOLIBRARY_MICROCHIP_MEGAAVR_I2C_CONTROLLER_SCAN_INTERACTIVE_TEST_CONTROLLER_TWI`:
          `::picolibrary::Microchip::megaAVR::I2C::Controller` scan interactive test
          controller TWI
        - `PICOLIBRARY_MICROCHIP_MEGAAVR_I2C_CONTROLLER_SCAN_INTERACTIVE_TEST_CONTROLLER_TWI_BIT_RATE_GENERATOR_PRESCALER_VALUE`:
          `::picolibrary::Microchip::megaAVR::I2C::Controller` scan interactive test
          controller TWI bit rate generator prescaler value
        - `PICOLIBRARY_MICROCHIP_MEGAAVR_I2C_CONTROLLER_SCAN_INTERACTIVE_TEST_CONTROLLER_TWI_BIT_RATE_GENERATOR_SCALING_FACTOR`:
          `::picolibrary::Microchip::megaAVR::I2C::Controller` scan interactive test
          controller TWI bit rate generator scaling factor

## Test Executable Name
`test-interactive-picolibrary-microchip-megaavr-i2c-controller-scan`
