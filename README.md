# Hello_Cpp_Using_VSCode

Getting Reacquainted with C++ on MacOS

## C++ Project Start Up

### Check the Environment
- [x] Have VSCode and XCode Installed
- [x] Have C/C++, C/C++ Extension, Cmaske, CMake Tools, CodeLLDB (debugs clang output) all installed in VSCode
- [x] Have XCode command line tools installed
- [x] check which compilers have installed
    - `clang --version` [clang](https://en.wikipedia.org/wiki/Clang) is the default on MacOS. My result: `Apple clang version 14.0.3 (clang-1403.0.22.14.1)`
    - `gcc --version` will likely reveal that its aliasing clang
    - `g++ --version` will likely show the same
- [x] check which version of cmake 
    - `cmake --version` mine `cmake version 3.27.1`
- [x] check which version of make
    - `make --version` mine `GNU Make 3.81`

### Set Up the Project
- [x] Create a [Repo To Work In](https://github.com/carlynorama/Hello_Cpp_Using_VSCode) (github provides a [default gitignore](https://github.com/carlynorama/Hello_Cpp_Using_VSCode/blob/main/.gitignore) to which I added `.DS_Store` and `HelloWorld`)

- [x] Write and compile hello world script via command line

`HelloWorld.cpp`

```cpp
#include <iostream>

int main()
{
    std::cout << "Hello World" << std::endl;
}
```

```zsh
# -o for output file name, 
# if none provided will be a.out https://en.wikipedia.org/wiki/A.out
g++ HelloWorld.cpp -o HelloWorld
./HelloWorld
```

 warning: range-based for loop is a C++11 extension [-Wc++11-extensions]
//https://stackoverflow.com/questions/49269691/why-am-i-getting-a-warning-for-this-range-based-for-loop-in-c
  
              "args": [
                "-fcolor-diagnostics",
                "-fansi-escape-codes",
                //ADDED!
                "-std=c++17",
                "-g",
                "${file}",
                "-o",
                "${fileDirname}/${fileBasenameNoExtension}"
            ],

g++ HelloWorld.cpp -std=c++17 -o HelloWorld

### C++ Review

- Standard Library headers: https://en.cppreference.com/w/cpp/header
- keywords: https://en.cppreference.com/w/cpp/keyword
- Precedence rules: https://en.cppreference.com/w/cpp/language/operator_precedence
- https://cplusplus.com/reference/ 
- https://www.codecademy.com/courses/c-plus-plus-for-programmers/