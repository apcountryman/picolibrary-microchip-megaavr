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
 * \brief picolibrary::Microchip::megaAVR::I2C interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR_I2C_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR_I2C_H

#include <cstdint>

#include "picolibrary/error.h"
#include "picolibrary/i2c.h"
#include "picolibrary/microchip/megaavr/peripheral/twi.h"
#include "picolibrary/result.h"
#include "picolibrary/void.h"

/**
 * \brief Microchip megaAVR Inter-Integrated Circuit (I2C) facilities.
 */
namespace picolibrary::Microchip::megaAVR::I2C {

/**
 * \brief I2C basic controller.
 */
class Basic_Controller {
  public:
    /**
     * \brief Bit rate generator configuration.
     */
    struct Bit_Rate_Generator_Configuration {
        /**
         * \brief Prescaler.
         */
        Peripheral::TWI::Prescaler prescaler;

        /**
         * \brief Scaling factor.
         */
        std::uint8_t scaling_factor;
    };

    /**
     * \brief Constructor.
     */
    constexpr Basic_Controller() noexcept = default;

    /**
     * \brief Constructor.
     *
     * \param[in] twi The TWI peripheral used by the I2C controller.
     * \param[in] bit_rate_generator_configuration The desired bit rate generator
     *            configuration.
     */
    Basic_Controller( Peripheral::TWI & twi, Bit_Rate_Generator_Configuration bit_rate_generator_configuration ) noexcept
        :
        m_twi{ &twi }
    {
        m_twi->disable();

        m_twi->configure(
            bit_rate_generator_configuration.prescaler, bit_rate_generator_configuration.scaling_factor );
    }

    /**
     * \brief Constructor.
     *
     * \param[in] source The source of the move.
     */
    constexpr Basic_Controller( Basic_Controller && source ) noexcept :
        m_twi{ source.m_twi }
    {
        source.m_twi = nullptr;
    }

    Basic_Controller( Basic_Controller const & ) = delete;

    /**
     * \brief Destructor.
     */
    ~Basic_Controller() noexcept
    {
        disable();
    }

    /**
     * \brief Assignment operator.
     *
     * \param[in] expression The expression to be assigned.
     *
     * \return The assigned to object.
     */
    auto & operator=( Basic_Controller && expression ) noexcept
    {
        if ( &expression != this ) {
            disable();

            m_twi = expression.m_twi;

            expression.m_twi = nullptr;
        } // if

        return *this;
    }

    auto operator=( Basic_Controller const & ) = delete;

    /**
     * \brief Initialize the controller's hardware.
     *
     * \return Success.
     */
    auto initialize() noexcept -> Result<Void, Void>
    {
        m_twi->enable();

        return {};
    }

    /**
     * \brief Transmit a start condition.
     *
     * \return Nothing if start condition transmission succeeded.
     * \return picolibrary::Generic_Error::BUS_ERROR if a bus error occurred.
     * \return picolibrary::Generic_Error::LOGIC_ERROR if an unexpected TWI peripheral
     *         status is encountered.
     */
    auto start() noexcept -> Result<Void, Error_Code>
    {
        m_twi->start();

        while ( not m_twi->operation_complete() ) {}

        switch ( m_twi->status() ) {
            case Peripheral::TWI::Status::BUS_ERROR: return Generic_Error::BUS_ERROR;
            case Peripheral::TWI::Status::CONTROLLER_START_CONDITION_TRANSMITTED:
                return {};
            default: return Generic_Error::LOGIC_ERROR;
        } // switch
    }

    /**
     * \brief Transmit a repeated start condition.
     *
     * \return Nothing if repeated start condition transmission succeeded.
     * \return picolibrary::Generic_Error::BUS_ERROR if a bus error occurred.
     * \return picolibrary::Generic_Error::LOGIC_ERROR if an unexpected TWI peripheral
     *         status is encountered.
     */
    auto repeated_start() noexcept -> Result<Void, Error_Code>
    {
        m_twi->start();

        while ( not m_twi->operation_complete() ) {}

        switch ( m_twi->status() ) {
            case Peripheral::TWI::Status::BUS_ERROR: return Generic_Error::BUS_ERROR;
            case Peripheral::TWI::Status::CONTROLLER_REPEATED_START_CONDITION_TRANSMITTED:
                return {};
            default: return Generic_Error::LOGIC_ERROR;
        } // switch
    }

    /**
     * \brief Transmit a stop condition.
     *
     * \return Success.
     */
    auto stop() noexcept -> Result<Void, Void>
    {
        m_twi->stop();

        return {};
    }

