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
 * \brief picolibrary::Microchip::megaAVR::I2C interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR_I2C_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR_I2C_H

#include <cstdint>

#include "picolibrary/error.h"
#include "picolibrary/i2c.h"
#include "picolibrary/microchip/megaavr/peripheral/twi.h"
#include "picolibrary/postcondition.h"
#include "picolibrary/utility.h"

/**
 * \brief Microchip megaAVR Inter-Integrated Circuit (I2C) facilities.
 */
namespace picolibrary::Microchip::megaAVR::I2C {

/**
 * \brief TWI bit rate generator prescaler value.
 */
enum class TWI_Bit_Rate_Generator_Prescaler_Value : std::uint8_t {
    _1  = Peripheral::TWI::TWSR::TWPS_1,  ///< 1.
    _4  = Peripheral::TWI::TWSR::TWPS_4,  ///< 4.
    _16 = Peripheral::TWI::TWSR::TWPS_16, ///< 16.
    _64 = Peripheral::TWI::TWSR::TWPS_64, ///< 64.
};

/**
 * \brief Basic controller.
 */
class Basic_Controller {
  public:
    /**
     * \brief Constructor.
     */
    constexpr Basic_Controller() noexcept = default;

    /**
     * \brief Constructor.
     *
     * \param[in] twi The TWI to be used by the controller.
     * \param[in] twi_bit_rate_generator_prescaler_value The desired TWI bit rate
     *            generator prescaler value.
     * \param[in] twi_bit_rate_generator_scaling_factor The desired TWI bit rate generator
     *            scaling factor (TWBR register value).
     */
    Basic_Controller(
        Peripheral::TWI &                      twi,
        TWI_Bit_Rate_Generator_Prescaler_Value twi_bit_rate_generator_prescaler_value,
        std::uint8_t twi_bit_rate_generator_scaling_factor ) noexcept :
        m_twi{ &twi }
    {
        configure_controller( twi_bit_rate_generator_prescaler_value, twi_bit_rate_generator_scaling_factor );
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
    constexpr auto operator=( Basic_Controller && expression ) noexcept -> Basic_Controller &
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
     */
    void initialize() noexcept
    {
        enable_controller();
    }

    /**
     * \brief Check if a bus error is present.
     *
     * \return true if a bus error is present.
     * \return false if a bus error is not present.
     */
    auto bus_error_present() const noexcept -> bool
    {
        return controller_bus_error_present();
    }

    /**
     * \brief Transmit a start condition.
     *
     * \post a start condition has been transmitted
     */
    void start() noexcept
    {
        initiate_start_transmission();

        while ( not operation_complete() ) {} // while

        switch ( status() ) {
            case Peripheral::TWI::TWSR::TWS::TWS_HOST_START_CONDITION_TRANSMITTED: return;
            case Peripheral::TWI::TWSR::TWS::TWS_BUS_ERROR:
                ensure( Generic_Error::BUS_ERROR );
                break;
            default: ensure( Generic_Error::LOGIC_ERROR );
        } // switch
    }

    /**
     * \brief Transmit a repeated start condition.
     *
     * \post a repeated start condition has been transmitted
     */
    void repeated_start() noexcept
    {
        initiate_start_transmission();

        while ( not operation_complete() ) {} // while

        switch ( status() ) {
            case Peripheral::TWI::TWSR::TWS::TWS_HOST_REPEATED_START_CONDITION_TRANSMITTED:
                return;
            case Peripheral::TWI::TWSR::TWS::TWS_BUS_ERROR:
                ensure( Generic_Error::BUS_ERROR );
                break;
            default: ensure( Generic_Error::LOGIC_ERROR );
        } // switch
    }

    /**
     * \brief Transmit a stop condition.
     */
    void stop() noexcept
    {
        initiate_stop_transmission();

        while ( not stop_transmission_complete() ) {} // while
    }

    /**
     * \brief Address a device.
     *
     * \param[in] address The address of the device to address.
     * \param[in] operation The operation that will be performed once the device has been
     *            addressed.
     *
     * \post the device has been addressed and a response has been received
     *
     * \return picolibrary::I2C::Response::ACK if an ACK response is received.
     * \return picolibrary::I2C::Response::NACK if a NACK response is received.
     */
    auto address( ::picolibrary::I2C::Address_Transmitted address, ::picolibrary::I2C::Operation operation ) noexcept
        -> ::picolibrary::I2C::Response
    {
        // #lizard forgives the length

        initiate_write( address.as_unsigned_integer() | to_underlying( operation ) );

        while ( not operation_complete() ) {} // while

        switch ( status() ) {
            case Peripheral::TWI::TWSR::TWS::TWS_HOST_ADDRESS_WRITE_TRANSMITTED_ACK_RECEIVED:
                return ::picolibrary::I2C::Response::ACK;
            case Peripheral::TWI::TWSR::TWS::TWS_HOST_ADDRESS_WRITE_TRANSMITTED_NACK_RECEIVED:
                return ::picolibrary::I2C::Response::NACK;
            case Peripheral::TWI::TWSR::TWS::TWS_HOST_ADDRESS_READ_TRANSMITTED_ACK_RECEIVED:
                return ::picolibrary::I2C::Response::ACK;
            case Peripheral::TWI::TWSR::TWS::TWS_HOST_ADDRESS_READ_TRANSMITTED_NACK_RECEIVED:
                return ::picolibrary::I2C::Response::NACK;
            case Peripheral::TWI::TWSR::TWS::TWS_BUS_ERROR:
                ensure( Generic_Error::BUS_ERROR );
                break;
            case Peripheral::TWI::TWSR::TWS::TWS_HOST_ARBITRATION_LOST:
                ensure( Generic_Error::ARBITRATION_LOST );
                break;
            default: ensure( Generic_Error::LOGIC_ERROR );
        } // switch

        return ::picolibrary::I2C::Response::NACK; // unreachable
    }

    /**
     * \brief Read data from a device.
     *
     * \param[in] response The response to transmit once the data has been read.
     *
     * \post data has been read from the device and the desired response has been
     *       transmitted
     *
     * \return The data read from the device.
     */
    auto read( ::picolibrary::I2C::Response response ) noexcept -> std::uint8_t
    {
        initiate_read( response );

        while ( not operation_complete() ) {} // while

        switch ( status() ) {
            case Peripheral::TWI::TWSR::TWS::TWS_HOST_DATA_RECEIVED_ACK_TRANSMITTED:
                return finish_read();
            case Peripheral::TWI::TWSR::TWS::TWS_HOST_DATA_RECEIVED_NACK_TRANSMITTED:
                return finish_read();
            case Peripheral::TWI::TWSR::TWS::TWS_BUS_ERROR:
                ensure( Generic_Error::BUS_ERROR );
                break;
            case Peripheral::TWI::TWSR::TWS::TWS_HOST_ARBITRATION_LOST:
                ensure( Generic_Error::ARBITRATION_LOST );
                break;
            default: ensure( Generic_Error::LOGIC_ERROR );
        } // switch

        return 0; // unreachable
    }

    /**
     * \brief Write data to a device.
     *
     * \param[in] data The data to write to the device.
     *
     * \post data has been transmitted and a response has been received
     *
     * \return picolibrary::I2C::Response::ACK if an ACK response is received.
     * \return picolibrary::I2C::Response::NACK if a NACK response is received.
     */
    auto write( std::uint8_t data ) noexcept -> ::picolibrary::I2C::Response
    {
        initiate_write( data );

        while ( not operation_complete() ) {} // while

        switch ( status() ) {
            case Peripheral::TWI::TWSR::TWS::TWS_HOST_DATA_TRANSMITTED_ACK_RECEIVED:
                return ::picolibrary::I2C::Response::ACK;
            case Peripheral::TWI::TWSR::TWS::TWS_HOST_DATA_TRANSMITTED_NACK_RECEIVED:
                return ::picolibrary::I2C::Response::NACK;
            case Peripheral::TWI::TWSR::TWS::TWS_BUS_ERROR:
                ensure( Generic_Error::BUS_ERROR );
                break;
            case Peripheral::TWI::TWSR::TWS::TWS_HOST_ARBITRATION_LOST:
                ensure( Generic_Error::ARBITRATION_LOST );
                break;
            default: ensure( Generic_Error::LOGIC_ERROR );
        } // switch

        return ::picolibrary::I2C::Response::NACK; // unreachable
    }

  private:
    /**
     * \brief The TWI used by the controller.
     */
    Peripheral::TWI * m_twi{};

    /**
     * \brief Disable the controller.
     */
    constexpr void disable() noexcept
    {
        if ( m_twi ) {
            disable_controller();
        } // if
    }

    /**
     * \brief Configure the controller.
     *
     * \param[in] twi_bit_rate_generator_prescaler_value The desired TWI bit rate
     *            generator prescaler value.
     * \param[in] twi_bit_rate_generator_scaling_factor The desired TWI bit rate generator
     *            scaling factor (TWBR register value).
     */
    void configure_controller(
        TWI_Bit_Rate_Generator_Prescaler_Value twi_bit_rate_generator_prescaler_value,
        std::uint8_t twi_bit_rate_generator_scaling_factor ) noexcept
    {
        m_twi->twcr  = 0;
        m_twi->twsr  = to_underlying( twi_bit_rate_generator_prescaler_value );
        m_twi->twbr  = twi_bit_rate_generator_scaling_factor;
        m_twi->twar  = 0;
        m_twi->twamr = 0;
    }

    /**
     * \brief Disable the controller.
     */
    void disable_controller() noexcept
    {
        m_twi->twcr = 0;
    }

    /**
     * \brief Enable the controller.
     */
    void enable_controller() noexcept
    {
        m_twi->twcr = Peripheral::TWI::TWCR::Mask::TWEN;
    }

    /**
     * \brief Check if a bus error is present.
     *
     * \return true if a bus error is present.
     * \return false if a bus error is not present.
     */
    auto controller_bus_error_present() const noexcept -> bool
    {
        return ( m_twi->twsr & Peripheral::TWI::TWSR::Mask::TWS ) == Peripheral::TWI::TWSR::TWS_BUS_ERROR;
    }

    /**
     * \brief Check if an operation is complete.
     *
     * \return true if the operation is complete.
     * \return false if the operation is not complete.
     */
    auto operation_complete() const noexcept -> bool
    {
        return m_twi->twcr & Peripheral::TWI::TWCR::Mask::TWINT;
    }

    /**
     * \brief Get the TWI peripheral/bus status.
     *
     * \return The TWI peripheral/bus status.
     */
    auto status() const noexcept -> Peripheral::TWI::TWSR::TWS
    {
        return static_cast<Peripheral::TWI::TWSR::TWS>( m_twi->twsr & Peripheral::TWI::TWSR::Mask::TWS );
    }

    /**
     * \brief Initiate transmission of a start condition or a repeated start condition.
     */
    void initiate_start_transmission() noexcept
    {
        m_twi->twcr = Peripheral::TWI::TWCR::Mask::TWINT | Peripheral::TWI::TWCR::Mask::TWSTA
                      | Peripheral::TWI::TWCR::Mask::TWEN;
    }

    /**
     * \brief Initiate transmission of a stop condition.
     */
    void initiate_stop_transmission() noexcept
    {
        m_twi->twcr = Peripheral::TWI::TWCR::Mask::TWINT | Peripheral::TWI::TWCR::Mask::TWSTO
                      | Peripheral::TWI::TWCR::Mask::TWEN;
    }

    /**
     * \brief Check if transmission of a stop condition has been completed.
     *
     * \return true if transmission of the stop condition has been completed.
     * \return false if transmission of the stop condition has not been completed.
     */
    auto stop_transmission_complete() const noexcept -> bool
    {
        return not( m_twi->twcr & Peripheral::TWI::TWCR::Mask::TWSTO );
    }

    /**
     * \brief Initiate a read.
     *
     * \param[in] response The response to transmit once the data has been read.
     */
    void initiate_read( ::picolibrary::I2C::Response response ) noexcept
    {
        m_twi->twcr = Peripheral::TWI::TWCR::Mask::TWINT | Peripheral::TWI::TWCR::Mask::TWEN
                      | ( response == ::picolibrary::I2C::Response::ACK
                              ? Peripheral::TWI::TWCR::Mask::TWEA
                              : 0 );
    }

    /**
     * \brief Finish a read by reading the received data.
     *
     * \return The received data.
     */
    auto finish_read() const noexcept -> std::uint8_t
    {
        return m_twi->twdr;
    }

    /**
     * \brief Initiate a write.
     *
     * \param[in] data The data to be transmitted.
     */
    void initiate_write( std::uint8_t data ) noexcept
    {
        m_twi->twdr = data;
        m_twi->twcr = Peripheral::TWI::TWCR::Mask::TWINT | Peripheral::TWI::TWCR::Mask::TWEN;
    }
};

/**
 * \brief Controller.
 */
using Controller = ::picolibrary::I2C::Controller<Basic_Controller>;

} // namespace picolibrary::Microchip::megaAVR::I2C

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR_I2C_H
