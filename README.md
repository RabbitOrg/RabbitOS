# RabbitOS

```
 ____       _     _     _ _      ___  ____  
|  _ \ __ _| |__ | |__ (_) |_   / _ \/ ___| 
| |_) / _` | '_ \| '_ \| | __| | | | \___ \ 
|  _ < (_| | |_) | |_) | | |_  | |_| |___) |
|_| \_\__,_|_.__/|_.__/|_|\__|  \___/|____/ 

```

**参考书目：一个操作系统的实现**

Edit by tsengkasing

<br>

Usage:

```
$make image
$cd ./command
$make install
$cd ..
$bochs -f bochsrc
```

##版本1.3.0

```
=============================================================================

Rabbit OS bash, version 1.0.0-release
These shell commands are defined internally. Type 'help' to see this list.
help      :  Display this help message
echo      :  Print the arguments to the screen
pwd       :  Show the current directory
time      :  Print the current time
ps        :  Print the status of processes
touch     :  Create a file
rm        :  delete a file
mv        :  move a file
ls        :  List all files
cat       :  Show the content of file
vi        :  Edit the file
cpuinfo   :  Show the infomation of CPU

=============================================================================
```

##版本1.2.0

- 增加cpuinfo | time | vi 命令，完善控制台


##版本1.1.5

- 修改开机动画

- 增加help信息
<code>$help</code>

- 明白了之前卡死的问题是因为用的是bochs x86 emulator , 改成用 bochs x86-64 emulator 就可以解决卡死异常的问题。
所以建议后人不要下载bochs的tar包然后重新编译安装 而是直接
<code>sudo apt-get install bochs bochs-x bochs-sdl</code>

具体问题参考
[bochs安装一系列问题](http://www.cnblogs.com/zhangze/p/3143054.html)


##版本1.1.2

**只能读1024字节的cat指令以及可以创建文件的touch指令**

1.在/command 中 增加一个cat.c

2.修改/command/MakeFile 增添对此的编译即可

3.因为只需调用之前文件系统写好的open()和read()等等函数，故不需要写其他文件的代码。

**增加一个ls指令**

1.在/command 中 增加一个 ls.c

2.修改/command/MakeFile

```
BIN = ... ls
ls.o: ls.c ../include/stdio.h
	$(CC) $(CFLAGS) -o $@ $<

ls : ls.o start.o $(LIB)
	$(LD) $(LDFLAGS) -o $@ $?
```

3./include/sys/const.c msgtype 增加新的消息类型枚举类型

4./lib 增加一个list.c <br>并且在/include/stdio.h 中增加list函数的声明

5.修改MakeFile 加上对 /lib/list.c的编译

6.修改/fs/main.c 

```
修改task_fs()
增加fs_list()
```

读写一定要记得 进入内核态后 虚拟地址和物理地址的转换 我在这里浪费了好几个小时。

```
char* str = "something you want to copy";
/*
*  src 		->  msg.source
*  buf 		->  target memory
*  bytes_rw 	->  offset
*/
phys_copy((void*)va2la(src, buf + bytes_rw),
			str,
			strlen(str));
