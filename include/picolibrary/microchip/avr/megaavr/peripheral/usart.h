/**
 * picolibrary-microchip-avr-megaavr
 *
 * Copyright 2020 Andrew Countryman <apcountryman@gmail.com>
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
 * \brief picolibrary::Microchip::AVR::megaAVR::Peripheral::USART interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_AVR_MEGAAVR_PERIPHERAL_USART_H
#define PICOLIBRARY_MICROCHIP_AVR_MEGAAVR_PERIPHERAL_USART_H

#include <cstdint>

#include "picolibrary/microchip/avr/megaavr/register.h"

namespace picolibrary::Microchip::AVR::megaAVR::Peripheral {

/**
 * \brief Microchip AVR megaAVR Universal Synchronous Asynchronous Receiver Transciever
 *        (USART) peripheral.
 */
class USART {
  public:
    /**
     * \brief USART Control and Status Register A (UCSRA).
     *
     * This register has the following fields:
     * - Multi-Processor Communication Mode (MPCM)
     * - Double USART Speed (U2X)
     * - USART Parity Error (UPE)
     * - Data Overrun (DOR)
     * - Frame Error (FE)
     * - USART Data Register Empty (UDRE)
     * - USART Transmit Complete (TXC)
     * - USART Receive Complete (RXC)
     */
    class UCSRA : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto MPCM = std::uint_fast8_t{ 1 }; ///< MPCM.
            static constexpr auto U2X  = std::uint_fast8_t{ 1 }; ///< U2X.
            static constexpr auto UPE  = std::uint_fast8_t{ 1 }; ///< UPE.
            static constexpr auto DOR  = std::uint_fast8_t{ 1 }; ///< DOR.
            static constexpr auto FE   = std::uint_fast8_t{ 1 }; ///< FE.
            static constexpr auto UDRE = std::uint_fast8_t{ 1 }; ///< UDRE.
            static constexpr auto TXC  = std::uint_fast8_t{ 1 }; ///< TXC.
            static constexpr auto RXC  = std::uint_fast8_t{ 1 }; ///< RXC.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto MPCM = std::uint_fast8_t{}; ///< MPCM.
            static constexpr auto U2X  = std::uint_fast8_t{ MPCM + Size::MPCM }; ///< U2X.
            static constexpr auto UPE  = std::uint_fast8_t{ U2X + Size::U2X };   ///< UPE.
            static constexpr auto DOR  = std::uint_fast8_t{ UPE + Size::UPE };   ///< DOR.
            static constexpr auto FE   = std::uint_fast8_t{ DOR + Size::DOR };   ///< FE.
            static constexpr auto UDRE = std::uint_fast8_t{ FE + Size::FE }; ///< UDRE.
            static constexpr auto TXC  = std::uint_fast8_t{ UDRE + Size::UDRE }; ///< TXC.
            static constexpr auto RXC  = std::uint_fast8_t{ TXC + Size::TXC };   ///< TXC.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto MPCM = std::uint_fast8_t{ 0b1 << Bit::MPCM }; ///< MPCM.
            static constexpr auto U2X  = std::uint_fast8_t{ 0b1 << Bit::U2X };  ///< U2X.
            static constexpr auto UPE  = std::uint_fast8_t{ 0b1 << Bit::UPE };  ///< UPE.
            static constexpr auto DOR  = std::uint_fast8_t{ 0b1 << Bit::DOR };  ///< DOR.
            static constexpr auto FE   = std::uint_fast8_t{ 0b1 << Bit::FE };   ///< FE.
            static constexpr auto UDRE = std::uint_fast8_t{ 0b1 << Bit::UDRE }; ///< UDRE.
            static constexpr auto TXC  = std::uint_fast8_t{ 0b1 << Bit::TXC };  ///< TXC.
            static constexpr auto RXC  = std::uint_fast8_t{ 0b1 << Bit::RXC };  ///< RXC.
        };

        UCSRA() = delete;

        /**
         * \todo #27
         */
        UCSRA( UCSRA && ) = delete;

        /**
         * \todo #27
         */
        UCSRA( UCSRA const & ) = delete;

        ~UCSRA() = delete;

        /**
         * \todo #27
         *
         * \return
         */
        auto operator=( UCSRA && ) = delete;

        /**
         * \todo #27
         *
         * \return
         */
        auto operator=( UCSRA const & ) = delete;
    };

    /**
     * \brief USART Control and Status Register B (UCSRB).
     *
     * This register has the following fields:
     * - Transmit Data Bit 8 (TXB8)
     * - Receive Data Bit 8 (RXB8)
     * - Character Size Bit 2 (UCSZ2) (referred to as UCSZ within this class)
     * - Transmitter Enable (TXEN)
     * - Receiver Enable (RXEN)
     * - USART Data Register Empty Interrupt Enable (UDRIE)
     * - Transmit Complete Interrupt Enable (TXCIE)
     * - Receive Complete Interrupt Enable (RXCIE)
     */
    class UCSRB : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto TXB8  = std::uint_fast8_t{ 1 }; ///< TXB8.
            static constexpr auto RXB8  = std::uint_fast8_t{ 1 }; ///< RXB8.
            static constexpr auto UCSZ  = std::uint_fast8_t{ 1 }; ///< UCSZ.
            static constexpr auto TXEN  = std::uint_fast8_t{ 1 }; ///< TXEN.
            static constexpr auto RXEN  = std::uint_fast8_t{ 1 }; ///< RXEN.
            static constexpr auto UDRIE = std::uint_fast8_t{ 1 }; ///< UDRIE.
            static constexpr auto TXCIE = std::uint_fast8_t{ 1 }; ///< TXCIE.
            static constexpr auto RXCIE = std::uint_fast8_t{ 1 }; ///< RXCIE.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto TXB8 = std::uint_fast8_t{}; ///< TXB8.
            static constexpr auto RXB8 = std::uint_fast8_t{ TXB8 + Size::TXB8 }; ///< RXB8.
            static constexpr auto UCSZ = std::uint_fast8_t{ RXB8 + Size::RXB8 }; ///< UCSZ.
            static constexpr auto TXEN = std::uint_fast8_t{ UCSZ + Size::UCSZ }; ///< TXEN.
            static constexpr auto RXEN = std::uint_fast8_t{ TXEN + Size::TXEN }; ///< TXEN.
            static constexpr auto UDRIE = std::uint_fast8_t{ RXEN + Size::RXEN }; ///< UDRIE.
            static constexpr auto TXCIE = std::uint_fast8_t{ UDRIE + Size::UDRIE }; ///< TXCIE.
            static constexpr auto RXCIE = std::uint_fast8_t{ TXCIE + Size::TXCIE }; ///< TXCIE.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto TXB8 = std::uint_fast8_t{ 0b1 << Bit::TXB8 }; ///< TXB8.
            static constexpr auto RXB8 = std::uint_fast8_t{ 0b1 << Bit::RXB8 }; ///< RXB8.
            static constexpr auto UCSZ = std::uint_fast8_t{ 0b1 << Bit::UCSZ }; ///< UCSZ.
            static constexpr auto TXEN = std::uint_fast8_t{ 0b1 << Bit::TXEN }; ///< TXEN.
            static constexpr auto RXEN = std::uint_fast8_t{ 0b1 << Bit::RXEN }; ///< RXEN.
            static constexpr auto UDRIE = std::uint_fast8_t{ 0b1 << Bit::UDRIE }; ///< UDRIE.
            static constexpr auto TXCIE = std::uint_fast8_t{ 0b1 << Bit::TXCIE }; ///< TXCIE.
            static constexpr auto RXCIE = std::uint_fast8_t{ 0b1 << Bit::RXCIE }; ///< RXCIE.
        };

        UCSRB() = delete;

        /**
         * \todo #27
         */
        UCSRB( UCSRB && ) = delete;

        /**
         * \todo #27
         */
        UCSRB( UCSRB const & ) = delete;

        ~UCSRB() = delete;

        /**
         * \todo #27
         *
         * \return
         */
        auto operator=( UCSRB && ) = delete;

        /**
         * \todo #27
         *
         * \return
         */
        auto operator=( UCSRB const & ) = delete;
    };

    /**
     * \brief USART Control and Status Register A (UCSRC).
     *
     * This register has the following fields:
     * - USART Clock Polarity (UCPOL)
     * - USART Character Size Bits 0 and 1 (UCSZ)
     * - USART Clock Phase (UCPHA)
     * - USART Data Order (UDORD)
     * - USART Stop Bit Select (USBS)
     * - USART Parity Mode (UPM)
     * - USART Mode Select (UMSEL)
     */
    class UCSRC : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto UCPOL = std::uint_fast8_t{ 1 }; ///< UCPOL.
            static constexpr auto UCSZ  = std::uint_fast8_t{ 2 }; ///< UCSZ.
            static constexpr auto USBS  = std::uint_fast8_t{ 1 }; ///< USBS.
            static constexpr auto UPM   = std::uint_fast8_t{ 2 }; ///< UPM.
            static constexpr auto UMSEL = std::uint_fast8_t{ 2 }; ///< UMSEL.

            static constexpr auto UCPHA = std::uint_fast8_t{ 1 }; ///< UCPHA.
            static constexpr auto UDORD = std::uint_fast8_t{ 1 }; ///< UDORD.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto UCPOL = std::uint_fast8_t{}; ///< UCPOL.
            static constexpr auto UCSZ = std::uint_fast8_t{ UCPOL + Size::UCPOL }; ///< UCSZ.
            static constexpr auto USBS = std::uint_fast8_t{ UCSZ + Size::UCSZ }; ///< USBS.
            static constexpr auto UPM  = std::uint_fast8_t{ USBS + Size::USBS }; ///< UPM.
            static constexpr auto UMSEL = std::uint_fast8_t{ UPM + Size::UPM }; ///< UMSEL.

            static constexpr auto UCPHA = std::uint_fast8_t{ UCPOL + Size::UCPOL }; ///< UCPHA.
            static constexpr auto UDORD = std::uint_fast8_t{ UCPHA + Size::UCPHA }; ///< UDORD.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto UCPOL = std::uint_fast8_t{ 0b1 << Bit::UCPOL }; ///< UCPOL.
            static constexpr auto UCSZ = std::uint_fast8_t{ 0b11 << Bit::UCSZ }; ///< UCSZ.
            static constexpr auto USBS = std::uint_fast8_t{ 0b1 << Bit::USBS }; ///< USBS.
            static constexpr auto UPM  = std::uint_fast8_t{ 0b11 << Bit::UPM }; ///< UPM.
            static constexpr auto UMSEL = std::uint_fast8_t{ 0b11 << Bit::UMSEL }; ///< UMSEL.

            static constexpr auto UCPHA = std::uint_fast8_t{ 0b1 << Bit::UCPHA }; ///< UCPHA.
            static constexpr auto UDORD = std::uint_fast8_t{ 0b1 << Bit::UDORD }; ///< UDORD.
        };

        UCSRC() = delete;

        /**
         * \todo #27
         */
        UCSRC( UCSRC && ) = delete;

        /**
         * \todo #27
         */
        UCSRC( UCSRC const & ) = delete;

        ~UCSRC() = delete;

        /**
         * \todo #27
         *
         * \return
         */
        auto operator=( UCSRC && ) = delete;

        /**
         * \todo #27
         *
         * \return
         */
        auto operator=( UCSRC const & ) = delete;
    };

    /**
     * \brief UCSRA.
     */
    UCSRA ucsra;

    /**
     * \brief UCSRB.
     */
    UCSRB ucsrb;

    /**
     * \brief UCSRC.
     */
    UCSRC ucsrc;

    /**
     * \brief Reserved register.
     */
    Reserved_Register<std::uint8_t> const reserved;

    /**
     * \brief USART Baud Rate Register (UBRR).
     */
    Register<std::uint16_t> ubrr;

    /**
     * \brief USART Data Register (UDR).
     */
    Register<std::uint8_t> udr;

    USART() = delete;

    /**
     * \todo #27
     */
    USART( USART && ) = delete;

    /**
     * \todo #27
     */
    USART( USART const & ) = delete;

    ~USART() = delete;

    /**
     * \todo #27
     *
     * \return
     */
    auto operator=( USART && ) = delete;

    /**
     * \todo #27
     *
     * \return
     */
    auto operator=( USART const & ) = delete;
};

} // namespace picolibrary::Microchip::AVR::megaAVR::Peripheral

#endif // PICOLIBRARY_MICROCHIP_AVR_MEGAAVR_PERIPHERAL_USART_H
