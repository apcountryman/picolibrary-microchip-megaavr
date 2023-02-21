# Library Version
To access the null-terminated library version string that may be stored in ROM, link with
the `picolibrary-microchip-megaavr-version` static library, include
[`picolibrary/microchip/megaavr/version.h`](https://github.com/apcountryman/picolibrary-microchip-megaavr/blob/main/include/picolibrary/microchip/megaavr/version.h)
and use `::picolibrary::Microchip::megaAVR::version()`:
```cmake
target_link_libraries(
    foo
    picolibrary-microchip-megaavr
    picolibrary-microchip-megaavr-version
)
```
```c++
#include "picolibrary/stream.h"
#include "picolibrary/microchip/megaavr/version.h"

void foo( ::picolibrary::Reliable_Output_Stream & stream ) noexcept
{
    stream.put( ::picolibrary::Microchip::megaAVR::version() );
}
```
The null-terminated library version string is populated with the output of the following
Git command:
```shell
git describe --match=none --always --dirty --broken
```
