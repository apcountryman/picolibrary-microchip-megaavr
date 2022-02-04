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
 * \brief picolibrary::Microchip::megaAVR::GPIO interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR_GPIO_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR_GPIO_H

#include <cstdint>

#include "picolibrary/gpio.h"
#include "picolibrary/microchip/megaavr/peripheral/port.h"

/**
 * \brief Microchip megaAVR General Purpose Input/Output (GPIO) facilities.
 */
namespace picolibrary::Microchip::megaAVR::GPIO {

/**
 * \brief Internally pulled-up input pin.
 */
class Internally_Pulled_Up_Input_Pin {
  public:
    /**
     * \brief Constructor.
     */
    constexpr Internally_Pulled_Up_Input_Pin() noexcept = default;

    /**
     * \brief Constructor.
     *
     * \param[in] port The GPIO port the pin is a member of.
     * \param[in] mask The mask identifying the pin.
     */
    constexpr Internally_Pulled_Up_Input_Pin( Peripheral::PORT & port, std::uint8_t mask ) noexcept :
        m_port{ &port },
        m_mask{ mask }
    {
    }

    /**
     * \brief Constructor.
     *
     * \param[in] source The source of the move.
     */
    constexpr Internally_Pulled_Up_Input_Pin( Internally_Pulled_Up_Input_Pin && source ) noexcept :
        m_port{ source.m_port },
        m_mask{ source.m_mask }
    {
        source.m_port = nullptr;
        source.m_mask = 0;
    }

    Internally_Pulled_Up_Input_Pin( Internally_Pulled_Up_Input_Pin const & ) = delete;

    /**
     * \brief Destructor.
     */
    ~Internally_Pulled_Up_Input_Pin() noexcept
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
    auto & operator=( Internally_Pulled_Up_Input_Pin && expression ) noexcept
    {
        if ( &expression != this ) {
            disable();

            m_port = expression.m_port;
            m_mask = expression.m_mask;

            expression.m_port = nullptr;
            expression.m_mask = 0;
        } // if

        return *this;
    }

    auto operator=( Internally_Pulled_Up_Input_Pin const & ) = delete;

    /**
     * \brief Initialize the pin's hardware.
     *
     * \param[in] initial_pull_up_state The initial state of the pin's internal pull-up
     *            resistor.
     */
    void initialize( ::picolibrary::GPIO::Initial_Pull_Up_State initial_pull_up_state = ::picolibrary::GPIO::Initial_Pull_Up_State::DISABLED ) noexcept
    {
        configure_pin_as_internally_pulled_up_input();

        switch ( initial_pull_up_state ) {
            case ::picolibrary::GPIO::Initial_Pull_Up_State::DISABLED:
                disable_pull_up();
                break;
            case ::picolibrary::GPIO::Initial_Pull_Up_State::ENABLED:
                enable_pull_up();
                break;
        } // switch
    }

    /**
     * \brief Check if the pin's internal pull-up resistor is disabled.
     *
     * \return true if the pin's internal pull-up resistor is disabled.
     * \return false if the pin's internal pull-up resistor is not disabled.
     */
    auto pull_up_is_disabled() const noexcept
    {
        return not pull_up_is_enabled();
    }

    /**
     * \brief Check if the pin's internal pull-up resistor is enabled.
     *
     * \return true if the pin's internal pull-up resistor is enabled.
     * \return false if the pin's internal pull-up resistor is not enabled.
     */
    auto pull_up_is_enabled() const noexcept -> bool
    {
        return m_port->port & m_mask;
    }

    /**
     * \brief Disable the pin's internal pull-up resistor.
     */
    void disable_pull_up() noexcept
    {
        m_port->port &= ~m_mask;
    }

    /**
     * \brief Enable the pin's internal pull-up resistor.
     */
    void enable_pull_up() noexcept
    {
        m_port->port |= m_mask;
    }

    /**
     * \brief Check if the pin is in the low state.
     *
     * \return true if the pin is in the low state.
     * \return false if the pin is not in the low state.
     */
    auto is_low() const noexcept
    {
        return not is_high();
    }

    /**
     * \brief Check if the pin is in the high state.
     *
     * \return true if the pin is in the high state.
     * \return false if the pin is not in the high state.
     */
    auto is_high() const noexcept -> bool
    {
        return m_port->pin & m_mask;
    }

  private:
    /**
     * \brief The GPIO port the pin is a member of.
     */
    Peripheral::PORT * m_port{};

