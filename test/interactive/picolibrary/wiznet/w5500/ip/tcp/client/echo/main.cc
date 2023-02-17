/**
 * picolibrary-microchip-megaavr
 *
 * Copyright 2020-2023, Andrew Countryman <apcountryman@gmail.com> and the
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
 * \brief picolibrary::WIZnet::W5500::IP::TCP::Client echo interactive test program.
 */

#include "picolibrary/gpio.h"
#include "picolibrary/ipv4.h"
#include "picolibrary/microchip/megaavr/gpio.h"
#include "picolibrary/microchip/megaavr/peripheral.h"
#include "picolibrary/microchip/megaavr/peripheral/spi.h"
#include "picolibrary/microchip/megaavr/spi.h"
#include "picolibrary/spi.h"
#include "picolibrary/testing/interactive/microchip/megaavr/log.h"
#include "picolibrary/testing/interactive/wiznet/w5500/ip/tcp.h"
#include "picolibrary/wiznet/w5500.h"

namespace {

using ::picolibrary::GPIO::Active_Low_IO_Pin;
using ::picolibrary::IPv4::Address;
using ::picolibrary::Microchip::megaAVR::GPIO::Push_Pull_IO_Pin;
using ::picolibrary::Microchip::megaAVR::SPI::Fixed_Configuration_Controller;
using ::picolibrary::Microchip::megaAVR::SPI::SPI_Bit_Order;
using ::picolibrary::Microchip::megaAVR::SPI::SPI_Clock_Phase;
using ::picolibrary::Microchip::megaAVR::SPI::SPI_Clock_Polarity;
using ::picolibrary::Microchip::megaAVR::SPI::SPI_Clock_Rate;
using ::picolibrary::SPI::GPIO_Output_Pin_Device_Selector;
using ::picolibrary::Testing::Interactive::Microchip::megaAVR::Log;
using ::picolibrary::Testing::Interactive::WIZnet::W5500::IP::TCP::echo_client;
using ::picolibrary::WIZnet::W5500::ARP_Forcing;
using ::picolibrary::WIZnet::W5500::No_Delayed_ACK_Usage;
using ::picolibrary::WIZnet::W5500::PHY_Mode;
using ::picolibrary::WIZnet::W5500::Ping_Blocking;
using ::picolibrary::WIZnet::W5500::Socket_Buffer_Size;

using namespace ::picolibrary::Microchip::megaAVR::Peripheral;

} // namespace

/**
 * \brief Execute the picolibrary::WIZnet::W5500::IP::TCP::Client echo interactive test.
 *
 * \return N/A
 */
int main() noexcept
{
    // #lizard forgives the length

    Log::initialize();

    echo_client(
        Log::instance(),
        Fixed_Configuration_Controller<SPI>{ CONTROLLER_SPI::instance(),
                                             SPI_Clock_Rate::CONTROLLER_SPI_CLOCK_RATE,
                                             SPI_Clock_Polarity::CONTROLLER_SPI_CLOCK_POLARITY,
                                             SPI_Clock_Phase::CONTROLLER_SPI_CLOCK_PHASE,
                                             SPI_Bit_Order::MSB_FIRST },
        Fixed_Configuration_Controller<SPI>::Configuration{},
        GPIO_Output_Pin_Device_Selector<Active_Low_IO_Pin<Push_Pull_IO_Pin>>{
            DEVICE_SELECTOR_PORT::instance(), DEVICE_SELECTOR_MASK },
        PHY_Mode::W5500_PHY_MODE,
        Ping_Blocking::W5500_PING_BLOCKING_CONFIGURATION,
        ARP_Forcing::W5500_ARP_FORCING_CONFIGURATION,
        W5500_RETRANSMISSION_RETRY_TIME,
        W5500_RETRANSMISSION_RETRY_COUNT,
        Socket_Buffer_Size::W5500_SOCKET_BUFFER_SIZE,
        { { W5500_MAC_ADDRESS } },
        { { W5500_IPV4_ADDRESS } },
        { { W5500_IPV4_GATEWAY_ADDRESS } },
        { { W5500_IPV4_SUBNET_MASK } },
        No_Delayed_ACK_Usage::CLIENT_NO_DELAYED_ACK_USAGE_CONFIGURATION,
        CLIENT_MAXIMUM_SEGMENT_SIZE,
        CLIENT_TIME_TO_LIVE,
        CLIENT_KEEPALIVE_PERIOD,
        { CLIENT_LOCAL_ENDPOINT },
        { CLIENT_REMOTE_ENDPOINT } );

    for ( ;; ) {} // for
}
