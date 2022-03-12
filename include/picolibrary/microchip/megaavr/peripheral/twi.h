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
 * \brief picolibrary::Microchip::megaAVR::Peripheral::TWI interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR_PERIPHERAL_TWI_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR_PERIPHERAL_TWI_H

#include <cstdint>

#include "picolibrary/bit_manipulation.h"
#include "picolibrary/microchip/megaavr/register.h"

namespace picolibrary::Microchip::megaAVR::Peripheral {

/**
 * \brief Microchip megaAVR 2-wire Serial Interface (TWI) peripheral.
 */
class TWI {
  public:
    /**
     * \brief TWI Control Register (TWCR) register.
     *
     * This register has the following fields:
     * - TWI Interrupt Enable (TWIE)
     * - TWI Enable Bit (TWEN)
     * - TWI Write Collision Flag (TWWC)
     * - TWI Stop Condition Bit (TWSTO)
     * - TWI Start Condition Bit (TWSTA)
     * - TWI Enable Acknowledge Bit (TWEA)
     * - TWI Interrupt Flag (TWINT)
     */
    class TWCR : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto TWIE      = std::uint_fast8_t{ 1 }; ///< TWIE.
            static constexpr auto RESERVED1 = std::uint_fast8_t{ 1 }; ///< RESERVED1.
            static constexpr auto TWEN      = std::uint_fast8_t{ 1 }; ///< TWEN.
            static constexpr auto TWWC      = std::uint_fast8_t{ 1 }; ///< TWWC.
            static constexpr auto TWSTO     = std::uint_fast8_t{ 1 }; ///< TWSTO.
            static constexpr auto TWSTA     = std::uint_fast8_t{ 1 }; ///< TWSTA.
            static constexpr auto TWEA      = std::uint_fast8_t{ 1 }; ///< TWEA.
            static constexpr auto TWINT     = std::uint_fast8_t{ 1 }; ///< TWINT.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto TWIE = std::uint_fast8_t{}; ///< TWIE.
            static constexpr auto RESERVED1 = std::uint_fast8_t{ TWIE + Size::TWIE }; ///< RESERVED1.
            static constexpr auto TWEN = std::uint_fast8_t{ RESERVED1 + Size::RESERVED1 }; ///< TWEN.
            static constexpr auto TWWC = std::uint_fast8_t{ TWEN + Size::TWEN }; ///< TWWC.
            static constexpr auto TWSTO = std::uint_fast8_t{ TWWC + Size::TWWC }; ///< TWSTO.
            static constexpr auto TWSTA = std::uint_fast8_t{ TWSTO + Size::TWSTO }; ///< TWSTA.
            static constexpr auto TWEA = std::uint_fast8_t{ TWSTA + Size::TWSTA }; ///< TWEA.
            static constexpr auto TWINT = std::uint_fast8_t{ TWEA + Size::TWEA }; ///< TWINT.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto TWIE = mask<std::uint8_t>( Size::TWIE, Bit::TWIE ); ///< TWIE.
            static constexpr auto RESERVED1 = mask<std::uint8_t>( Size::RESERVED1, Bit::RESERVED1 ); ///< RESERVED1.
            static constexpr auto TWEN = mask<std::uint8_t>( Size::TWEN, Bit::TWEN ); ///< TWEN.
            static constexpr auto TWWC = mask<std::uint8_t>( Size::TWWC, Bit::TWWC ); ///< TWWC.
            static constexpr auto TWSTO = mask<std::uint8_t>( Size::TWSTO, Bit::TWSTO ); ///< TWSTO.
            static constexpr auto TWSTA = mask<std::uint8_t>( Size::TWSTA, Bit::TWSTA ); ///< TWSTA.
            static constexpr auto TWEA = mask<std::uint8_t>( Size::TWEA, Bit::TWEA ); ///< TWEA.
            static constexpr auto TWINT = mask<std::uint8_t>( Size::TWINT, Bit::TWINT ); ///< TWINT.
        };

        TWCR() = delete;

        TWCR( TWCR && ) = delete;

        TWCR( TWCR const & ) = delete;

        ~TWCR() = delete;

        auto operator=( TWCR && ) = delete;

        auto operator=( TWCR const & ) = delete;

