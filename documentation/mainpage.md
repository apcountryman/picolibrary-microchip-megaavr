# picolibrary-microchip-megaavr

[`picolibrary`](https://github.com/apcountryman/picolibrary) Hardware Interface Layer
(HIL) for Microchip megaAVR microcontrollers.

## Obtaining the Source Code
HTTPS:
```shell
git clone --recurse-submodules https://github.com/apcountryman/picolibrary-microchip-megaavr.git
```
SSH:
```shell
git clone --recurse-submodules git@github.com:apcountryman/picolibrary-microchip-megaavr.git
```

## Usage (Dependency)
To use this library as a dependency, simply add the subdirectory containing this
repository to a CMake build, and link with the `picolibrary-microchip-megaavr` static
library.
```cmake
add_subdirectory( picolibrary-microchip-megaavr )
```
```cmake
target_link_libraries(
    foo
    picolibrary-microchip-megaavr
)
```

## Usage (Development)
This repository's Git `pre-commit` hook script is the simplest way to configure, and build
this project during development.
See the `pre-commit` script's help text for usage details.
```shell
./git/hooks/pre-commit --help
```

Additional checks, such as static analysis, are performed by this project's GitHub Actions
CI workflow.

## Versioning
`picolibrary-microchip-megaavr` follows the [Abseil Live at Head
philosophy](https://abseil.io/about/philosophy).

## Workflow
`picolibrary-microchip-megaavr` uses the [GitHub
flow](https://guides.github.com/introduction/flow/) workflow.

## Git Hooks
To install this repository's Git hooks, execute the `install` script located in the
`git/hooks` directory.
See the `install` script's help text for usage details.
```shell
./git/hooks/install --help
```

## Authors
- Andrew Countryman

## License
`picolibrary-microchip-megaavr` is licensed under the Apache License, Version 2.0.
For more information, [see the `LICENSE` file in this repository](LICENSE).
