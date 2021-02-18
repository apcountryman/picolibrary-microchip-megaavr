/**
 * picolibrary-microchip-megaavr
 *
 * Copyright 2020-2021, Andrew Countryman <apcountryman@gmail.com> and the
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

#include "picolibrary/microchip/megaavr/peripheral/instance.h"
#include "picolibrary/microchip/megaavr/register.h"

namespace picolibrary::Microchip::megaAVR::Peripheral {

/**
 * \brief Microchip megaAVR 2-wire Serial Interface (TWI) peripheral.
 */
class TWI {
  public:
    enum class Prescaler : std::uint8_t;

    enum class Status : std::uint8_t;

    enum class General_Call_Recognition : std::uint8_t;

    /**
     * \brief TWI Control Register (TWCR).
     *
     * This register has the following fields:
     * - TWI Interrupt Enable (TWIE)
     * - TWI Enable (TWEN)
     * - TWI Write Collision (TWWC)
     * - TWI Stop Condition (TWSTO)
     * - TWI Start Condition (TWSTA)
     * - TWI Enable Acknowledge (TWEA)
     * - TWI Interrupt (TWINT)
     */
    class TWCR : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto TWIE     = std::uint_fast8_t{ 1 }; ///< TWIE.
            static constexpr auto RESERVED = std::uint_fast8_t{ 1 }; ///< Reserved.
            static constexpr auto TWEN     = std::uint_fast8_t{ 1 }; ///< TWEN.
            static constexpr auto TWWC     = std::uint_fast8_t{ 1 }; ///< TWWC.
            static constexpr auto TWSTO    = std::uint_fast8_t{ 1 }; ///< TWSTO.
            static constexpr auto TWSTA    = std::uint_fast8_t{ 1 }; ///< TWSTA.
            static constexpr auto TWEA     = std::uint_fast8_t{ 1 }; ///< TWEA.
            static constexpr auto TWINT    = std::uint_fast8_t{ 1 }; ///< TWINT.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto TWIE = std::uint_fast8_t{}; ///< TWIE.
            static constexpr auto RESERVED = std::uint_fast8_t{ TWIE + Size::TWIE }; ///< Reserved.
            static constexpr auto TWEN = std::uint_fast8_t{ RESERVED + Size::RESERVED }; ///< TWEN.
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
            static constexpr auto TWIE = std::uint8_t{ 0b1 << Bit::TWIE }; ///< TWIE.
            static constexpr auto RESERVED = std::uint8_t{ 0b1 << Bit::RESERVED }; ///< Reserved.
            static constexpr auto TWEN  = std::uint8_t{ 0b1 << Bit::TWEN };  ///< TWEN.
            static constexpr auto TWWC  = std::uint8_t{ 0b1 << Bit::TWWC };  ///< TWWC.
            static constexpr auto TWSTO = std::uint8_t{ 0b1 << Bit::TWSTO }; ///< TWSTO.
            static constexpr auto TWSTA = std::uint8_t{ 0b1 << Bit::TWSTA }; ///< TWSTA.
            static constexpr auto TWEA  = std::uint8_t{ 0b1 << Bit::TWEA };  ///< TWEA.
            static constexpr auto TWINT = std::uint8_t{ 0b1 << Bit::TWINT }; ///< TWINT.
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
     * \brief TWI Status Register (TWSR).
     *
     * This register has the following fields:
     * - TWI Prescaler (TWPS)
     * - TWI Status (TWS)
     */
    class TWSR : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto TWPS     = std::uint_fast8_t{ 2 }; ///< TWPS.
            static constexpr auto RESERVED = std::uint_fast8_t{ 1 }; ///< Reserved.
            static constexpr auto TWS      = std::uint_fast8_t{ 5 }; ///< TWS.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto TWPS = std::uint_fast8_t{}; ///< TWPS.
            static constexpr auto RESERVED = std::uint_fast8_t{ TWPS + Size::TWPS }; ///< Reserved.
            static constexpr auto TWS = std::uint_fast8_t{ RESERVED + Size::RESERVED }; ///< TWS.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto TWPS = std::uint8_t{ 0b11 << Bit::TWPS }; ///< TWPS.
            static constexpr auto RESERVED = std::uint8_t{ 0b1 << Bit::RESERVED }; ///< Reserved.
            static constexpr auto TWS = std::uint8_t{ 0b1'1111 << Bit::TWS }; ///< TWS.
        };