    /**
     * \brief The mask identifying the pin.
     */
    std::uint8_t m_mask{};

    /**
     * \brief Configure the pin to act as an internally pulled-up input.
     */
    void configure_pin_as_internally_pulled_up_input() noexcept
    {
        m_port->ddr &= ~m_mask;
    }

    /**
     * \brief Disable the pin.
     */
    void disable() noexcept
    {
        if ( m_port ) {
            disable_pull_up();
        } // if
    }
};

/**
 * \brief Open-drain Input/Output (I/O) pin.
 */
class Open_Drain_IO_Pin {
  public:
    /**
     * \brief Constructor.
     */
    constexpr Open_Drain_IO_Pin() noexcept = default;

    /**
     * \brief Constructor.
     *
     * \param[in] port The GPIO port the pin is a member of.
     * \param[in] mask The mask identifying the pin.
     */
    constexpr Open_Drain_IO_Pin( Peripheral::PORT & port, std::uint8_t mask ) noexcept :
        m_port{ &port },
        m_mask{ mask }
    {
    }

    /**
     * \brief Constructor.
     *
     * \param[in] source The source of the move.
     */
    constexpr Open_Drain_IO_Pin( Open_Drain_IO_Pin && source ) noexcept :
        m_port{ source.m_port },
        m_mask{ source.m_mask }
    {
        source.m_port = nullptr;
        source.m_mask = 0;
    }

    Open_Drain_IO_Pin( Open_Drain_IO_Pin const & ) = delete;

    /**
     * \brief Destructor.
     */
    ~Open_Drain_IO_Pin() noexcept
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
    auto & operator=( Open_Drain_IO_Pin && expression ) noexcept
    {
        if ( &expression != this ) {
            disable();

            m_port = expression.m_port;
            m_mask = expression.m_mask;

            expression.m_port = nullptr;
            expression.m_mask = 0;
        } // if

        return *this;
    }

    auto operator=( Open_Drain_IO_Pin const & ) = delete;

    /**
     * \brief Initialize the pin's hardware.
     *
     * \param[in] initial_pin_state The initial state of the pin.
     */
    void initialize( ::picolibrary::GPIO::Initial_Pin_State initial_pin_state = ::picolibrary::GPIO::Initial_Pin_State::LOW ) noexcept
    {
        configure_pin_as_open_drain_io();

        switch ( initial_pin_state ) {
            case ::picolibrary::GPIO::Initial_Pin_State::LOW: transition_to_low(); break;
            case ::picolibrary::GPIO::Initial_Pin_State::HIGH:
                transition_to_high();
                break;
        } // switch
    }

    /**
     * \brief Check if the pin is in the low state.
     *
     * \return true if the pin is in the low state.
     * \return false if the pin is not in the low state.
     */
    auto is_low() const noexcept
    {
        return not is_high();
    }

    /**
     * \brief Check if the pin is in the high state.
     *
     * \return true if the pin is in the high state.
     * \return false if the pin is not in the high state.
     */
    auto is_high() const noexcept -> bool
    {
        return m_port->pin & m_mask;
    }

    /**
     * \brief Transition the pin to the low state.
     */
    void transition_to_low() noexcept
    {
        m_port->ddr |= m_mask;
    }

    /**
     * \brief Transition the pin to the high state.
     */
    void transition_to_high() noexcept
    {
        m_port->ddr &= ~m_mask;
    }

    /**
     * \brief Toggle the pin state.
     */
    void toggle() noexcept
    {
        m_port->ddr ^= m_mask;
    }

  private:
    /**
     * \brief The GPIO port the pin is a member of.
     */
    Peripheral::PORT * m_port{};

    /**
     * \brief The mask identifying the pin.
     */
    std::uint8_t m_mask{};

    /**
     * \brief Configure the pin to act as an internally pulled-up input.
     */
    void configure_pin_as_internally_pulled_up_input() noexcept
    {
        m_port->ddr &= ~m_mask;
    }

    /**
     * \brief Configure the pin to act as an open-drain I/O pin.
     */
    void configure_pin_as_open_drain_io() noexcept
    {
        m_port->port &= ~m_mask;
    }

    /**
     * \brief Disable the pin.
     */
    void disable() noexcept
    {
        if ( m_port ) {
            configure_pin_as_internally_pulled_up_input();
        } // if
    }
};

} // namespace picolibrary::Microchip::megaAVR::GPIO

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR_GPIO_H
