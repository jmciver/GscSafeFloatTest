# Google Summer of Code 2019: Boost.SafeFloat Code Competancy Submission

| General Information        |                                                    |
|----------------------------|----------------------------------------------------|
|Author                      | John K. McIver III                                 |
|Author's institution e-mail | mciverj@unm.edu                                    |
|Degree being persued        | M.S. Computer Science                              |
|Associated university       | University of New Mexico                           |
|Location                    | Albuquerque, New Mexico (United States of America) |

## Requirements

* C++17 enabled compiler
* CMake at or above v3.12
* Boost libraries (used for unittesting)

Testing of the code was performed using G++ 8.3.1.

## Building

Clone the respository:

```shell
git clone git clone https://jkmciver@bitbucket.org/jkmciver/gscsafefloattest.git jmciverGscSafeFloat
```

Make the build directory:
```shell
cd jmciverGscSafeFloat && mkdir -p build/{debug,release}
```

Build debug version of project with testing enabled:
```shell
cd build/debug && \
cmake -DCMAKE_BUILD_TYPE=Debug -DTESTING=ON ../../src && \
make 
```

Run tests:
```shell
ctest
```
