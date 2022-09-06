# Usage

## Dependency
To use picolibrary-microchip-megaavr as a dependency, simply add the subdirectory
containing the repository to a CMake build, and link with the
`picolibrary-microchip-megaavr` static library.
```cmake
add_subdirectory( picolibrary-microchip-megaavr )
```
```cmake
target_link_libraries(
    foo
    picolibrary-microchip-megaavr
)
```

## Development
The repository's Git `pre-commit` hook script is the simplest way to configure, and build
picolibrary-microchip-megaavr during development.
See the `pre-commit` script's help text for usage details.
```shell
./git/hooks/pre-commit --help
```

Additional checks, such as static analysis, are performed by the repository's GitHub
Actions CI workflow.
