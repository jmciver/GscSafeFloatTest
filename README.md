# Google Summer of Code 2019: Boost.SafeFloat Code Competancy Submission

| General Information        |                                                    |
|----------------------------|----------------------------------------------------|
|Author                      | John K. McIver III                                 |
|Author's institution e-mail | mciverj@unm.edu                                    |
|Degree being persued        | M.S. Computer Science                              |
|Associated university       | University of New Mexico                           |
|Location                    | Albuquerque, New Mexico (United States of America) |

## Requirements

* C++17 enabled compiler (tested using g++ 8.3.1 or MSVC 15.9.7)
* CMake at or above v3.12
* Boost libraries (tested using 1.69.0)

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

## Tasks

1. Define a user defined literal assignable to float that fails
   compilation when the value provided cannot be expressed as an
   positive integer power of 0.5 (e.g. 0.5, 0.25, 0.125).
2. Provide a function receiving an integer (X) and a
   tuple (std::tuple<type1, type2, type3…>) into a tuple of
   vectors (std::tuple<std::vector,std::vector, std::vector, …>
   where each vector has X elements of each originally received
   in each tuple_element. E.g. for X=2 and the tuple {1, 1.0,
   ‘a’} , the result type is std::tuple<std::vector, std::vector,
   std::vector> and the values are: {{1, 1},{1.0, 1.0},{‘a’,
   ‘a’}}
3. Provide a template function “get_vector”, similar to std::get,
   that given the type X as parameter, returns editable access to
   the vector of type X in a tuple of vectors.
   
The following table outlines task number to implementation header 
file. Associated unittests can be found at `src/test`.

| Task | Implementation                |
|------|-------------------------------|
| 1    | positiveIntegerPowerLiteral.h | 
| 2    | tupleToVector.h               |
| 3    | tupleGetVector.h              |