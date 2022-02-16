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
    _5 = ( Peripheral::USART::Normal::UCSRB::UCSZ_5_BIT << USART_DATA_BITS_UCSRB_UCSZ_OFFSET )
         | Peripheral::USART::Normal::UCSRC::UCSZ_5_BIT, ///< 5.
    _6 = ( Peripheral::USART::Normal::UCSRB::UCSZ_6_BIT << USART_DATA_BITS_UCSRB_UCSZ_OFFSET )
         | Peripheral::USART::Normal::UCSRC::UCSZ_6_BIT, ///< 6.
    _7 = ( Peripheral::USART::Normal::UCSRB::UCSZ_7_BIT << USART_DATA_BITS_UCSRB_UCSZ_OFFSET )
         | Peripheral::USART::Normal::UCSRC::UCSZ_7_BIT, ///< 7.
    _8 = ( Peripheral::USART::Normal::UCSRB::UCSZ_8_BIT << USART_DATA_BITS_UCSRB_UCSZ_OFFSET )
         | Peripheral::USART::Normal::UCSRC::UCSZ_8_BIT, ///< 8.
    _9 = ( Peripheral::USART::Normal::UCSRB::UCSZ_9_BIT << USART_DATA_BITS_UCSRB_UCSZ_OFFSET )
         | Peripheral::USART::Normal::UCSRC::UCSZ_9_BIT, ///< 9.
};

/**
 * \brief USART parity configuration.
 */
enum class USART_Parity : std::uint8_t {
    NONE = Peripheral::USART::Normal::UCSRC::UPM_DISABLED,            ///< None.
    EVEN = Peripheral::USART::Normal::UCSRC::UPM_ENABLED_EVEN_PARITY, ///< Even.
    ODD  = Peripheral::USART::Normal::UCSRC::UPM_ENABLED_ODD_PARITY,  ///< Odd.
};

/**
 * \brief USART stop bits.
 */
enum class USART_Stop_Bits : std::uint8_t {
    _1 = Peripheral::USART::Normal::UCSRC::USBS_1_BIT, ///< 1.
    _2 = Peripheral::USART::Normal::UCSRC::USBS_2_BIT, ///< 2.
};

/**
 * \brief USART clock generator operating speed.
 */
enum class USART_Clock_Generator_Operating_Speed : std::uint8_t {
    NORMAL = 0b0 << Peripheral::USART::Normal::UCSRA::Bit::U2X, ///< Normal.
    DOUBLE = 0b1 << Peripheral::USART::Normal::UCSRA::Bit::U2X, ///< Double.
};

} // namespace picolibrary::Microchip::megaAVR::Asynchronous_Serial

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR_ASYNCHRONOUS_SERIAL_H
