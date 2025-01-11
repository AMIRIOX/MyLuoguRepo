# Welcome

## Author: @amiriox
* 洛谷: [https://www.luogu.com.cn/user/320697](https://www.luogu.com.cn/user/320697)
* Codeforces: [https://codeforces.com/profile/AMIRIOX](https://codeforces.com/profile/AMIRIOX)
* AtCoder: [https://atcoder.jp/users/amiriox](https://atcoder.jp/users/amiriox)

## Environment
主要编译环境：
|       Compiler        |       Operating System    |           Editor           |
|:----------------------|:-------------------------:|---------------------------:|
| `g++ MinGW 8.2.0`     | `Windows 10`              | `Dev C++ (Customized)`     |
| `Cl.exe 19.24.28314`  | `Windows 10`              | `Visual Studio 2019`       |
| `g++ 8.2.0`           | `Windows 10`              | `Visual Studio Code`       |
| `g++ 7.5.0`           | `WSL Ubuntu 18.04`        | `Visual Studio Code`       |
| `g++ (GCC) 10.2.0`    | `Manjaro, Kernel 5.8.16+` | `Visual Studio Code / vim` |
| `g++ (GCC) 10.2.0`    | `Manjaro, Kernel 5.8.16+` | `Atom`                     |
| `clang 10.0.1`        | `Manjaro, Kernel 5.8.16+` | `Atom`                     |
| `g++ (GCC) 10.2.01`   |                           | `CP Editor`                |
| `clang 10.0.1`        |                           | `CP Editor`                |
| `g++ (SUSE Linux) 10+`| `OpenSUSE Tumbleweed`     | `VSCode`                   |
| `g++ (GCC) 14.1.1+`   | `Arch Linux`              | `Sublime / Neovim / CP Editor`|
| `g++ (GCC) 14.1.1+`   | `Arch Linux`              | `Neovim`                   |
| `g++.exe (TDM) 4.9.2` | `Windows 11`              | `Sublime`                  |
| `g++ (GCC) 14.2.1`    | `Fedora 40 (WSL)`         | `Neovim`                   |

部分题目使用了如下的 GCC 编译选项。(很长）
```bash
-Wall -Werror -Wextra -pedantic -Wimplicit-fallthrough -Wsequence-point -Wswitch-default -Wswitch-unreachable -Wswitch-enum -Wstringop-truncation -Wbool-compare -Wtautological-compare -Wfloat-equal -Wshadow=global -Wpointer-arith -Wpointer-compare -Wcast-align -Wcast-qual -Wwrite-strings -Wdangling-else -Wlogical-op -std=c++11
```

部分题目使用了如下的 GCC 编译选项。
```makefile
VERSION = -std=c++20
CXXFLAGS = -pipe -Wall -D_DEBUG -Wall -Werror -Wextra -pedantic -Wimplicit-fallthrough -Wsequence-point -Wswitch-default -Wswitch-unreachable -Wswitch-enum -Wstringop-truncation -Wbool-compare -Wtautological-compare -Wfloat-equal -Wshadow=global -Wpointer-arith -Wpointer-compare -Wcast-align -Wcast-qual -Wconversion -Wwrite-strings -Wdangling-else -Wlogical-op -finput-charset=utf-8 -fexec-charset=utf-8
```

部分题目使用较新的 [C++ 17](https://en.cppreference.com/w/cpp/17) 或 [C++ 20](https://en.cppreference.com/w/cpp/20) 标准进行编译和提交。

## Imperfection
代码文件使用 CRLF 或 LF (大部分应该都是 LF ), 如果遇到换行不正常问题, 请尝试使用 [dos2unix](https://archlinux.org/packages/extra/x86_64/dos2unix/)
```bash
ξ pacman -Ss dos2unix
extra/dos2unix 7.5.2-2
    Text file format converter
```

