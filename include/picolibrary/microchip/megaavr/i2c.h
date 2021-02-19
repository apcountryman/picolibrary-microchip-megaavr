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

#include "picolibrary/microchip/megaavr/peripheral/twi.h"
#include "picolibrary/result.h"
#include "picolibrary/utility.h"

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
     * \brief Constructor.
     */
    constexpr Basic_Controller() noexcept = default;

    /**
     * \brief Constructor.
     *
     * \param[in] twi The TWI peripheral used by the I2C controller.
     * \param[in] prescaler The desired bit rate generator prescaler value.
     * \param[in] scaling_factor The desired bit rate generator scaling factor.
     */
    Basic_Controller( Peripheral::TWI & twi, Peripheral::TWI::Prescaler prescaler, std::uint8_t scaling_factor ) noexcept
        :
        m_twi{ &twi }
    {
        m_twi->disable();

        m_twi->configure( prescaler, scaling_factor );
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

} // namespace picolibrary::Microchip::megaAVR::I2C

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR_I2C_H