```

##版本1.0

Orange's OS
<br>
书中的chapter10/e 代码
<br>
切换控制台的按键Alt + Fn 改为 Ctrl + Fn 
<br>
Rabbit OS启动界面


##章节

###第一章

wow 好酷！

###第二章

配环境。
配环境。
配环境。

一定要装**32位**的Ubuntu ！！！
64位的系统从书上P140开始遇到的**ld**指令和32位系统**不兼容**，并且没有很好的办法模拟32位操作。

bochs进入调试模式要按c 开始模拟！

###第三章

懵逼。

###第四章

boot.bin **->** loader.bin

从boot引导扇区启动,然后加载loader

###第五章

**用汇编语言写hello world！**

boot.bin <b style="color:red;">-></b> loader.bin <b style="color:red;">-></b> kernel.bin

实现了从引导扇区的启动,加载loader,再从loader加载kernel,进入保护模式。

增加了异常处理机制。

**接下来的工作是在已经搭建好的框架上完成，并且大部分将用可读性较好的C语言编写**

**"最困难的日子已经过去，虽然眼前的路仍然很长，但是我们不再感觉是在无边的黑暗中探索，眼前是一条光明大道，等待我们踏入新的征程。"**

###第六章

进程！！！

完成进程调度 需要

1.时钟中断处理程序
2.进程调度模块
3.多个进程体

时钟中断是用汇编写的 (就不说了

进程调度也是在中断中处理的 (也是汇编

---------------准备进程表---------------

测试用的进程只是一个无限循环打印字母A和i++的函数，但是实现从ring0到ring1的跳转并执行这个进程需要很多步骤，特别是对堆栈段的处理，TSS|GDT|LDT|SS...
PCB进程控制块是一个是``` s_proc ```的结构体,该结构体的第一个成员还是一个结构体(```s_stackframe```)，存储所有的寄存器的值。

中断处理
解决嵌套重入中断问题，添加一个全局变量```k_reenter = -1;``` 每进入一次嵌套中断自增，判断是否为0来知道是否嵌套中断。

学习借鉴Minix的中断处理模块后修改了本来的代码，将其模块化 划分成save | restart 等多段清晰的代码段。
算是达到了一个里程碑 (黑人问号？？？？

接下来谈到了系！统！调！用！

终于在第247页讲到了我一直很想知道的时钟中断的时间间隔以及由谁产生的中断！

**进程调度**

在之前实现的时间片轮转调度算法后，再实现了简单的优先级调度～


###第七章

I/O！！！

P267 & P268 ----- 键盘中断 MakeCode & BreakCode

各种与运算或与运算宝宝看不懂啊！！！！
什么鬼啊！！！

**垃圾Bug - 0**

垃圾GCC编译器版本 makefile不通过

<code>Error : undefined reference to '__stack_chk_fail'</code>

需要改MakeFile里面的CFLAGS 加上 ```-fno-stack-protector```
<br>
即CFLAGS	= -I include/ -c -fno-builtin -fno-stack-protector


**垃圾Bug - 1**

在bochs下按Alt + Fn 这个组合键只会相应ubuntu的全局快捷键，不能响应虚拟机里面的操作 **冷漠**
于是请教吕老师，给出的回答是把Alt + Fn组合键改成ctrl + Fn这种组合键 **简单粗暴**

P315 ----- 增加一个系统调用 需要的步骤。


###第八章

进程间通信！！！

Minix->微内核<br>Linux->宏内核

assert() 和 panic() 

printl() --> printf() --> printx()

将之前的get_ticks()用消息通信机制重新实现，内核态代码大概不会再改动～


###第九章

文件系统！！！

硬盘驱动程序 硬盘系统进程

用bximage新建一个80M的硬盘 '80m.img'

```
SuperBlock -> Metadata
Sector map
inode_array
inode map
```

分区好复杂？？？

#####文件系统

<code>include/fs.h  ```#define MAGIC_V1 0x111```   -->  应该自定义为RabbitOS专属的代号</code>

**磁盘读写**
可以改进成电梯扫描法！～

**扁平文件系统**
可以改成树形/多级目录/无环图 文件系统！～

而且它现在只能存4096个文件？？？

读写文件还要创建4个'系统调用'。

-----我已经开始跳着看了。。代码量越来越多了-----

```strip_path()``` 根据路径返回文件名及其所在inode

P425第二段第三行末尾两个错别字-->'接触' : '解除';

终于结束第九章了。。。好长啊（冷漠

###第十章

内存管理！！！

P454 可以被链接成库的文件

严重的**BUG**

chapter10/c 

作者写的pwd应用程序，解压缩cmd.tar 然后使用write()写进硬盘的时候 会卡住，无法继续运行。 目前强行break跳过，但是在shell使用pwd程序就会卡死。

<br>
不过完成了一个可以实现echo的shell还是值得庆祝。

###第十一章

尾声。

官网已经没有书中说的0.97版本的grub了，只有1.99和2.00的grub，然而我都没有办法编译成功。
<br>
后来发现是编译时需要  ```./configure --disable-werror```

<br><br>

>希望每天都能commit

continue...
