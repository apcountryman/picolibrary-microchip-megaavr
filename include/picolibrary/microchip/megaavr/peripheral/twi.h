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

#include "picolibrary/bit_manipulation.h"
#include "picolibrary/microchip/megaavr/peripheral/instance.h"
#include "picolibrary/microchip/megaavr/register.h"

namespace picolibrary::Microchip::megaAVR::Peripheral {

/**
 * \brief Microchip megaAVR 2-wire Serial Interface (TWI) peripheral.
 */
class TWI {
  public:
    enum class Prescaler : std::uint8_t;

    enum class Interrupt_Enable_State : std::uint8_t;

    enum class Response : std::uint8_t;

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

        /**
         * \brief Configure the TWI.
         */
        void configure() noexcept
        {
            *this = 0;
        }

        /**
         * \brief Enable the TWI.
         */
        void enable() noexcept
        {
            *this |= Mask::TWEN;
        }

        /**
         * \brief Disable the TWI.
         */
        void disable() noexcept
        {
            *this &= ~Mask::TWEN;
        }

        /**
         * \brief Get the TWI interrupt enable state.
         *
         * \return The TWI interrupt enable state.
         */
        auto interrupt_enable_state() const noexcept -> Interrupt_Enable_State;

        /**
         * \brief Enable the TWI interrupt.
         */
        void enable_interrupt() noexcept
        {
            *this |= Mask::TWIE;
        }

        /**
         * \brief Disable the TWI interrupt.
         */
        void disable_interrupt() noexcept
        {
            *this &= ~Mask::TWIE;
        }

        /**
         * \brief Enable ACK.
         */
        void enable_ack() noexcept
        {
            *this |= Mask::TWEA;
        }

        /**
         * \brief Disable ACK.
         */
        void disable_ack() noexcept
        {
            *this &= ~Mask::TWEA;
        }

        /**
         * \brief Check if a write collision occurred.
         *
         * \return true if a write collision occurred.
         * \return false if a write collision did not occur.
         */
        auto write_collision() const noexcept -> bool
        {
            return *this & Mask::TWWC;
        }

        /**
         * \brief Check if an operation is complete.
         *
         * \return true if the operation is complete.
         * \return false if the operation is not complete.
         */
        auto operation_complete() const noexcept -> bool
        {
            return *this & Mask::TWINT;
        }

        /**
         * \brief Initiate transmission of a start condition or a repeated start
         *        condition.
         *
         * \param[in] interrupt_enable_state The interrupt enable state.
         */
        void start( Interrupt_Enable_State interrupt_enable_state ) noexcept
        {
            *this = Mask::TWINT | Mask::TWSTA | Mask::TWEN
                    | static_cast<std::uint8_t>( interrupt_enable_state );
        }

        /**
         * \brief Transmit a stop condition.
         *
         * \param[in] interrupt_enable_state The interrupt enable state.
         */
        void stop( Interrupt_Enable_State interrupt_enable_state ) noexcept
        {
            *this = Mask::TWINT | Mask::TWSTO | Mask::TWEN
                    | static_cast<std::uint8_t>( interrupt_enable_state );
        }

        /**
         * \brief Initiate a write of a device address and operation, or a data byte.
         *
         * \param[in] interrupt_enable_state The interrupt enable state.
         */
        void write( Interrupt_Enable_State interrupt_enable_state ) noexcept
        {
            *this = Mask::TWINT | Mask::TWEN | static_cast<std::uint8_t>( interrupt_enable_state );
        }

        /**
         * \brief Initiate a data read.
         *
         * \param[in] response The response to send after the data is read.
         * \param[in] interrupt_enable_state The interrupt enable state.
         */
        void read( Response response, Interrupt_Enable_State interrupt_enable_state ) noexcept;
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
        void configure( Prescaler prescaler = Prescaler::_1 ) noexcept;

        /**
         * \brief Get the peripheral/bus status.
         *
         * \return The peripheral/bus status.
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

        /**
         * \brief Configure the device address.
         *
         * \param[in] address The device address in transmitted form.
         * \param[in] general_call_recognition The general call recognition configuration.
         */
        void configure( std::uint8_t address, General_Call_Recognition general_call_recognition ) noexcept;
    };

    /**
     * \brief TWI (Device) Address Mask Register (TWAMR).
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

        /**
         * \brief Configure the device address mask.
         *
         * \param[in] address_mask The device address mask in transmitted form.
         */
        void configure( std::uint8_t address_mask ) noexcept
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
     * \brief TWI interrupt enable state.
     */
    enum class Interrupt_Enable_State : std::uint8_t {
        DISABLED = 0b0 << TWCR::Bit::TWIE, ///< Disabled.
        ENABLED  = 0b1 << TWCR::Bit::TWIE, ///< Enabled.
    };

    /**
     * \brief Response.
     */
    enum class Response : std::uint8_t {
        ACK  = 0b1 << TWCR::Bit::TWEA, ///< ACK.
        NACK = 0b0 << TWCR::Bit::TWEA, ///< NACK.
    };

    /**
     * \brief Peripheral/bus status.
     */
    enum class Status : std::uint8_t {
        // #lizard forgives the length

        BUS_ERROR = 0x00, ///< Bus error due to illegal start or stop condition.

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