        using Register<std::uint8_t>::operator=;
    };

    /**
     * \brief TWI Status Register (TWSR) register.
     *
     * This register has the following fields:
     * - TWI Prescaler Bits (TWPS)
     * - TWI Status (TWS)
     */
    class TWSR : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto TWPS      = std::uint_fast8_t{ 2 }; ///< TWPS.
            static constexpr auto RESERVED2 = std::uint_fast8_t{ 1 }; ///< RESERVED2.
            static constexpr auto TWS       = std::uint_fast8_t{ 5 }; ///< TWS.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto TWPS = std::uint_fast8_t{}; ///< TWPS.
            static constexpr auto RESERVED2 = std::uint_fast8_t{ TWPS + Size::TWPS }; ///< RESERVED2.
            static constexpr auto TWS = std::uint_fast8_t{ RESERVED2 + Size::RESERVED2 }; ///< TWS.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto TWPS = mask<std::uint8_t>( Size::TWPS, Bit::TWPS ); ///< TWPS.
            static constexpr auto RESERVED2 = mask<std::uint8_t>( Size::RESERVED2, Bit::RESERVED2 ); ///< RESERVED2.
            static constexpr auto TWS = mask<std::uint8_t>( Size::TWS, Bit::TWS ); ///< TWS.
        };

        /**
         * \brief TWPS.
         */
        enum TWPS : std::uint8_t {
            TWPS_1  = 0b00 << Bit::TWPS, ///< 1.
            TWPS_4  = 0b01 << Bit::TWPS, ///< 4.
            TWPS_16 = 0b10 << Bit::TWPS, ///< 16.
            TWPS_64 = 0b11 << Bit::TWPS, ///< 64.
        };

        /**
         * \brief TWS.
         */
        enum TWS : std::uint8_t {
            TWS_CONTROLLER_START_CONDITION_TRANSMITTED = 0x08, ///< Controller mode: start condition transmitted.
            TWS_CONTROLLER_REPEATED_START_CONDITION_TRANSMITTED    = 0x10, ///< Controller mode: repeated start condition transmitted.
            TWS_CONTROLLER_ADDRESS_WRITE_TRANSMITTED_ACK_RECEIVED  = 0x18, ///< Controller mode: device address + write transmitted, ACK received.
            TWS_CONTROLLER_ADDRESS_WRITE_TRANSMITTED_NACK_RECEIVED = 0x20, ///< Controller mode: device address + write transmitted, NACK received.
            TWS_CONTROLLER_DATA_TRANSMITTED_ACK_RECEIVED           = 0x28, ///< Controller mode: data transmitted, ACK received.
            TWS_CONTROLLER_DATA_TRANSMITTED_NACK_RECEIVED          = 0x30, ///< Controller mode: data transmitted, NACK received.
            TWS_CONTROLLER_ARBITRATION_LOST = 0x38, ///< Controller mode: arbitration lost.
            TWS_CONTROLLER_ADDRESS_READ_TRANSMITTED_ACK_RECEIVED  = 0x40, ///< Controller mode: device address + read transmitted, ACK received.
            TWS_CONTROLLER_ADDRESS_READ_TRANSMITTED_NACK_RECEIVED = 0x48, ///< Controller mode: device address + read transmitted, NACK received.
            TWS_CONTROLLER_DATA_RECEIVED_ACK_TRANSMITTED          = 0x50, ///< Controller mode: data received, ACK transmitted.
            TWS_CONTROLLER_DATA_RECEIVED_NACK_TRANSMITTED         = 0x58, ///< Controller mode: data received, NACK transmitted.

            TWS_DEVICE_ADDRESS_WRITE_RECEIVED_ACK_TRANSMITTED                         = 0x60, ///< Device mode: device address + write received, ACK transmitted.
            TWS_DEVICE_ARBITRATION_LOST_ADDRESS_WRITE_RECEIVED_ACK_TRANSMITTED        = 0x68, ///< Device mode: arbitration lost, device address + write received, ACK transmitted.
            TWS_DEVICE_GENERAL_CALL_ADDRESS_RECEIVED_ACK_TRANSMITTED                  = 0x70, ///< Device mode: general call address received, ACK transmitted.
            TWS_DEVICE_ARBITRATION_LOST_GENERAL_CALL_ADDRESS_RECEIVED_ACK_TRANSMITTED = 0x78, ///< Device mode: arbitration lost, general call address received, ACK transmitted.
            TWS_DEVICE_DATA_RECEIVED_ACK_TRANSMITTED = 0x80, ///< Device mode: data received, ACK transmitted.
            TWS_DEVICE_DATA_RECEIVED_NACK_TRANSMITTED = 0x88, ///< Device mode: data received, NACK transmitted.
            TWS_DEVICE_GENERAL_CALL_DATA_RECEIVED_ACK_TRANSMITTED             = 0x90, ///< Device mode: general call, data received, ACK transmitted.
            TWS_DEVICE_GENERAL_CALL_DATA_RECEIVED_NACK_TRANSMITTED            = 0x98, ///< Device mode: general call, data received, NACK transmitted.
            TWS_DEVICE_STOP_CONDITION_OR_REPEATED_START_CONDITION_RECEIVED    = 0xA0, ///< device mode: stop condition or repeated start condition received.
            TWS_DEVICE_ADDRESS_READ_RECEIVED_ACK_TRANSMITTED                  = 0xA8, ///< Device mode: device address + read received, ACK transmitted.
            TWS_DEVICE_ARBITRATION_LOST_ADDRESS_READ_RECEIVED_ACK_TRANSMITTED = 0xB0, ///< Device mode: arbitration lost, device address + read received, ACK transmitted.
            TWS_DEVICE_DATA_TRANSMITTED_ACK_RECEIVED = 0xB8, ///< Device mode: data transmitted, ACK received.
            TWS_DEVICE_DATA_TRANSMITTED_NACK_RECEIVED = 0xC0, ///< Device mode: data transmitted, NACK received.
            TWS_DEVICE_ALL_DATA_TRANSMITTED_ACK_RECEIVED = 0xC8, ///< Device mode: all data transmitted, ACK received.

            TWS_NO_STATE_INFORMATION_AVAILABLE = 0xF8, ///< No state information available.
            TWS_BUS_ERROR = 0x00, ///< Bus error due to illegal start condition or stop condition.
        };

        TWSR() = delete;

        TWSR( TWSR && ) = delete;

        TWSR( TWSR const & ) = delete;

        ~TWSR() = delete;

        auto operator=( TWSR && ) = delete;

        auto operator=( TWSR const & ) = delete;

        using Register<std::uint8_t>::operator=;
    };

    /**
     * \brief TWI (Device) Address Register (TWAR) register.
     *
     * This register has the following fields:
     * - TWI General Call Recognition Enable Bit (TWGCE)
     * - TWI (Device) Address (TWA)
     */
    class TWAR : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto TWGCE = std::uint_fast8_t{ 1 }; ///< TWGCE.
            static constexpr auto TWA   = std::uint_fast8_t{ 7 }; ///< TWA.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto TWGCE = std::uint_fast8_t{}; ///< TWGCE.
            static constexpr auto TWA = std::uint_fast8_t{ TWGCE + Size::TWGCE }; ///< TWA.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto TWGCE = mask<std::uint8_t>( Size::TWGCE, Bit::TWGCE ); ///< TWGCE.
            static constexpr auto TWA = mask<std::uint8_t>( Size::TWA, Bit::TWA ); ///< TWA.
        };

        TWAR() = delete;

        TWAR( TWAR && ) = delete;

        TWAR( TWAR const & ) = delete;

        ~TWAR() = delete;

        auto operator=( TWAR && ) = delete;

        auto operator=( TWAR const & ) = delete;

        using Register<std::uint8_t>::operator=;
    };

    /**
     * \brief TWI (Device) Address Mask Register (TWAMR) register.
     *
     * This register has the following fields:
     * - TWI (Device) Address Mask (TWAM)
     */
    class TWAMR : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto RESERVED0 = std::uint_fast8_t{ 1 }; ///< RESERVED0.
            static constexpr auto TWAM      = std::uint_fast8_t{ 7 }; ///< TWAM.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto RESERVED0 = std::uint_fast8_t{}; ///< RESERVED0.
            static constexpr auto TWAM = std::uint_fast8_t{ RESERVED0 + Size::RESERVED0 }; ///< TWAM.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto RESERVED0 = mask<std::uint8_t>( Size::RESERVED0, Bit::RESERVED0 ); ///< RESERVED0.
            static constexpr auto TWAM = mask<std::uint8_t>( Size::TWAM, Bit::TWAM ); ///< TWAM.
        };

        TWAMR() = delete;

        TWAMR( TWAMR && ) = delete;

        TWAMR( TWAMR const & ) = delete;

        ~TWAMR() = delete;

        auto operator=( TWAMR && ) = delete;

        auto operator=( TWAMR const & ) = delete;

        using Register<std::uint8_t>::operator=;
    };

    /**
     * \brief TWI Bit Rate Register (TWBR) register.
     */
    Register<std::uint8_t> twbr;

    /**
     * \brief TWSR.
     */
    TWSR twsr;

    /**
     * \brief TWAR.
     */
    TWAR twar;

    /**
     * \brief TWI Data Register (TWDR) register.
     */
    Register<std::uint8_t> twdr;

    /**
     * \brief TWCR.
     */
    TWCR twcr;

    /**
     * \brief TWAMR.
     */
    TWAMR twamr;

    TWI() = delete;

    TWI( TWI && ) = delete;

    TWI( TWI const & ) = delete;

    ~TWI() = delete;

    auto operator=( TWI && ) = delete;

    auto operator=( TWI const & ) = delete;
};

} // namespace picolibrary::Microchip::megaAVR::Peripheral

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR_PERIPHERAL_TWI_H
