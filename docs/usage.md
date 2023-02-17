# Usage

## Table of Contents
1. [Dependency](#dependency)
    1. [Configuration Options](#configuration-options)
1. [Development](#development)

## Dependency
To use picolibrary-microchip-megaavr as a dependency, simply add the subdirectory
containing the repository to a CMake build, and link with the
`picolibrary-microchip-megaavr` static library.
```cmake
add_subdirectory( picolibrary-microchip-megaavr )
```
```cmake
target_link_libraries(
    foo
    picolibrary-microchip-megaavr
)
```

The `picolibrary-microchip-megaavr` static library does not include
`::picolibrary::Microchip::megaAVR::version()`.
To use `::picolibrary::Microchip::megaAVR::version()`, link with the
`picolibrary-microchip-megaavr-version` static library.
```cmake
target_link_libraries(
    foo
    picolibrary-microchip-megaavr
    picolibrary-microchip-megaavr-version
)
```

### Configuration Options
picolibrary-microchip-megaavr supports the following project configuration options:
- `PICOLIBRARY_MICROCHIP_MEGAAVR_ENABLE_INTERACTIVE_TESTING` (defaults to `OFF`): enable
  interactive testing
    - The following project configuration options are available if
      `PICOLIBRARY_MICROCHIP_MEGAAVR_ENABLE_INTERACTIVE_TESTING` is `ON`:
        - `PICOLIBRARY_MICROCHIP_MEGAAVR_TESTING_INTERACTIVE_LOG_USART` (optional):
          `::picolibrary::Testing::Interactive::Microchip::megaAVR::Log` USART (see
          [`include/picolibrary/testing/interactive/microchip/megaavr/log.h`](https://github.com/apcountryman/picolibrary-microchip-megaavr/blob/main/include/picolibrary/testing/interactive/microchip/megaavr/log.h)
          for more information)
        - `PICOLIBRARY_MICROCHIP_MEGAAVR_TESTING_INTERACTIVE_LOG_USART_CLOCK_GENERATOR_OPERATING_SPEED`
          (optional): `::picolibrary::Testing::Interactive::Microchip::megaAVR::Log` USART
          clock generator operating speed (see
          [`include/picolibrary/testing/interactive/microchip/megaavr/log.h`](https://github.com/apcountryman/picolibrary-microchip-megaavr/blob/main/include/picolibrary/testing/interactive/microchip/megaavr/log.h)
          for more information)
        - `PICOLIBRARY_MICROCHIP_MEGAAVR_TESTING_INTERACTIVE_LOG_USART_CLOCK_GENERATOR_SCALING_FACTOR`
          (optional): `::picolibrary::Testing::Interactive::Microchip::megaAVR::Log` USART
          clock generator scaling factor (see
          [`include/picolibrary/testing/interactive/microchip/megaavr/log.h`](https://github.com/apcountryman/picolibrary-microchip-megaavr/blob/main/include/picolibrary/testing/interactive/microchip/megaavr/log.h)
          for more information)
- `PICOLIBRARY_MICROCHIP_MEGAAVR_USE_PARENT_PROJECT_BUILD_FLAGS` (defaults to `ON`) use
  parent project's build flags
    - The following project configuration options are available if
      `PICOLIBRARY_MICROCHIP_MEGAAVR_USE_PARENT_PROJECT_BUILD_FLAGS` is `OFF`:
        - `PICOLIBRARY_MICROCHIP_MEGAAVR_MCU`: MCU type
        - `PICOLIBRARY_MICROCHIP_MEGAAVR_F_CPU`: CPU frequency, in Hz
- `PICOLIBRARY_MICROCHIP_MEGAAVR_USE_PARENT_PROJECT_AVRLIBCPP` (defaults to `ON`): use
  parent project's avr-libcpp
- `PICOLIBRARY_MICROCHIP_MEGAAVR_USE_PARENT_PROJECT_PICOLIBRARY` (defaults to `ON`): use
  parent project's picolibrary

## Development
The repository's Git `pre-commit` hook script is the simplest way to configure, and build
picolibrary-microchip-megaavr during development.
See the `pre-commit` script's help text for usage details.
```shell
./git/hooks/pre-commit --help
```

Additional checks, such as static analysis, are performed by the repository's GitHub
Actions CI workflow.
