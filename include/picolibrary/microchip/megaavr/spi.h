/**
 * picolibrary-microchip-megaavr
 *
 * Copyright 2020-2022, Andrew Countryman <apcountryman@gmail.com> and the
 * picolibrary-microchip-megaavr contributors
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may not use this
 * file except in compliance with the License. You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software distributed under
 * the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied. See the License for the specific language governing
 * permissions and limitations under the License.
 */

/**
 * \file
 * \brief picolibrary::Microchip::megaAVR::SPI interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR_SPI_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR_SPI_H

#include <cstdint>

#include "picolibrary/microchip/megaavr/peripheral/spi.h"
#include "picolibrary/microchip/megaavr/peripheral/usart.h"

/**
 * \brief Microchip megaAVR Serial Peripheral Interface (SPI) facilities.
 */
namespace picolibrary::Microchip::megaAVR::SPI {

/**
 * \brief SPI clock rate SPCR register SPR field offset.
 */
constexpr auto SPI_CLOCK_RATE_SPCR_SPR_OFFSET = std::uint_fast8_t{ 1 };

/**
 * \brief SPI clock rate.
 */
enum class SPI_Clock_Rate : std::uint_fast8_t {
    FOSC_2 = ( 0b1 << Peripheral::SPI::SPSR::Bit::SPI2X )
             | ( 0b00 << ( Peripheral::SPI::SPCR::Bit::SPR + SPI_CLOCK_RATE_SPCR_SPR_OFFSET ) ), ///< fosc/2
    FOSC_4 = ( 0b0 << Peripheral::SPI::SPSR::Bit::SPI2X )
             | ( 0b00 << ( Peripheral::SPI::SPCR::Bit::SPR + SPI_CLOCK_RATE_SPCR_SPR_OFFSET ) ), ///< fosc/4
    FOSC_8 = ( 0b1 << Peripheral::SPI::SPSR::Bit::SPI2X )
             | ( 0b01 << ( Peripheral::SPI::SPCR::Bit::SPR + SPI_CLOCK_RATE_SPCR_SPR_OFFSET ) ), ///< fosc/8
    FOSC_16 = ( 0b0 << Peripheral::SPI::SPSR::Bit::SPI2X )
              | ( 0b01 << ( Peripheral::SPI::SPCR::Bit::SPR + SPI_CLOCK_RATE_SPCR_SPR_OFFSET ) ), ///< fosc/16
    FOSC_32 = ( 0b1 << Peripheral::SPI::SPSR::Bit::SPI2X )
              | ( 0b10 << ( Peripheral::SPI::SPCR::Bit::SPR + SPI_CLOCK_RATE_SPCR_SPR_OFFSET ) ), ///< fosc/32
    FOSC_64 = ( 0b0 << Peripheral::SPI::SPSR::Bit::SPI2X )
              | ( 0b10 << ( Peripheral::SPI::SPCR::Bit::SPR + SPI_CLOCK_RATE_SPCR_SPR_OFFSET ) ), ///< fosc/64
    FOSC_128 = ( 0b0 << Peripheral::SPI::SPSR::Bit::SPI2X )
               | ( 0b11 << ( Peripheral::SPI::SPCR::Bit::SPR + SPI_CLOCK_RATE_SPCR_SPR_OFFSET ) ), ///< fosc/128
};

/**
 * \brief SPI clock polarity.
 */
enum class SPI_Clock_Polarity : std::uint8_t {
    IDLE_LOW = Peripheral::SPI::SPCR::CPOL_LEADING_EDGE_RISING_TRAILING_EDGE_FALLING, ///< Idle low.
    IDLE_HIGH = Peripheral::SPI::SPCR::CPOL_LEADING_EDGE_FALLING_TRAILING_EDGE_RISING, ///< Idle high.
};

/**
 * \brief SPI clock phase.
 */
enum class SPI_Clock_Phase : std::uint8_t {
    CAPTURE_IDLE_TO_ACTIVE = Peripheral::SPI::SPCR::CPHA_LEADING_EDGE_SAMPLE_TRAILING_EDGE_SETUP, ///< Capture data on the idle-to-active clock transition.
    CAPTURE_ACTIVE_TO_IDLE = Peripheral::SPI::SPCR::CPHA_LEADING_EDGE_SETUP_TRAILING_EDGE_SAMPLE, ///< Capture data on the active-to-idle clock transition.
};

/**
 * \brief SPI bit order.
 */
enum class SPI_Bit_Order : std::uint8_t {
    MSB_FIRST = 0b0 << Peripheral::SPI::SPCR::Bit::DORD, ///< MSB first.
    LSB_FIRST = 0b1 << Peripheral::SPI::SPCR::Bit::DORD, ///< LSB first.
};

/**
 * \brief USART clock polarity.
 */
enum class USART_Clock_Polarity : std::uint8_t {
    IDLE_LOW  = 0b0 << Peripheral::USART::SPI_Host::UCSRC::Bit::UCPOL, ///< Idle low.
    IDLE_HIGH = 0b1 << Peripheral::USART::SPI_Host::UCSRC::Bit::UCPOL, ///< Idle high.
};

/**
 * \brief USART clock phase.
 */
enum class USART_Clock_Phase : std::uint8_t {
    CAPTURE_IDLE_TO_ACTIVE = 0b0 << Peripheral::USART::SPI_Host::UCSRC::Bit::UCPHA, ///< Capture data on the idle-to-active clock transition.
    CAPTURE_ACTIVE_TO_IDLE = 0b1 << Peripheral::USART::SPI_Host::UCSRC::Bit::UCPHA, ///< Capture data on the active-to-idle clock transition.
};

/**
 * \brief USART bit order.
 */
enum class USART_Bit_Order : std::uint8_t {
    MSB_FIRST = 0b0 << Peripheral::USART::SPI_Host::UCSRC::Bit::UDORD, ///< MSB first.
    LSB_FIRST = 0b1 << Peripheral::USART::SPI_Host::UCSRC::Bit::UDORD, ///< LSB first.
};

/**
 * \brief Fixed configuration basic controller.
 *
 * \tparam Peripheral The type of peripheral used to implement fixed configuration
 *         controller functionality.
 */
template<typename Peripheral>
class Fixed_Configuration_Basic_Controller;

} // namespace picolibrary::Microchip::megaAVR::SPI

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR_SPI_H
