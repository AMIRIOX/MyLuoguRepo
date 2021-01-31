# Welcome


> news: 目前已更换至openSUSE Tumbleweed。

菜OIer`amiriox`的[luogu](https://www.luogu.com.cn/)题目code, ~~有一些没AC掉的题~~
我的洛谷主页: [https://www.luogu.com.cn/user/320697](https://www.luogu.com.cn/user/320697)

其中`P????`是题号,如P1551就是[https://www.luogu.com.cn/problem/P1551](https://www.luogu.com.cn/problem/P1551)

文件夹格式的题目在Windows 10/Dev C++下编写, 采用其内置编译器`g++ 8.2.0` (MinGW)

题号为`P????.cpp`格式的在     
* ` (Cl.exe 19.24.28314)`/`Windows 10`/`Visual Studio 2019`/
* `g++ 8.2.0`/`Windows 10`/`Visual Studio Code`/
* `g++ 7.5.0`/`(WSL Ubuntu18.04)`/`Visual Studio Code`
* `g++ (GCC) 10.2.0`/`Manjaro Linux, Kernel 5.8.11~16`/`Visual Studio Code+vim`
* `g++ (GCC) 10.2.0+clang version 10.0.1`/`Manjaro Linux, Kernel 5.8.11~16`/`Atom`
* `g++ (GCC) 10.2.0+clang version 10.0.1`/`CP Editor`
* `g++ (SUSE Linux) 10.2.1 20201202`/`OpenSUSE Tumbleweed 5.10.9-1-default`/`VSCode`

在Dev C++上编译运行的皆加入了下列编译选项, 在vs中的没有加入, 在VSC中的部分加入(`Windows`)部分没加入(`WSL`或`linux`)

```bash
-Wall -Werror -Wextra -pedantic -Wimplicit-fallthrough -Wsequence-point -Wswitch-default -Wswitch-unreachable -Wswitch-enum -Wstringop-truncation -Wbool-compare -Wtautological-compare -Wfloat-equal -Wshadow=global -Wpointer-arith -Wpointer-compare -Wcast-align -Wcast-qual -Wwrite-strings -Wdangling-else -Wlogical-op -std=c++11
```

~~另外, atom对于`CRLF`/`LF`的显示很迷惑, 我明明是linux, 而且vscode显示的也是`LF`, 但atom就给我显示成`CRLF`, 所以换行可能有问题~~    
问题已经解决, 但全部文件使用`CRLF`或`LF`, 如果遇到换行不正常问题, 请

```bash
[  9:28AM ]  [ amiriox@SgrA:~ ]
 $ pacman -Ss dos2unix
community/dos2unix 7.4.2-1
    Text file format converter
```
