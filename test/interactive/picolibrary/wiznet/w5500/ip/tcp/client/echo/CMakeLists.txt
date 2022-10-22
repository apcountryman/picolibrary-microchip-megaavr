# picolibrary-microchip-megaavr
#
# Copyright 2020-2022, Andrew Countryman <apcountryman@gmail.com> and the
# picolibrary-microchip-megaavr contributors
#
# Licensed under the Apache License, Version 2.0 (the "License"); you may not use this
# file except in compliance with the License. You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software distributed under
# the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
# KIND, either express or implied. See the License for the specific language governing
# permissions and limitations under the License.

# Description: picolibrary::WIZnet::W5500::IP::TCP::Client echo interactive test CMake
#       rules.

# build the picolibrary::WIZnet::W5500::IP::TCP::Client echo interactive test
if( ${PICOLIBRARY_MICROCHIP_MEGAAVR_ENABLE_INTERACTIVE_TESTING} )
    option(
        PICOLIBRARY_WIZNET_W5500_IP_TCP_CLIENT_ENABLE_ECHO_INTERACTIVE_TEST
        "picolibrary-microchip-megaavr: enable the picolibrary::WIZnet::W5500::IP::TCP::Client echo interactive test"
        OFF
    )

    if( ${PICOLIBRARY_WIZNET_W5500_IP_TCP_CLIENT_ENABLE_ECHO_INTERACTIVE_TEST} )
        set(
            PICOLIBRARY_WIZNET_W5500_IP_TCP_CLIENT_ECHO_INTERACTIVE_TEST_CONTROLLER_SPI
            "" CACHE STRING
            "picolibrary-microchip-megaavr: picolibrary::WIZnet::W5500::IP::TCP::Client echo interactive test controller SPI"
        )
        set(
            PICOLIBRARY_WIZNET_W5500_IP_TCP_CLIENT_ECHO_INTERACTIVE_TEST_CONTROLLER_SPI_CLOCK_RATE
            "" CACHE STRING
            "picolibrary-microchip-megaavr: picolibrary::WIZnet::W5500::IP::TCP::Client echo interactive test controller SPI clock rate"
        )
        set(
            PICOLIBRARY_WIZNET_W5500_IP_TCP_CLIENT_ECHO_INTERACTIVE_TEST_CONTROLLER_SPI_CLOCK_POLARITY
            "" CACHE STRING
            "picolibrary-microchip-megaavr: picolibrary::WIZnet::W5500::IP::TCP::Client echo interactive test controller SPI clock polarity"
        )
        set(
            PICOLIBRARY_WIZNET_W5500_IP_TCP_CLIENT_ECHO_INTERACTIVE_TEST_CONTROLLER_SPI_CLOCK_PHASE
            "" CACHE STRING
            "picolibrary-microchip-megaavr: picolibrary::WIZnet::W5500::IP::TCP::Client echo interactive test controller SPI clock phase"
        )

        set(
            PICOLIBRARY_WIZNET_W5500_IP_TCP_CLIENT_ECHO_INTERACTIVE_TEST_DEVICE_SELECTOR_PORT
            "" CACHE STRING
            "picolibrary-microchip-megaavr: picolibrary::WIZnet::W5500::IP::TCP::Client echo interactive test device selector PORT"
        )
        set(
            PICOLIBRARY_WIZNET_W5500_IP_TCP_CLIENT_ECHO_INTERACTIVE_TEST_DEVICE_SELECTOR_MASK
            "" CACHE STRING
            "picolibrary-microchip-megaavr: picolibrary::WIZnet::W5500::IP::TCP::Client echo interactive test device selector mask"
        )

        set(
            PICOLIBRARY_WIZNET_W5500_IP_TCP_CLIENT_ECHO_INTERACTIVE_TEST_W5500_PHY_MODE
            "ALL_CAPABLE_AUTO_NEGOTIATION_ENABLED" CACHE STRING
            "picolibrary-microchip-megaavr: picolibrary::WIZnet::W5500::IP::TCP::Client echo interactive test W5500 PHY mode"
        )

        set(
            PICOLIBRARY_WIZNET_W5500_IP_TCP_CLIENT_ECHO_INTERACTIVE_TEST_W5500_PING_BLOCKING_CONFIGURATION
            "DISABLED" CACHE STRING
            "picolibrary-microchip-megaavr: picolibrary::WIZnet::W5500::IP::TCP::Client echo interactive test W5500 ping blocking configuration"
        )

        set(
            PICOLIBRARY_WIZNET_W5500_IP_TCP_CLIENT_ECHO_INTERACTIVE_TEST_W5500_ARP_FORCING_CONFIGURATION
            "DISABLED" CACHE STRING
            "picolibrary-microchip-megaavr: picolibrary::WIZnet::W5500::IP::TCP::Client echo interactive test W5500 ARP forcing configuration"
        )

        set(
            PICOLIBRARY_WIZNET_W5500_IP_TCP_CLIENT_ECHO_INTERACTIVE_TEST_W5500_RETRANSMISSION_RETRY_TIME
            "2000" CACHE STRING
            "picolibrary-microchip-megaavr: picolibrary::WIZnet::W5500::IP::TCP::Client echo interactive test W5500 retransmission retry time"
        )
        set(
            PICOLIBRARY_WIZNET_W5500_IP_TCP_CLIENT_ECHO_INTERACTIVE_TEST_W5500_RETRANSMISSION_RETRY_COUNT
            "8" CACHE STRING
            "picolibrary-microchip-megaavr: picolibrary::WIZnet::W5500::IP::TCP::Client echo interactive test W5500 retransmission retry count"
        )

        set(
            PICOLIBRARY_WIZNET_W5500_IP_TCP_CLIENT_ECHO_INTERACTIVE_TEST_W5500_SOCKET_BUFFER_SIZE
            "_2_KiB" CACHE STRING
            "picolibrary-microchip-megaavr: picolibrary::WIZnet::W5500::IP::TCP::Client echo interactive test W5500 socket buffer size"
        )

        set(
            PICOLIBRARY_WIZNET_W5500_IP_TCP_CLIENT_ECHO_INTERACTIVE_TEST_W5500_MAC_ADDRESS
            "0x02,0x00,0x00,0x00,0x00,0x00" CACHE STRING
            "picolibrary-microchip-megaavr: picolibrary::WIZnet::W5500::IP::TCP::Client echo interactive test W5500 MAC address"
        )

        set(
            PICOLIBRARY_WIZNET_W5500_IP_TCP_CLIENT_ECHO_INTERACTIVE_TEST_W5500_IPV4_ADDRESS
            "0,0,0,0" CACHE STRING
            "picolibrary-microchip-megaavr: picolibrary::WIZnet::W5500::IP::TCP::Client echo interactive test W5500 IPv4 address"
        )
        set(
            PICOLIBRARY_WIZNET_W5500_IP_TCP_CLIENT_ECHO_INTERACTIVE_TEST_W5500_IPV4_GATEWAY_ADDRESS
            "0,0,0,0" CACHE STRING
            "picolibrary-microchip-megaavr: picolibrary::WIZnet::W5500::IP::TCP::Client echo interactive test W5500 IPv4 gateway address"
        )
        set(
            PICOLIBRARY_WIZNET_W5500_IP_TCP_CLIENT_ECHO_INTERACTIVE_TEST_W5500_IPV4_SUBNET_MASK
            "255,255,255,255" CACHE STRING
            "picolibrary-microchip-megaavr: picolibrary::WIZnet::W5500::IP::TCP::Client echo interactive test W5500 IPv4 subnet mask"
        )

        set(
            PICOLIBRARY_WIZNET_W5500_IP_TCP_CLIENT_ECHO_INTERACTIVE_TEST_CLIENT_NO_DELAYED_ACK_USAGE_CONFIGURATION
            "DISABLED" CACHE STRING
            "picolibrary-microchip-megaavr: picolibrary::WIZnet::W5500::IP::TCP::Client echo interactive test client no delayed ACK usage configuration"
        )

        set(
            PICOLIBRARY_WIZNET_W5500_IP_TCP_CLIENT_ECHO_INTERACTIVE_TEST_CLIENT_MAXIMUM_SEGMENT_SIZE
            "0x0000" CACHE STRING
            "picolibrary-microchip-megaavr: picolibrary::WIZnet::W5500::IP::TCP::Client echo interactive test client maximum segment size"
        )

        set(
            PICOLIBRARY_WIZNET_W5500_IP_TCP_CLIENT_ECHO_INTERACTIVE_TEST_CLIENT_TIME_TO_LIVE
            "0x80" CACHE STRING
            "picolibrary-microchip-megaavr: picolibrary::WIZnet::W5500::IP::TCP::Client echo interactive test client time to live"
        )

        set(
            PICOLIBRARY_WIZNET_W5500_IP_TCP_CLIENT_ECHO_INTERACTIVE_TEST_CLIENT_KEEPALIVE_PERIOD
            "0x00" CACHE STRING
            "picolibrary-microchip-megaavr: picolibrary::WIZnet::W5500::IP::TCP::Client echo interactive test client keepalive period"
        )

        set(
            PICOLIBRARY_WIZNET_W5500_IP_TCP_CLIENT_ECHO_INTERACTIVE_TEST_CLIENT_LOCAL_ENDPOINT
            "0" CACHE STRING
            "picolibrary-microchip-megaavr: picolibrary::WIZnet::W5500::IP::TCP::Client echo interactive test client local endpoint"
        )
        set(
            PICOLIBRARY_WIZNET_W5500_IP_TCP_CLIENT_ECHO_INTERACTIVE_TEST_CLIENT_REMOTE_ENDPOINT
            "Address{ { 0,0,0,0 } }, 0" CACHE STRING
            "picolibrary-microchip-megaavr: picolibrary::WIZnet::W5500::IP::TCP::Client echo interactive test client remote endpoint"
        )

        add_executable(
            test-interactive-picolibrary-wiznet-w5500-ip-tcp-client-echo
            main.cc
        )
        target_compile_definitions(
            test-interactive-picolibrary-wiznet-w5500-ip-tcp-client-echo
            PRIVATE CONTROLLER_SPI=${PICOLIBRARY_WIZNET_W5500_IP_TCP_CLIENT_ECHO_INTERACTIVE_TEST_CONTROLLER_SPI}
            PRIVATE CONTROLLER_SPI_CLOCK_RATE=${PICOLIBRARY_WIZNET_W5500_IP_TCP_CLIENT_ECHO_INTERACTIVE_TEST_CONTROLLER_SPI_CLOCK_RATE}
            PRIVATE CONTROLLER_SPI_CLOCK_POLARITY=${PICOLIBRARY_WIZNET_W5500_IP_TCP_CLIENT_ECHO_INTERACTIVE_TEST_CONTROLLER_SPI_CLOCK_POLARITY}
            PRIVATE CONTROLLER_SPI_CLOCK_PHASE=${PICOLIBRARY_WIZNET_W5500_IP_TCP_CLIENT_ECHO_INTERACTIVE_TEST_CONTROLLER_SPI_CLOCK_PHASE}
            PRIVATE DEVICE_SELECTOR_PORT=${PICOLIBRARY_WIZNET_W5500_IP_TCP_CLIENT_ECHO_INTERACTIVE_TEST_DEVICE_SELECTOR_PORT}
            PRIVATE DEVICE_SELECTOR_MASK=${PICOLIBRARY_WIZNET_W5500_IP_TCP_CLIENT_ECHO_INTERACTIVE_TEST_DEVICE_SELECTOR_MASK}
            PRIVATE W5500_PHY_MODE=${PICOLIBRARY_WIZNET_W5500_IP_TCP_CLIENT_ECHO_INTERACTIVE_TEST_W5500_PHY_MODE}
            PRIVATE W5500_PING_BLOCKING_CONFIGURATION=${PICOLIBRARY_WIZNET_W5500_IP_TCP_CLIENT_ECHO_INTERACTIVE_TEST_W5500_PING_BLOCKING_CONFIGURATION}
            PRIVATE W5500_ARP_FORCING_CONFIGURATION=${PICOLIBRARY_WIZNET_W5500_IP_TCP_CLIENT_ECHO_INTERACTIVE_TEST_W5500_ARP_FORCING_CONFIGURATION}
            PRIVATE W5500_RETRANSMISSION_RETRY_TIME=${PICOLIBRARY_WIZNET_W5500_IP_TCP_CLIENT_ECHO_INTERACTIVE_TEST_W5500_RETRANSMISSION_RETRY_TIME}
            PRIVATE W5500_RETRANSMISSION_RETRY_COUNT=${PICOLIBRARY_WIZNET_W5500_IP_TCP_CLIENT_ECHO_INTERACTIVE_TEST_W5500_RETRANSMISSION_RETRY_COUNT}
            PRIVATE W5500_SOCKET_BUFFER_SIZE=${PICOLIBRARY_WIZNET_W5500_IP_TCP_CLIENT_ECHO_INTERACTIVE_TEST_W5500_SOCKET_BUFFER_SIZE}
            PRIVATE W5500_MAC_ADDRESS=${PICOLIBRARY_WIZNET_W5500_IP_TCP_CLIENT_ECHO_INTERACTIVE_TEST_W5500_MAC_ADDRESS}
            PRIVATE W5500_IPV4_ADDRESS=${PICOLIBRARY_WIZNET_W5500_IP_TCP_CLIENT_ECHO_INTERACTIVE_TEST_W5500_IPV4_ADDRESS}
            PRIVATE W5500_IPV4_GATEWAY_ADDRESS=${PICOLIBRARY_WIZNET_W5500_IP_TCP_CLIENT_ECHO_INTERACTIVE_TEST_W5500_IPV4_GATEWAY_ADDRESS}
            PRIVATE W5500_IPV4_SUBNET_MASK=${PICOLIBRARY_WIZNET_W5500_IP_TCP_CLIENT_ECHO_INTERACTIVE_TEST_W5500_IPV4_SUBNET_MASK}
            PRIVATE CLIENT_NO_DELAYED_ACK_USAGE_CONFIGURATION=${PICOLIBRARY_WIZNET_W5500_IP_TCP_CLIENT_ECHO_INTERACTIVE_TEST_CLIENT_NO_DELAYED_ACK_USAGE_CONFIGURATION}
            PRIVATE CLIENT_MAXIMUM_SEGMENT_SIZE=${PICOLIBRARY_WIZNET_W5500_IP_TCP_CLIENT_ECHO_INTERACTIVE_TEST_CLIENT_MAXIMUM_SEGMENT_SIZE}
            PRIVATE CLIENT_TIME_TO_LIVE=${PICOLIBRARY_WIZNET_W5500_IP_TCP_CLIENT_ECHO_INTERACTIVE_TEST_CLIENT_TIME_TO_LIVE}
            PRIVATE CLIENT_KEEPALIVE_PERIOD=${PICOLIBRARY_WIZNET_W5500_IP_TCP_CLIENT_ECHO_INTERACTIVE_TEST_CLIENT_KEEPALIVE_PERIOD}
            PRIVATE CLIENT_LOCAL_ENDPOINT=${PICOLIBRARY_WIZNET_W5500_IP_TCP_CLIENT_ECHO_INTERACTIVE_TEST_CLIENT_LOCAL_ENDPOINT}
            PRIVATE CLIENT_REMOTE_ENDPOINT=${PICOLIBRARY_WIZNET_W5500_IP_TCP_CLIENT_ECHO_INTERACTIVE_TEST_CLIENT_REMOTE_ENDPOINT}
        )
        target_link_libraries(
            test-interactive-picolibrary-wiznet-w5500-ip-tcp-client-echo
            picolibrary
            picolibrary-microchip-megaavr
            picolibrary-microchip-megaavr-testing-interactive-fatal_error
        )
        add_avrdude_programming_targets(
            test-interactive-picolibrary-wiznet-w5500-ip-tcp-client-echo
            "${PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_RESET}"
            CONFIGURATION_FILE "${PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_CONFIGURATION_FILE}"
            PORT               "${PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_PORT}"
            PROGRAM_FLASH      "${PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_PROGRAM_FLASH}"
            VERBOSITY          "${PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_VERBOSITY}"
            VERIFY_FLASH       "${PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_VERIFY_FLASH}"
        )
    endif( ${PICOLIBRARY_WIZNET_W5500_IP_TCP_CLIENT_ENABLE_ECHO_INTERACTIVE_TEST} )
endif( ${PICOLIBRARY_MICROCHIP_MEGAAVR_ENABLE_INTERACTIVE_TESTING} )
