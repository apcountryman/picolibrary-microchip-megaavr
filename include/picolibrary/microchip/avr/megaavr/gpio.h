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
 * \brief picolibrary::Microchip::AVR::megaAVR::GPIO interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_AVR_MEGAAVR_GPIO_H
#define PICOLIBRARY_MICROCHIP_AVR_MEGAAVR_GPIO_H

/**
 * \brief Microchip AVR megaAVR General Purpose Input/Output (GPIO) facilities.
 */
namespace picolibrary::Microchip::AVR::megaAVR::GPIO {

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
     * \param[in] source The source of the move.
     */
    constexpr Internally_Pulled_Up_Input_Pin( Internally_Pulled_Up_Input_Pin && source ) noexcept = default;

    /**
     * \todo #27
     */
    Internally_Pulled_Up_Input_Pin( Internally_Pulled_Up_Input_Pin const & ) = delete;

    /**
     * \brief Destructor.
     */
    ~Internally_Pulled_Up_Input_Pin() noexcept = default;

    /**
     * \brief Assignment operator.
     *
     * \param[in] expression The expression to be assigned.
     *
     * \return The assigned to object.
     */
    auto operator=( Internally_Pulled_Up_Input_Pin && expression ) noexcept
        -> Internally_Pulled_Up_Input_Pin & = default;

    /**
     * \todo #27
     *
     * \return
     */
    auto operator=( Internally_Pulled_Up_Input_Pin const & ) = delete;
};

} // namespace picolibrary::Microchip::AVR::megaAVR::GPIO

#endif // PICOLIBRARY_MICROCHIP_AVR_MEGAAVR_GPIO_H
