# Hello_Cpp_Using_VSCode

Getting Reacquainted with C++ on MacOS

### Check the Environment

C++ needs a compiler. Confirm what tools are available. My result on checking:

```zsh
clang --version     # Apple clang version 14.0.3 (clang-1403.0.22.14.1)
gcc --version       # aliases clang
g++ --version       # also aliases clang
cmake --version     # cmake version 3.27.1
make --version      # GNU Make 3.81
```

### Set Up Project

```zsh
mkdir $PROJECT_NAME
cd $PROJECT_NAME
git init
touch .gitignore
touch HelloWorld.cpp
```

#### gitignore

GitHub [provides more](https://github.com/github/gitignore/blob/main/C%2B%2B.gitignore), but bare minium:

```bash
.DS_Store

HelloWorld # Leave out build of default script
# Will eventually put all binaries in a bin folder
bin/
*.out #in case forget to add a -o flag to compiler call

## Apple for iOS
## can turn them off by not using -g in compiler call
## or using -g0 compiler flag
*.dSYM

```

#### HelloWorld.cpp

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

### Set Up VSCode

#### Compile Options

With a .cpp file open, hit the run button on the top right to [link clang up to VSCode](https://code.visualstudio.com/docs/cpp/config-clang-mac). A `tasks.json` file will be generated. The below is an example of tha file after choosing `clang++ build active file`, with some noted changes. 

For more on available arguments: 
 - https://clang.llvm.org/docs/ClangCommandLineReference.html
 - https://clang.llvm.org/get_started.html
 - https://gcc.gnu.org/onlinedocs/gcc/
 - C++ status: https://clang.llvm.org/cxx_status.html
 - on dSYM files: https://developer.apple.com/videos/play/wwdc2021/10211/

### tasks.json

```json
{
    "tasks": [
        {
            "type": "cppbuild",
            "label": "C/C++: clang++ build active file",
            "command": "/usr/bin/clang++",
            "args": [
                "-fcolor-diagnostics",
                "-fansi-escape-codes",
                //ADDED!
                "-std=c++17",
                //-g is default, -g0 turns off the creation of .dSYM files
                "-g0",
                "${file}",
                "-o",
                //default: ${fileDirname}/${fileBasenameNoExtension}
                "${workspaceFolder}/bin/${fileBasenameNoExtension}"
            ],
            "options": {
                "cwd": "${fileDirname}"
            },
            "problemMatcher": [
                "$gcc"
            ],
            "group": {
                "kind": "build",
                "isDefault": true
            },
            "detail": "Task generated by Debugger."
        }
    ],
    "version": "2.0.0"
}
```

It's possible to use a later library via a command line compile, too: 

```zsh
g++ HelloWorld.cpp -std=c++17 -o HelloWorld
./HelloWorld
```

#### Formatting Options

VSCode's default style is to put the opening curly brace below the starting line, but this is [easily changed](https://stackoverflow.com/questions/46111834/format-curly-braces-on-same-line-in-c-vscode) by adding the following line to the workspace's `.vscode/settings.json` 

```json
{ 
    //other settings...,
    "C_Cpp.clang_format_fallbackStyle": "LLVM"
}

```

To be fancier provide a `.clang-format` file in the project's root directory. An added benefit, a `.clang-format` file will be usable by others not using VSCode.  

```yaml
---
Language:    	Cpp
# BasedOnStyle:  LLVM
AccessModifierOffset: -4
IndentWidth: 4
TabWidth: 4
AlignAfterOpenBracket: Align
AlignConsecutiveMacros: false
AlignConsecutiveAssignments: false
```

- https://code.visualstudio.com/docs/cpp/cpp-ide#_code-formatting
- https://clang.llvm.org/docs/ClangFormat.html
- https://www.clangpowertools.com/blog/getting-started-with-clang-format-style-options.html


## C++ Review

### Resources

- Standard Library headers: https://en.cppreference.com/w/cpp/header
- keywords: https://en.cppreference.com/w/cpp/keyword
- Precedence rules: https://en.cppreference.com/w/cpp/language/operator_precedence
- https://cplusplus.com/reference/ 
- Easy clear course to blow through, down side, requires (free) account: https://www.codecademy.com/courses/c-plus-plus-for-programmers/

Also when back and looked at a [2021 project](https://github.com/SketchingInHardware/skommunity) to remind myself about Templates. Originally cribbed from [FastLED](https://github.com/FastLED/FastLED) a really well written hardware library. 

### Included Files

Each file can be compiled and run independently.

- **HelloWorld.cpp**: miscellaneous things to remember about C++
- **Classes.cpp**: How Classes and inheritance work
- **Containers.cpp**: Various data types like, arrays, vectors, stacks, queues, sets and maps. 



#### Multi-file CMake Example

Not currently set up to build with VSCode run button, but with CMake directly.

```bash
cd MultiFileExample/source
cmake -S . -B ../build
cmake --build ../build 
../build/PrimeEmitter # gives random prime
../build/PrimeEmitter 3 998 9999 # gives 3rd, 998th and 9999th prime
```