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
 * \brief picolibrary::Microchip::megaAVR::Peripheral::USART interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR_PERIPHERAL_USART_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR_PERIPHERAL_USART_H

#include <cstdint>

#include "picolibrary/bit_manipulation.h"
#include "picolibrary/microchip/megaavr/peripheral/instance.h"
#include "picolibrary/microchip/megaavr/register.h"

namespace picolibrary::Microchip::megaAVR::Peripheral {

/**
 * \brief Microchip megaAVR Universal Synchronous and Asynchronous Receiver and
 *        Transmitter (USART) peripheral.
 */
class USART {
  public:
    /**
     * \brief Normal mode.
     */
    class Normal {
      public:
        /**
         * \brief USART Control and Status Register A (UCSRA) register.
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
                static constexpr auto U2X = std::uint_fast8_t{ MPCM + Size::MPCM }; ///< U2X.
                static constexpr auto UPE = std::uint_fast8_t{ U2X + Size::U2X }; ///< UPE.
                static constexpr auto DOR = std::uint_fast8_t{ UPE + Size::UPE }; ///< DOR.
                static constexpr auto FE  = std::uint_fast8_t{ DOR + Size::DOR }; ///< FE.
                static constexpr auto UDRE = std::uint_fast8_t{ FE + Size::FE }; ///< UDRE.
                static constexpr auto TXC = std::uint_fast8_t{ UDRE + Size::UDRE }; ///< TXC.
                static constexpr auto RXC = std::uint_fast8_t{ TXC + Size::TXC }; ///< RXC.
            };

            /**
             * \brief Field bit masks.
             */
            struct Mask {
                static constexpr auto MPCM = mask<std::uint8_t>( Size::MPCM, Bit::MPCM ); ///< MPCM.
                static constexpr auto U2X = mask<std::uint8_t>( Size::U2X, Bit::U2X ); ///< U2X.
                static constexpr auto UPE = mask<std::uint8_t>( Size::UPE, Bit::UPE ); ///< UPE.
                static constexpr auto DOR = mask<std::uint8_t>( Size::DOR, Bit::DOR ); ///< DOR.
                static constexpr auto FE = mask<std::uint8_t>( Size::FE, Bit::FE ); ///< FE.
                static constexpr auto UDRE = mask<std::uint8_t>( Size::UDRE, Bit::UDRE ); ///< UDRE.
                static constexpr auto TXC = mask<std::uint8_t>( Size::TXC, Bit::TXC ); ///< TXC.
                static constexpr auto RXC = mask<std::uint8_t>( Size::RXC, Bit::RXC ); ///< RXC.
            };

            UCSRA() = delete;

            UCSRA( UCSRA && ) = delete;

            UCSRA( UCSRA const & ) = delete;

            ~UCSRA() = delete;

            auto operator=( UCSRA && ) = delete;

            auto operator=( UCSRA const & ) = delete;

            using Register<std::uint8_t>::operator=;
        };

        /**
         * \brief USART Control and Status Register B (UCSRB) register.
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
                static constexpr auto RXEN = std::uint_fast8_t{ TXEN + Size::TXEN }; ///< RXEN.
                static constexpr auto UDRIE = std::uint_fast8_t{ RXEN + Size::RXEN }; ///< UDRIE.
                static constexpr auto TXCIE = std::uint_fast8_t{ UDRIE + Size::UDRIE }; ///< TXCIE.
                static constexpr auto RXCIE = std::uint_fast8_t{ TXCIE + Size::TXCIE }; ///< RXCIE.
            };

            /**
             * \brief Field bit masks.
             */
            struct Mask {
                static constexpr auto TXB8 = mask<std::uint8_t>( Size::TXB8, Bit::TXB8 ); ///< TXB8.
                static constexpr auto RXB8 = mask<std::uint8_t>( Size::RXB8, Bit::RXB8 ); ///< RXB8.
                static constexpr auto UCSZ = mask<std::uint8_t>( Size::UCSZ, Bit::UCSZ ); ///< UCSZ.
                static constexpr auto TXEN = mask<std::uint8_t>( Size::TXEN, Bit::TXEN ); ///< TXEN.
                static constexpr auto RXEN = mask<std::uint8_t>( Size::RXEN, Bit::RXEN ); ///< RXEN.
                static constexpr auto UDRIE = mask<std::uint8_t>( Size::UDRIE, Bit::UDRIE ); ///< UDRIE.
                static constexpr auto TXCIE = mask<std::uint8_t>( Size::TXCIE, Bit::TXCIE ); ///< TXCIE.
                static constexpr auto RXCIE = mask<std::uint8_t>( Size::RXCIE, Bit::RXCIE ); ///< RXCIE.
            };

