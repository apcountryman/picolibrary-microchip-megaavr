# Interactive Testing Utilities
Interactive testing utilities are available if the
`PICOLIBRARY_MICROCHIP_MEGAAVR_ENABLE_INTERACTIVE_TESTING` project configuration option is
`ON`.

## Table of Contents
1. [Fatal Error Trap](#fatal-error-trap)
1. [Log](#log)

## Fatal Error Trap
picolibrary-microchip-megaavr provides an implementation for
`::picolibrary::trap_fatal_error()` for use in interactive tests.
The implementation is defined in the
[`source/picolibrary/testing/interactive/microchip/megaavr/fatal_error.cc`](https://github.com/apcountryman/picolibrary-microchip-megaavr/blob/main/source/picolibrary/testing/interactive/microchip/megaavr/fatal_error.cc)
source file.
The `picolibrary-microchip-megaavr` static library does not include this implementation.
To use this implementation, link with the
`picolibrary-microchip-megaavr-testing-interactive-fatal_error` static library.

## Log
The `::picolibrary::Testing::Interactive::Microchip::megaAVR::Log` class is a reliable
output stream for interacting with a Microchip megaAVR USART peripheral.
The `::picolibrary::Testing::Interactive::Microchip::megaAVR::Log` class is defined in the
[`include/picolibrary/testing/interactive/microchip/megaavr/log.h`](https://github.com/apcountryman/picolibrary-microchip-megaavr/blob/main/include/picolibrary/testing/interactive/microchip/megaavr/log.h)/[`source/picolibrary/testing/interactive/microchip/megaavr/log.cc`](https://github.com/apcountryman/picolibrary-microchip-megaavr/blob/main/source/picolibrary/testing/interactive/microchip/megaavr/log.cc)
header/source file pair.
- To check if the log has been initialized, use the
  `::picolibrary::Testing::Interactive::Microchip::megaAVR::Log::is_initialized()` static
  member function.
- To initialize the log, use the
  `::picolibrary::Testing::Interactive::Microchip::megaAVR::Log::initialize()` static
  member functions.
- To report a fatal error, use the
  `::picolibrary::Testing::Interactive::Microchip::megaAVR::Log::report_fatal_error()`
  static member function.
- To get the log instance, use the
  `::picolibrary::Testing::Interactive::Microchip::megaAVR::Log::instance()` static member
  function.
