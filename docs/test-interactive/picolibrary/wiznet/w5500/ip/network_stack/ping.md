# `::picolibrary::WIZnet::W5500::IP::Network_Stack` ping interactive test

## Table of Contents
1. [Test Configuration Options](#test-configuration-options)
1. [Test Executable Name](#test-executable-name)

## Test Configuration Options
The `::picolibrary::WIZnet::W5500::IP::Network_Stack` ping interactive test supports the
following configuration options:
- `PICOLIBRARY_WIZNET_W5500_IP_NETWORK_STACK_ENABLE_PING_INTERACTIVE_TEST`
  (defaults to `OFF`): enable the
  `::picolibrary::WIZnet::W5500::IP::Network_Stack` ping interactive test
    - The following configuration options are available if
      `PICOLIBRARY_WIZNET_W5500_IP_NETWORK_STACK_ENABLE_PING_INTERACTIVE_TEST`
      is `ON`:
       - `PICOLIBRARY_WIZNET_W5500_IP_NETWORK_STACK_PING_INTERACTIVE_TEST_CONTROLLER_SPI`:
         `::picolibrary::WIZnet::W5500::IP::Network_Stack` ping interactive
         test controller SPI
       - `PICOLIBRARY_WIZNET_W5500_IP_NETWORK_STACK_PING_INTERACTIVE_TEST_CONTROLLER_SPI_CLOCK_RATE`:
         `::picolibrary::WIZnet::W5500::IP::Network_Stack` ping interactive
         test controller SPI clock rate
       - `PICOLIBRARY_WIZNET_W5500_IP_NETWORK_STACK_PING_INTERACTIVE_TEST_CONTROLLER_SPI_CLOCK_POLARITY`:
         `::picolibrary::WIZnet::W5500::IP::Network_Stack` ping interactive
         test controller SPI clock polarity
       - `PICOLIBRARY_WIZNET_W5500_IP_NETWORK_STACK_PING_INTERACTIVE_TEST_CONTROLLER_SPI_CLOCK_PHASE`:
         `::picolibrary::WIZnet::W5500::IP::Network_Stack` ping interactive
         test controller SPI clock phase
       - `PICOLIBRARY_WIZNET_W5500_IP_NETWORK_STACK_PING_INTERACTIVE_TEST_DEVICE_SELECTOR_PORT`:
         `::picolibrary::WIZnet::W5500::IP::Network_Stack` ping interactive
         test device selector PORT
       - `PICOLIBRARY_WIZNET_W5500_IP_NETWORK_STACK_PING_INTERACTIVE_TEST_DEVICE_SELECTOR_MASK`:
         `::picolibrary::WIZnet::W5500::IP::Network_Stack` ping interactive
         test device selector mask
       - `PICOLIBRARY_WIZNET_W5500_IP_NETWORK_STACK_PING_INTERACTIVE_TEST_NETWORK_STACK_PHY_MODE`
         (defaults to `ALL_CAPABLE_AUTO_NEGOTIATION_ENABLED`):
         `::picolibrary::WIZnet::W5500::IP::Network_Stack` ping interactive
         test network stack PHY mode
       - `PICOLIBRARY_WIZNET_W5500_IP_NETWORK_STACK_PING_INTERACTIVE_TEST_NETWORK_STACK_ARP_FORCING_CONFIGURATION`
         (defaults to `DISABLED`):
         `::picolibrary::WIZnet::W5500::IP::Network_Stack` ping interactive
         test network stack ARP forcing configuration
       - `PICOLIBRARY_WIZNET_W5500_IP_NETWORK_STACK_PING_INTERACTIVE_TEST_NETWORK_STACK_RETRANSMISSION_RETRY_TIME`
         (defaults to `2000`):
         `::picolibrary::WIZnet::W5500::IP::Network_Stack` ping interactive
         test network stack retransmission retry time
       - `PICOLIBRARY_WIZNET_W5500_IP_NETWORK_STACK_PING_INTERACTIVE_TEST_NETWORK_STACK_RETRANSMISSION_RETRY_COUNT`
         (defaults to `8`): `::picolibrary::WIZnet::W5500::IP::Network_Stack`
         ping interactive test network stack retransmission retry count
       - `PICOLIBRARY_WIZNET_W5500_IP_NETWORK_STACK_PING_INTERACTIVE_TEST_NETWORK_STACK_MAC_ADDRESS`
         (defaults to `0x02,0x00,0x00,0x00,0x00,0x00`):
         `::picolibrary::WIZnet::W5500::IP::Network_Stack` ping interactive
         test network stack MAC address
       - `PICOLIBRARY_WIZNET_W5500_IP_NETWORK_STACK_PING_INTERACTIVE_TEST_NETWORK_STACK_IPV4_ADDRESS`
         (defaults to `0,0,0,0`):
         `::picolibrary::WIZnet::W5500::IP::Network_Stack` ping interactive
         test network stack IPv4 address
       - `PICOLIBRARY_WIZNET_W5500_IP_NETWORK_STACK_PING_INTERACTIVE_TEST_NETWORK_STACK_IPV4_GATEWAY_ADDRESS`
         (defaults to `0,0,0,0`):
         `::picolibrary::WIZnet::W5500::IP::Network_Stack` ping interactive
         test network stack IPv4 gateway address
       - `PICOLIBRARY_WIZNET_W5500_IP_NETWORK_STACK_PING_INTERACTIVE_TEST_NETWORK_STACK_IPV4_SUBNET_MASK`
         (defaults to `255,255,255,255`):
         `::picolibrary::WIZnet::W5500::IP::Network_Stack` ping interactive
         test network stack IPv4 subnet mask

## Test Executable Name
`test-interactive-picolibrary-wiznet-w5500-ip-network_stack-ping`