    /**
     * \brief Configure the TWI for use as an I2C controller.
     *
     * \param[in] prescaler The desired bit rate generator prescaler value.
     * \param[in] scaling_factor The desired bit rate generator scaling factor.
     * \param[in] address The controller's device address in transmitted form.
     * \param[in] general_call_recognition The general call recognition configuration.
     * \param[in] address_mask The controller's device address mask in transmitted form.
     */
    void configure_as_i2c_controller(
        Prescaler                prescaler,
        std::uint8_t             scaling_factor,
        std::uint8_t             address                  = 0,
        General_Call_Recognition general_call_recognition = General_Call_Recognition::DISABLED,
        std::uint8_t             address_mask             = 0 ) noexcept
    {
        twcr.configure();
        twsr.configure( prescaler );

        twbr = scaling_factor;

        twar.configure( address, general_call_recognition );
        twamr.configure( address_mask );
    }

    /**
     * \brief Configure the TWI for use as an I2C device.
     *
     * \param[in] address The device address in transmitted form.
     * \param[in] general_call_recognition The general call recognition configuration.
     * \param[in] address_mask The device address mask in transmitted form.
     */
    void configure_as_i2c_device( std::uint8_t address, General_Call_Recognition general_call_recognition, std::uint8_t address_mask ) noexcept
    {
        twcr.configure();
        twsr.configure();

        twbr = 0;

        twar.configure( address, general_call_recognition );
        twamr.configure( address_mask );
    }

    /**
     * \brief Enable the TWI.
     */
    void enable() noexcept
    {
        twcr.enable();
    }

    /**
     * \brief Disable the TWI.
     */
    void disable() noexcept
    {
        twcr.disable();
    }

    /**
     * \brief Get the TWI interrupt enable state.
     *
     * \return The TWI interrupt enable state.
     */
    auto interrupt_enable_state() const noexcept
    {
        return twcr.interrupt_enable_state();
    }

    /**
     * \brief Enable the TWI interrupt.
     */
    void enable_interrupt() noexcept
    {
        twcr.enable_interrupt();
    }

    /**
     * \brief Disable the TWI interrupt.
     */
    void disable_interrupt() noexcept
    {
        twcr.disable_interrupt();
    }

    /**
     * \brief Enable ACK.
     */
    void enable_ack() noexcept
    {
        twcr.enable_ack();
    }

    /**
     * \brief Disable ACK.
     */
    void disable_ack() noexcept
    {
        twcr.disable_ack();
    }

    /**
     * \brief Check if a write collision occurred.
     *
     * \return true if a write collision occurred.
     * \return false if a write collision did not occur.
     */
    auto write_collision() const noexcept
    {
        return twcr.write_collision();
    }

    /**
     * \brief Check if an operation is complete.
     *
     * \return true if the operation is complete.
     * \return false if the operation is not complete.
     */
    auto operation_complete() const noexcept
    {
        return twcr.operation_complete();
    }

    /**
     * \brief Initiate transmission of a start condition or a repeated start condition.
     *
     * \param[in] interrupt_enable_state The interrupt enable state.
     */
    void start( Interrupt_Enable_State interrupt_enable_state = Interrupt_Enable_State::DISABLED ) noexcept
    {
        twcr.start( interrupt_enable_state );
    }

    /**
     * \brief Transmit a stop condition.
     *
     * \param[in] interrupt_enable_state The interrupt enable state.
     */
    void stop( Interrupt_Enable_State interrupt_enable_state = Interrupt_Enable_State::DISABLED ) noexcept
    {
        twcr.stop( interrupt_enable_state );
    }

    /**
     * \brief Initiate a write of a device address and operation, or a data byte.
     *
     * \param[in] data The device address and operation, or the data byte to write.
     * \param[in] interrupt_enable_state The interrupt enable state.
     */
    void write( std::uint8_t data, Interrupt_Enable_State interrupt_enable_state = Interrupt_Enable_State::DISABLED ) noexcept
    {
        twdr = data;

        twcr.write( interrupt_enable_state );
    }

    /**
     * \brief Initiate a data read.
     *
     * \param[in] response The response to send after the data is read.
     * \param[in] interrupt_enable_state The interrupt enable state.
     */
    void read( Response response, Interrupt_Enable_State interrupt_enable_state = Interrupt_Enable_State::DISABLED ) noexcept
    {
        twcr.read( response, interrupt_enable_state );
    }

    /**
     * \brief Get the peripheral/bus status.
     *
     * \return The peripheral/bus status.
     */
    auto status() const noexcept
    {
        return twsr.status();
    }

    /**
     * \brief Read received data.
     *
     * \return The received data.
     */
    auto read() const noexcept -> std::uint8_t
    {
        return twdr;
    }
};

inline auto TWI::TWCR::interrupt_enable_state() const noexcept -> Interrupt_Enable_State
{
    return static_cast<Interrupt_Enable_State>( *this & Mask::TWIE );
}

inline void TWI::TWCR::read( Response response, Interrupt_Enable_State interrupt_enable_state ) noexcept
{
    *this = Mask::TWINT | Mask::TWEN | static_cast<std::uint8_t>( response )
            | static_cast<std::uint8_t>( interrupt_enable_state );
}

inline void TWI::TWSR::configure( Prescaler prescaler ) noexcept
{
    *this = static_cast<std::uint8_t>( prescaler );
}

inline auto TWI::TWSR::status() const noexcept -> Status
{
    return static_cast<Status>( *this & Mask::TWS );
}

inline void TWI::TWAR::configure( std::uint8_t address, General_Call_Recognition general_call_recognition ) noexcept
{
    *this = address | static_cast<std::uint8_t>( general_call_recognition );
}

/**
 * \brief Microchip megaAVR 2-wire Serial Interface (TWI) peripheral instance.
 *
 * \tparam INSTANCE_ADDRESS The address of the TWI instance.
 */
template<std::uintptr_t INSTANCE_ADDRESS>
using TWI_Instance = Instance<TWI, INSTANCE_ADDRESS>;

} // namespace picolibrary::Microchip::megaAVR::Peripheral

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR_PERIPHERAL_TWI_H
