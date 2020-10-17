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
 * \brief picolibrary::Microchip::AVR::megaAVR::Peripheral::PORT interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_AVR_MEGAAVR_PERIPHERAL_PORT_H
#define PICOLIBRARY_MICROCHIP_AVR_MEGAAVR_PERIPHERAL_PORT_H

#include <cstdint>

#include "picolibrary/microchip/avr/megaavr/register.h"

namespace picolibrary::Microchip::AVR::megaAVR::Peripheral {

/**
 * \brief Microchip AVR megaAVR General Purpose Input/Output (GPIO) port.
 */
class PORT {
  public:
    /**
     * \brief Port Input Pins Register (PIN).
     */
    Register<std::uint8_t> pin;

    /**
     * \brief Data Direction Register (DDR).
     */
    Register<std::uint8_t> ddr;

    /**
     * \brief Data Register (PORT).
     */
    Register<std::uint8_t> port;

    PORT() = delete;

    /**
     * \todo #27
     */
    PORT( PORT && ) = delete;

    /**
     * \todo #27
     */
    PORT( PORT const & ) = delete;

    ~PORT() = delete;

    /**
     * \todo #27
     *
     * \return
     */
    auto operator=( PORT && ) = delete;

    /**
     * \todo #27
     *
     * \return
     */
    auto operator=( PORT const & ) = delete;

    /**
     * \brief Configure a pin to act as an internally pulled-up input pin.
     *
     * \param[in] mask The mask identifying the pin to be configured as an internally
     *            pulled-up input pin.
     */
    void configure_pin_as_internally_pulled_up_input( std::uint8_t mask ) noexcept
    {
        ddr &= ~mask;
    }

    /**
     * \brief Configure a pin to act as an open-drain output pin.
     *
     * \param[in] mask The mask identifying the pin to be configured as an open-drain
     *            output pin.
     */
    void configure_pin_as_open_drain_output( std::uint8_t mask ) noexcept
    {
        port &= ~mask;
    }

    /**
     * \brief Enable an internally pulled-up input pin's internal pull-up resistor.
     *
     * \param[in] mask The mask identifying the internally pulled-up input pin whose
     *            internal pull-up resistor is to be enabled.
     */
    void enable_pull_up( std::uint8_t mask ) noexcept
    {
        port |= mask;
    }

    /**
     * \brief Disable an internally pulled-up input pin's internal pull-up resistor.
     *
     * \param[in] mask The mask identifying the internally pulled-up input pin whose
     *            internal pull-up resistor is to be disabled.
     */
    void disable_pull_up( std::uint8_t mask ) noexcept
    {
        port &= ~mask;
    }

    /**
     * \brief Get the state of a pin.
     *
     * \param[in] mask The mask identifying the pin whose state is to be gotten.
     *
     * \return The state of the pin.
     */
    auto state( std::uint8_t mask ) const noexcept
    {
        return pin & mask;
    }

    /**
     * \brief Transition an open-drain output pin to the high state.
     *
     * \param[in] mask The mask identifying the open-drain output pin to transition to the
     *            high state.
     */
    void transition_open_drain_output_to_high( std::uint8_t mask ) noexcept
    {
        ddr &= ~mask;
    }

    /**
     * \brief Transition an open-drain output pin to the low state.
     *
     * \param[in] mask The mask identifying the open-drain output pin to transition to the
     *            low state.
     */
    void transition_open_drain_output_to_low( std::uint8_t mask ) noexcept
    {
        ddr |= mask;
    }

    /**
     * \brief Toggle the state of an open-drain output pin.
     *
     * \param[in] mask The mask identifying the open-drain output pin to toggle the state
     *            of.
     */
    void toggle_open_drain_output( std::uint8_t mask ) noexcept
    {
        ddr ^= mask;
    }
};

} // namespace picolibrary::Microchip::AVR::megaAVR::Peripheral

#endif // PICOLIBRARY_MICROCHIP_AVR_MEGAAVR_PERIPHERAL_PORT_H