        TWSR() = delete;

        TWSR( TWSR && ) = delete;

        TWSR( TWSR const & ) = delete;

        ~TWSR() = delete;

        auto operator=( TWSR && ) = delete;

        auto operator=( TWSR const & ) = delete;

        using Register<std::uint8_t>::operator=;

        /**
         * \brief Configure the TWI bit rate generator prescaler value.
         *
         * \param[in] The desired bit rate generator prescaler value.
         */
        void configure( Prescaler prescaler ) noexcept;

        /**
         * \brief Get the peripheral/bus status.
         */
        auto status() const noexcept -> Status;
    };

    /**
     * \brief TWI (Device) Address Register (TWAR).
     *
     * This register has the following fields:
     * - TWI General Call Recognition Enable (TWGCE)
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
            static constexpr auto TWGCE = std::uint8_t{ 0b1 << Bit::TWGCE }; ///< TWGCE.
            static constexpr auto TWA = std::uint8_t{ 0b111'1111 << Bit::TWA }; ///< TWA.
        };

        TWAR() = delete;

        TWAR( TWAR && ) = delete;

        TWAR( TWAR const & ) = delete;

        ~TWAR() = delete;

        auto operator=( TWAR && ) = delete;

        auto operator=( TWAR const & ) = delete;

        using Register<std::uint8_t>::operator=;

        /**
         * \brief Configure the device address.
         *
         * \param[in] address The device address in transmitted form.
         * \param[in] general_call_recognition The general call recognition configuration.
         */
        void configure(
            std::uint8_t address                              = 0,
            General_Call_Recognition general_call_recognition = General_Call_Recognition::DISABLED ) noexcept;
    };

    /**
     * \brief TWI (Device) Address Mask Register (TWAMR).
     *
     * This register has the following fields:
     * - TWI (Device) Address Mask(TWAM)
     */
    class TWAMR : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto RESERVED = std::uint_fast8_t{ 1 }; ///< Reserved.
            static constexpr auto TWAM     = std::uint_fast8_t{ 7 }; ///< TWAM.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto RESERVED = std::uint_fast8_t{}; ///< Reserved.
            static constexpr auto TWAM = std::uint_fast8_t{ RESERVED + Size::RESERVED }; ///< TWAM.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto RESERVED = std::uint8_t{ 0b1 << Bit::RESERVED }; ///< Reserved.
            static constexpr auto TWAM = std::uint8_t{ 0b111'1111 << Bit::TWAM }; ///< TWAM.
        };

        TWAMR() = delete;

        TWAMR( TWAMR && ) = delete;

        TWAMR( TWAMR const & ) = delete;

        ~TWAMR() = delete;

        auto operator=( TWAMR && ) = delete;

        auto operator=( TWAMR const & ) = delete;

        using Register<std::uint8_t>::operator=;

        /**
         * \brief Configure the device address mask.
         *
         * \param[in] address_mask The device address mask in transmitted form.
         */
        void configure( std::uint8_t address_mask = 0 ) noexcept
        {
            *this = address_mask;
        }
    };

    /**
     * \brief Bit rate generator prescaler value.
     */
    enum class Prescaler : std::uint8_t {
        _1  = 0b00 << TWSR::Bit::TWPS, ///< 1.
        _4  = 0b01 << TWSR::Bit::TWPS, ///< 4.
        _16 = 0b10 << TWSR::Bit::TWPS, ///< 16.
        _64 = 0b11 << TWSR::Bit::TWPS, ///< 64.
    };

    /**
     * \brief Peripheral/bus status.
     */
    enum class Status : std::uint8_t {
        // #lizard forgives the length

        BUS_ERROR = 0x00, ///< Bus error due to illegal start or stop condition

        CONTROLLER_START_CONDITION_TRANSMITTED = 0x08, ///< Controller mode: start condition transmitted.
        CONTROLLER_REPEATED_START_CONDITION_TRANSMITTED    = 0x10, ///< Controller mode: repeated start condition transmitted.
        CONTROLLER_ADDRESS_WRITE_TRANSMITTED_ACK_RESPONSE  = 0x18, ///< Controller mode: device address + write transmitted, ACK response.
        CONTROLLER_ADDRESS_WRITE_TRANSMITTED_NACK_RESPONSE = 0x20, ///< Controller mode: device address + write transmitted, NACK response.
        CONTROLLER_DATA_TRANSMITTED_ACK_RESPONSE = 0x28, ///< Controller mode: data transmitted, ACK response.
        CONTROLLER_DATA_TRANSMITTED_NACK_RESPONSE = 0x30, ///< Controller mode: data transmitted, NACK response.
        CONTROLLER_ARBITRATION_LOST = 0x38, ///< Controller mode: arbitration lost.
        CONTROLLER_ADDRESS_READ_TRANSMITTED_ACK_RESPONSE  = 0x40, ///< Controller mode: device address + read transmitted, ACK response.
        CONTROLLER_ADDRESS_READ_TRANSMITTED_NACK_RESPONSE = 0x48, ///< Controller mode: device address + read transmitted, NACK response.
        CONTROLLER_DATA_RECEIVED_ACK_RESPONSE = 0x50, ///< Controller mode: data received, ACK response.
        CONTROLLER_DATA_RECEIVED_NACK_RESPONSE = 0x58, ///< Controller mode: data received, NACK response.

        DEVICE_ADDRESS_WRITE_RECEIVED_ACK_RESPONSE                  = 0x60, ///< Device mode: device address + write received, ACK response.
        DEVICE_ARBITRATION_LOST_ADDRESS_WRITE_RECEIVED_ACK_RESPONSE = 0x68, ///< Device mode: arbitration lost, device address + write received, ACK response.
        DEVICE_GENERAL_CALL_RECEIVED_ACK_RESPONSE = 0x70, ///< General call address received, ACK response.
        DEVICE_ARBITRATION_LOST_GENERAL_CALL_RECEIVED_ACK_RESPONSE = 0x78, ///< Device mode: arbitration lost, general call address received, ACK response.
        DEVICE_DATA_RECEIVED_ACK_RESPONSE = 0x80, ///< Device mode: data received, ACK response.
        DEVICE_DATA_RECEIVED_NACK_RESPONSE = 0x88, ///< Device mode: data received, NACK response.
        DEVICE_GENERAL_CALL_DATA_RECEIVED_ACK_RESPONSE             = 0x90, ///< Device mode: general call, data received, ACK response.
        DEVICE_GENERAL_CALL_DATA_RECEIVED_NACK_RESPONSE            = 0x98, ///< Device mode: general call, data received, NACK response.
        DEVICE_STOP_OR_REPEATED_START_RECEIVED                     = 0xA0, ///< Device mode: stop condition or repeated start condition received.
        DEVICE_ADDRESS_READ_RECEIVED_ACK_RESPONSE                  = 0xA8, ///< Device mode: device address + read received, ACK response.
        DEVICE_ARBITRATION_LOST_ADDRESS_READ_RECEIVED_ACK_RESPONSE = 0xB0, ///< Device mode: arbitration lost, device address + read received, ACK response.
        DEVICE_DATA_TRANSMITTED_ACK_RESPONSE = 0xB8, ///< Device mode: data transmitted, ACK response.
        DEVICE_DATA_TRANSMITTED_NACK_RESPONSE = 0xC0, ///< Device mode: data transmitted, NACK response.
        DEVICE_ALL_DATA_TRANSMITTED_ACK_RESPONSE = 0xC8, ///< Device mode: all data transmitted, ACK response.

        NO_STATE_INFORMATION_AVAILABLE = 0xF8, ///< No state information available.
    };

    /**
     * \brief General call recognition configuration.
     */
    enum class General_Call_Recognition : std::uint8_t {
        DISABLED = 0b0 << TWAR::Bit::TWGCE, ///< Disabled.
        ENABLED  = 0b1 << TWAR::Bit::TWGCE, ///< Enabled.
    };

    /**
     * \brief TWI Bit Rate Register (TWBR).
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
     * \brief TWI Data Register (TWDR).
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
};

inline void TWI::TWSR::configure( TWI::Prescaler prescaler ) noexcept
{
    *this = static_cast<std::uint8_t>( prescaler );
}

inline auto TWI::TWSR::status() const noexcept -> TWI::Status
{
    return static_cast<TWI::Status>( *this & Mask::TWS );
}

inline void TWI::TWAR::configure( std::uint8_t address, TWI::General_Call_Recognition general_call_recognition ) noexcept
{
    *this = address | static_cast<std::uint8_t>( general_call_recognition );
}

} // namespace picolibrary::Microchip::megaAVR::Peripheral

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR_PERIPHERAL_TWI_H
