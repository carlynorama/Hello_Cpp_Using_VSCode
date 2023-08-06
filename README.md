# Hello_Cpp_Using_VSCode


## C++ Project Start Up

- [x] Have VSCode Installed
- [x] Have C/C++, C/C++ Extension, Cmaske, CMake Tools, CodeLLDB (debugs clang output) all installed in VSCode
- [x] Have XCode command line tools installed
- [x] Create a [Repo To Work In](https://github.com/carlynorama/Hello_Cpp_Using_VSCode) (github provides a [default gitignore](https://github.com/carlynorama/Hello_Cpp_Using_VSCode/blob/main/.gitignore) to which I added `.DS_Store` and `HelloWorld`)
- [x] Scan / light review of Standard Library headers: https://en.cppreference.com/w/cpp/header
- [x] Scan/ light review of keywords: https://en.cppreference.com/w/cpp/keyword
- [x] check which compilers have installed
    - `clang --version` [clang](https://en.wikipedia.org/wiki/Clang) is the default on MacOS. My result: `Apple clang version 14.0.3 (clang-1403.0.22.14.1)`
    - `gcc --version` will likely reveal that its aliasing clang
    - `g++ --version` will likely show the same
- [x] check which version of cmake 
    - `cmake --version` mine `cmake version 3.27.1`
- [x] check which version of make
    - `make --version` mine `GNU Make 3.81`
- [x] Write and compile hello world script via command line

`HelloWorld.cpp`

```cpp
#include <iostream>

int main()
{
    std::cout << "Hello World" << std::endl;
}
```

```
g++ HelloWorld.cpp -o HelloWorld
./HelloWorld
```

