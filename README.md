# RabbitOS

**参考书目：一个操作系统的实现**

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


<br><br>
>希望每天都能commit
continue...