    /**
     * \brief Address a device.
     *
     * \param[in] address The address of the device to address.
     * \param[in] operation The operation that will be performed once the device has been
     *            addressed.
     *
     * \return Nothing if addressing the device succeeded.
     * \return picolibrary::Generic_Error::BUS_ERROR if a bus error occurred.
     * \return picolibrary::Generic_Error::NONRESPONSIVE_DEVICE if the device did not
     *         respond when addressed.
     * \return picolibrary::Generic_Error::ARBITRATION_LOST if the controller lost
     *         arbitration while attempting to address the device.
     * \return picolibrary::Generic_Error::LOGIC_ERROR if an unexpected TWI peripheral
     *         status is encountered.
     */
    auto address( ::picolibrary::I2C::Address address, ::picolibrary::I2C::Operation operation ) noexcept
        -> Result<Void, Error_Code>
    {
        m_twi->write( address.transmitted() | static_cast<std::uint8_t>( operation ) );

        while ( not m_twi->operation_complete() ) {}

        switch ( m_twi->status() ) {
            case Peripheral::TWI::Status::BUS_ERROR: return Generic_Error::BUS_ERROR;
            case Peripheral::TWI::Status::CONTROLLER_ADDRESS_WRITE_TRANSMITTED_ACK_RESPONSE:
            case Peripheral::TWI::Status::CONTROLLER_ADDRESS_READ_TRANSMITTED_ACK_RESPONSE:
                return {};
            case Peripheral::TWI::Status::CONTROLLER_ADDRESS_WRITE_TRANSMITTED_NACK_RESPONSE:
            case Peripheral::TWI::Status::CONTROLLER_ADDRESS_READ_TRANSMITTED_NACK_RESPONSE:
                return Generic_Error::NONRESPONSIVE_DEVICE;
            case Peripheral::TWI::Status::CONTROLLER_ARBITRATION_LOST:
                return Generic_Error::ARBITRATION_LOST;
            default: return Generic_Error::LOGIC_ERROR;
        } // switch
    }

    /**
     * \brief Read data from a device.
     *
     * \param[in] response The response to send after the data is read.
     *
     * \return The read data if the read succeeded.
     * \return picolibrary::Generic_Error::BUS_ERROR if a bus error occurred.
     * \return picolibrary::Generic_Error::LOGIC_ERROR if an unexpected TWI peripheral
     *         status is encountered.
     */
    auto read( ::picolibrary::I2C::Response response ) noexcept -> Result<std::uint8_t, Error_Code>
    {
        m_twi->read(
            response == ::picolibrary::I2C::Response::ACK ? Peripheral::TWI::Response::ACK
                                                          : Peripheral::TWI::Response::NACK );

        while ( not m_twi->operation_complete() ) {}

        switch ( m_twi->status() ) {
            case Peripheral::TWI::Status::BUS_ERROR: return Generic_Error::BUS_ERROR;
            case Peripheral::TWI::Status::CONTROLLER_DATA_RECEIVED_ACK_RESPONSE:
            case Peripheral::TWI::Status::CONTROLLER_DATA_RECEIVED_NACK_RESPONSE:
                return m_twi->read();
            default: return Generic_Error::LOGIC_ERROR;
        } // switch
    }

    /**
     * \brief Write data to a device.
     *
     * \param[in] data The data to write.
     *
     * \return Nothing if the write succeeded.
     * \return picolibrary::Generic_Error::BUS_ERROR if a bus error occurred.
     * \return picolibrary::Generic_Error::NONRESPONSIVE_DEVICE if the device did not
     *         acknowledge the write.
     * \return picolibrary::Generic_Error::ARBITRATION_LOST if the controller lost
     *         arbitration during the write.
     * \return picolibrary::Generic_Error::LOGIC_ERROR if an unexpected TWI peripheral
     *         status is encountered.
     */
    auto write( std::uint8_t data ) noexcept -> Result<Void, Error_Code>
    {
        m_twi->write( data );

        while ( not m_twi->operation_complete() ) {}

        switch ( m_twi->status() ) {
            case Peripheral::TWI::Status::BUS_ERROR: return Generic_Error::BUS_ERROR;
            case Peripheral::TWI::Status::CONTROLLER_DATA_TRANSMITTED_ACK_RESPONSE:
                return {};
            case Peripheral::TWI::Status::CONTROLLER_DATA_TRANSMITTED_NACK_RESPONSE:
                return Generic_Error::NONRESPONSIVE_DEVICE;
            case Peripheral::TWI::Status::CONTROLLER_ARBITRATION_LOST:
                return Generic_Error::ARBITRATION_LOST;
            default: return Generic_Error::LOGIC_ERROR;
        } // switch
    }

  private:
    /**
     * \brief The TWI peripheral used by the I2C controller.
     */
    Peripheral::TWI * m_twi{};

    /**
     * \brief Disable the TWI.
     */
    void disable() noexcept
    {
        if ( m_twi ) {
            m_twi->disable();
        } // if
    }
};

/**
 * \brief I2C controller.
 */
using Controller = ::picolibrary::I2C::Controller<Basic_Controller>;

} // namespace picolibrary::Microchip::megaAVR::I2C

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR_I2C_H