            /**
             * \brief enum class field offsets
             */
            struct Offset {
                static constexpr auto UCSZ = std::uint_fast8_t{ 1 }; ///< UCSZ.
            };

            UCSRB() = delete;

            UCSRB( UCSRB && ) = delete;

            UCSRB( UCSRB const & ) = delete;

            ~UCSRB() = delete;

            auto operator=( UCSRB && ) = delete;

            auto operator=( UCSRB const & ) = delete;

            using Register<std::uint8_t>::operator=;
        };

        /**
         * \brief USART Control and Status Register C (UCSRC) register.
         *
         * This register has the following fields:
         * - USART Clock Polarity (UCPOL)
         * - USART Character Size Bits 0 and 1 (UCSZ)
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
            };

            /**
             * \brief Field bit positions.
             */
            struct Bit {
                static constexpr auto UCPOL = std::uint_fast8_t{}; ///< UCPOL.
                static constexpr auto UCSZ = std::uint_fast8_t{ UCPOL + Size::UCPOL }; ///< UCSZ.
                static constexpr auto USBS = std::uint_fast8_t{ UCSZ + Size::UCSZ }; ///< USBS.
                static constexpr auto UPM = std::uint_fast8_t{ USBS + Size::USBS }; ///< UPM.
                static constexpr auto UMSEL = std::uint_fast8_t{ UPM + Size::UPM }; ///< UMSEL.
            };

            /**
             * \brief Field bit masks.
             */
            struct Mask {
                static constexpr auto UCPOL = mask<std::uint8_t>( Size::UCPOL, Bit::UCPOL ); ///< UCPOL.
                static constexpr auto UCSZ = mask<std::uint8_t>( Size::UCSZ, Bit::UCSZ ); ///< UCSZ.
                static constexpr auto USBS = mask<std::uint8_t>( Size::USBS, Bit::USBS ); ///< USBS.
                static constexpr auto UPM = mask<std::uint8_t>( Size::UPM, Bit::UPM ); ///< UPM.
                static constexpr auto UMSEL = mask<std::uint8_t>( Size::UMSEL, Bit::UMSEL ); ///< UMSEL.
            };

            UCSRC() = delete;

            UCSRC( UCSRC && ) = delete;

            UCSRC( UCSRC const & ) = delete;

            ~UCSRC() = delete;

            auto operator=( UCSRC && ) = delete;

            auto operator=( UCSRC const & ) = delete;

