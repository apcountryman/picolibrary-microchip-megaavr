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
 * \brief picolibrary::Microchip::megaAVR::Asynchronous_Serial interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR_ASYNCHRONOUS_SERIAL_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR_ASYNCHRONOUS_SERIAL_H

#include <cstdint>

#include "picolibrary/microchip/megaavr/peripheral/usart.h"

/**
 * \brief Microchip megaAVR asynchronous serial facilities.
 */
namespace picolibrary::Microchip::megaAVR::Asynchronous_Serial {

/**
 * \brief USART data bits configuration UCSRB register UCSZ field offset.
 */
constexpr auto USART_DATA_BITS_UCSRB_UCSZ_OFFSET = std::uint_fast8_t{ 1 };

/**
 * \brief USART data bits configuration.
 */
enum class USART_Data_Bits : std::uint_fast8_t {
    _5 = ( 0b0 << ( Peripheral::USART::Normal::UCSRB::Bit::UCSZ + USART_DATA_BITS_UCSRB_UCSZ_OFFSET ) )
         | ( 0b00 << Peripheral::USART::Normal::UCSRC::Bit::UCSZ ), ///< 5.
    _6 = ( 0b0 << ( Peripheral::USART::Normal::UCSRB::Bit::UCSZ + USART_DATA_BITS_UCSRB_UCSZ_OFFSET ) )
         | ( 0b01 << Peripheral::USART::Normal::UCSRC::Bit::UCSZ ), ///< 6.
    _7 = ( 0b0 << ( Peripheral::USART::Normal::UCSRB::Bit::UCSZ + USART_DATA_BITS_UCSRB_UCSZ_OFFSET ) )
         | ( 0b10 << Peripheral::USART::Normal::UCSRC::Bit::UCSZ ), ///< 7.
    _8 = ( 0b0 << ( Peripheral::USART::Normal::UCSRB::Bit::UCSZ + USART_DATA_BITS_UCSRB_UCSZ_OFFSET ) )
         | ( 0b11 << Peripheral::USART::Normal::UCSRC::Bit::UCSZ ), ///< 8.
    _9 = ( 0b1 << ( Peripheral::USART::Normal::UCSRB::Bit::UCSZ + USART_DATA_BITS_UCSRB_UCSZ_OFFSET ) )
         | ( 0b11 << Peripheral::USART::Normal::UCSRC::Bit::UCSZ ), ///< 9.
};

} // namespace picolibrary::Microchip::megaAVR::Asynchronous_Serial

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR_ASYNCHRONOUS_SERIAL_H