            using Register<std::uint8_t>::operator=;
        };

        /**
         * \brief USART mode.
         */
        enum class Mode : std::uint8_t {
            ASYNCHRONOUS_USART = 0b00 << UCSRC::Bit::UMSEL, ///< Asynchronous USART.
            SYNCHRONOUS_USART  = 0b01 << UCSRC::Bit::UMSEL, ///< Synchronous USART.
        };

        /**
         * \brief Clock generator operating speed.
         */
        enum class Operating_Speed : std::uint8_t {
            NORMAL = 0b0 << UCSRA::Bit::U2X, ///< Normal.
            DOUBLE = 0b1 << UCSRA::Bit::U2X, ///< Double.
        };

        /**
         * \brief Data bits.
         */
        enum class Data_Bits : std::uint8_t {
            _5 = ( 0b0 << ( UCSRB::Bit::UCSZ + UCSRB::Offset::UCSZ ) ) | ( 0b00 << UCSRC::Bit::UCSZ ), ///< 5.
            _6 = ( 0b0 << ( UCSRB::Bit::UCSZ + UCSRB::Offset::UCSZ ) ) | ( 0b01 << UCSRC::Bit::UCSZ ), ///< 6.
            _7 = ( 0b0 << ( UCSRB::Bit::UCSZ + UCSRB::Offset::UCSZ ) ) | ( 0b10 << UCSRC::Bit::UCSZ ), ///< 7.
            _8 = ( 0b0 << ( UCSRB::Bit::UCSZ + UCSRB::Offset::UCSZ ) ) | ( 0b11 << UCSRC::Bit::UCSZ ), ///< 8.
            _9 = ( 0b1 << ( UCSRB::Bit::UCSZ + UCSRB::Offset::UCSZ ) ) | ( 0b11 << UCSRC::Bit::UCSZ ), ///< 9.
        };

        /**
         * \brief Parity mode.
         */
        enum class Parity : std::uint8_t {
            NONE = 0b00 << UCSRC::Bit::UPM, ///< None.
            EVEN = 0b10 << UCSRC::Bit::UPM, ///< Even.
            ODD  = 0b11 << UCSRC::Bit::UPM, ///< Odd.
        };

        /**
         * \brief Stop bits.
         */
        enum class Stop_Bits : std::uint8_t {
            _1 = 0b0 << UCSRC::Bit::USBS, ///< 1.
            _2 = 0b1 << UCSRC::Bit::USBS, ///< 2.
        };

        /**
         * \brief Clock polarity.
         */
        enum class Clock_Polarity : std::uint8_t {
            IDLE_LOW  = 0b0 << UCSRC::Bit::UCPOL, ///< Idle low.
            IDLE_HIGH = 0b1 << UCSRC::Bit::UCPOL, ///< Idle high.
        };

        /**
         * \brief Multi-processor communication mode frame type.
         */
        enum class Frame_Type : std::uint8_t {
            DATA    = 0b0 << UCSRA::Bit::MPCM, ///< Data.
            ADDRESS = 0b1 << UCSRA::Bit::MPCM, ///< Address.
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
         * \brief Reserved registers.
         */
        Reserved_Register<std::uint8_t> const reserved[ 1 ];

        /**
         * \brief USART Baud Rate Register (UBRR).
         */
        Register<std::uint16_t> ubrr;

        /**
         * \brief USART I/O Data Register (UDR).
         */
        Register<std::uint8_t> udr;

        Normal() = delete;

        Normal( Normal && ) = delete;

        Normal( Normal const & ) = delete;

        ~Normal() = delete;

        auto operator=( Normal && ) = delete;

        auto operator=( Normal const & ) = delete;
    };

    /**
     * \brief Serial Peripheral Interface (SPI) controller mode.
     */
    class SPI_Controller {
      public:
        /**
         * \brief USART Control and Status Register A (UCSRA) register.
         *
         * This register has the following fields:
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
                static constexpr auto RESERVED0 = std::uint_fast8_t{ 5 }; ///< RESERVED0.
                static constexpr auto UDRE      = std::uint_fast8_t{ 1 }; ///< UDRE.
                static constexpr auto TXC       = std::uint_fast8_t{ 1 }; ///< TXC.
                static constexpr auto RXC       = std::uint_fast8_t{ 1 }; ///< RXC.
            };

            /**
             * \brief Field bit positions.
             */
            struct Bit {
                static constexpr auto RESERVED0 = std::uint_fast8_t{}; ///< RESERVED0.
                static constexpr auto UDRE = std::uint_fast8_t{ RESERVED0 + Size::RESERVED0 }; ///< UDRE.
                static constexpr auto TXC = std::uint_fast8_t{ UDRE + Size::UDRE }; ///< TXC.
                static constexpr auto RXC = std::uint_fast8_t{ TXC + Size::TXC }; ///< RXC.
            };

            /**
             * \brief Field bit masks.
             */
            struct Mask {
                static constexpr auto RESERVED0 = mask<std::uint8_t>( Size::RESERVED0, Bit::RESERVED0 ); ///< RESERVED0.
                static constexpr auto UDRE = mask<std::uint8_t>( Size::UDRE, Bit::UDRE ); ///< UDRE.
                static constexpr auto TXC = mask<std::uint8_t>( Size::TXC, Bit::TXC ); ///< TXC.
                static constexpr auto RXC = mask<std::uint8_t>( Size::RXC, Bit::RXC ); ///< RXC.
            };

            UCSRA() = delete;

            UCSRA( UCSRA && ) = delete;

            UCSRA( UCSRA const & ) = delete;

            ~UCSRA() = delete;

            auto operator=( UCSRA && ) = delete;

            auto operator=( UCSRA const & ) = delete;

            using Register<std::uint8_t>::operator=;
        };

        /**
         * \brief USART Control and Status Register B (UCSRB) register.
         *
         * This register has the following fields:
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
                static constexpr auto RESERVED0 = std::uint_fast8_t{ 3 }; ///< RESERVED0.
                static constexpr auto TXEN      = std::uint_fast8_t{ 1 }; ///< TXEN.
                static constexpr auto RXEN      = std::uint_fast8_t{ 1 }; ///< RXEN.
                static constexpr auto UDRIE     = std::uint_fast8_t{ 1 }; ///< UDRIE.
                static constexpr auto TXCIE     = std::uint_fast8_t{ 1 }; ///< TXCIE.
                static constexpr auto RXCIE     = std::uint_fast8_t{ 1 }; ///< RXCIE.
            };

            /**
             * \brief Field bit positions.
             */
            struct Bit {
                static constexpr auto RESERVED0 = std::uint_fast8_t{}; ///< RESERVED0.
                static constexpr auto TXEN = std::uint_fast8_t{ RESERVED0 + Size::RESERVED0 }; ///< TXEN.
                static constexpr auto RXEN = std::uint_fast8_t{ TXEN + Size::TXEN }; ///< RXEN.
                static constexpr auto UDRIE = std::uint_fast8_t{ RXEN + Size::RXEN }; ///< UDRIE.
                static constexpr auto TXCIE = std::uint_fast8_t{ UDRIE + Size::UDRIE }; ///< TXCIE.
                static constexpr auto RXCIE = std::uint_fast8_t{ TXCIE + Size::TXCIE }; ///< RXCIE.
            };

            /**
             * \brief Field bit masks.
             */
            struct Mask {
                static constexpr auto RESERVED0 = mask<std::uint8_t>( Size::RESERVED0, Bit::RESERVED0 ); ///< RESERVED0.
                static constexpr auto TXEN = mask<std::uint8_t>( Size::TXEN, Bit::TXEN ); ///< TXEN.
                static constexpr auto RXEN = mask<std::uint8_t>( Size::RXEN, Bit::RXEN ); ///< RXEN.
                static constexpr auto UDRIE = mask<std::uint8_t>( Size::UDRIE, Bit::UDRIE ); ///< UDRIE.
                static constexpr auto TXCIE = mask<std::uint8_t>( Size::TXCIE, Bit::TXCIE ); ///< TXCIE.
                static constexpr auto RXCIE = mask<std::uint8_t>( Size::RXCIE, Bit::RXCIE ); ///< RXCIE.
            };

            UCSRB() = delete;

            UCSRB( UCSRB && ) = delete;

            UCSRB( UCSRB const & ) = delete;

            ~UCSRB() = delete;

            auto operator=( UCSRB && ) = delete;

            auto operator=( UCSRB const & ) = delete;

            using Register<std::uint8_t>::operator=;
        };

        /**
         * \brief USART Control and Status Register C (UCSRC) register.
         *
         * This register has the following fields:
         * - USART Clock Polarity (UCPOL)
         * - USART Clock Phase (UCPHA)
         * - USART Data Order (UDORD)
         * - USART Mode Select (UMSEL)
         */
        class UCSRC : public Register<std::uint8_t> {
          public:
            /**
             * \brief Field sizes.
             */
            struct Size {
                static constexpr auto UCPOL     = std::uint_fast8_t{ 1 }; ///< UCPOL.
                static constexpr auto UCPHA     = std::uint_fast8_t{ 1 }; ///< UCPHA.
                static constexpr auto UDORD     = std::uint_fast8_t{ 1 }; ///< UDORD.
                static constexpr auto RESERVED3 = std::uint_fast8_t{ 3 }; ///< RESERVED3.
                static constexpr auto UMSEL     = std::uint_fast8_t{ 2 }; ///< UMSEL.
            };

            /**
             * \brief Field bit positions.
             */
            struct Bit {
                static constexpr auto UCPOL = std::uint_fast8_t{}; ///< UCPOL.
                static constexpr auto UCPHA = std::uint_fast8_t{ UCPOL + Size::UCPOL }; ///< UCPHA.
                static constexpr auto UDORD = std::uint_fast8_t{ UCPHA + Size::UCPHA }; ///< UCPHA.
                static constexpr auto RESERVED3 = std::uint_fast8_t{ UDORD + Size::UDORD }; ///< UDORD.
                static constexpr auto UMSEL = std::uint_fast8_t{ RESERVED3 + Size::RESERVED3 }; ///< UMSEL.
            };

            /**
             * \brief Field bit masks.
             */
            struct Mask {
                static constexpr auto UCPOL = mask<std::uint8_t>( Size::UCPOL, Bit::UCPOL ); ///< UCPOL.
                static constexpr auto UCPHA = mask<std::uint8_t>( Size::UCPHA, Bit::UCPHA ); ///< UCPHA.
                static constexpr auto UDORD = mask<std::uint8_t>( Size::UDORD, Bit::UDORD ); ///< UDORD.
                static constexpr auto RESERVED3 = mask<std::uint8_t>( Size::RESERVED3, Bit::RESERVED3 ); ///< RESERVED3.
                static constexpr auto UMSEL = mask<std::uint8_t>( Size::UMSEL, Bit::UMSEL ); ///< UMSEL.
            };

            UCSRC() = delete;

            UCSRC( UCSRC && ) = delete;

            UCSRC( UCSRC const & ) = delete;

            ~UCSRC() = delete;

            auto operator=( UCSRC && ) = delete;

            auto operator=( UCSRC const & ) = delete;

            using Register<std::uint8_t>::operator=;
        };

        /**
         * \brief USART mode.
         */
        enum class Mode : std::uint8_t {
            SPI_CONTROLLER = 0b11 << UCSRC::Bit::UMSEL, ///< SPI controller.
        };

        /**
         * \brief Clock polarity.
         */
        enum class Clock_Polarity : std::uint8_t {
            IDLE_LOW  = 0b0 << UCSRC::Bit::UCPOL, ///< Idle low.
            IDLE_HIGH = 0b1 << UCSRC::Bit::UCPOL, ///< Idle high.
        };

        /**
         * \brief Clock phase.
         */
        enum class Clock_Phase : std::uint8_t {
            CAPTURE_IDLE_TO_ACTIVE = 0b0 << UCSRC::Bit::UCPHA, ///< Capture data on the idle-to-active clock transition.
            CAPTURE_ACTIVE_TO_IDLE = 0b1 << UCSRC::Bit::UCPHA, ///< Capture data on the active-to-idle clock transition.
        };

        /**
         * \brief Data exchange bit order.
         */
        enum class Bit_Order : std::uint8_t {
            MSB_FIRST = 0b0 << UCSRC::Bit::UDORD, ///< Exchange data MSB first.
            LSB_FIRST = 0b1 << UCSRC::Bit::UDORD, ///< Exchange data LSB first.
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
         * \brief Reserved registers.
         */
        Reserved_Register<std::uint8_t> const reserved[ 1 ];

        /**
         * \brief USART Baud Rate Register (UBRR).
         */
        Register<std::uint16_t> ubrr;

        /**
         * \brief USART I/O Data Register (UDR).
         */
        Register<std::uint8_t> udr;

        SPI_Controller() = delete;

        SPI_Controller( SPI_Controller && ) = delete;

        SPI_Controller( SPI_Controller const & ) = delete;

        ~SPI_Controller() = delete;

        auto operator=( SPI_Controller && ) = delete;

        auto operator=( SPI_Controller const & ) = delete;
    };

    union {
        /**
         * \brief Normal mode.
         */
        Normal normal;

        /**
         * \brief SPI controller mode.
         */
        SPI_Controller spi_controller;
    };

    USART() = delete;

    USART( USART && ) = delete;

    USART( USART const & ) = delete;

    ~USART() = delete;

    auto operator=( USART && ) = delete;

    auto operator=( USART const & ) = delete;
};

/**
 * \brief Microchip megaAVR Universal Synchronous and Asynchronous Receiver and
 *        Transmitter (USART) peripheral instance.
 *
 * \tparam INSTANCE_ADDRESS The address of the USART peripheral instance.
 */
template<std::uintptr_t INSTANCE_ADDRESS>
using USART_Instance = Instance<USART, INSTANCE_ADDRESS>;

} // namespace picolibrary::Microchip::megaAVR::Peripheral

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR_PERIPHERAL_USART_H
