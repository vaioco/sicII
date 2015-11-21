# Software (In)security - corso di sicurezza II

per scaricare il repository del corso eseguite il comando:

```
git clone https://github.com/vaioco/sicII.git
```

nella cartella "esercizi/" trovate gli esercizi da completare durante il corso.

usate il comando "make" per compilare gli esercizi.

#dependencies

+ apt-get install build-essentials git binutils
+ checksec.sh
+ hopperapp
+ GDB

#disable ASLR
echo 0 > /proc/sys/kernel/randomize_va_space

#compilation flags
-fno-stack-protector -z execstack -mpreferred-stack-boundary=2 -m32

#add debug info 
-g

# Link utili

* An [ELF] [1] Format by example 
* ELF Format [specification] [2]
* [GDB] [3] tutorial and [cheatsheet] [4]
* how to use [objdump] [5]
* [Smashing the stack for fun and profit] [6]
* [Smashing the stack in 2010] [7]
* [layout dei binari in memoria] [8]
* [x86 assembly guide] [9]

[1]: http://www.linuxjournal.com/article/1060 "ELF example"
[2]: http://www.skyfree.org/linux/references/ELF_Format.pdf "ELF format"
[3]: http://www.yolinux.com/TUTORIALS/GDB-Commands.html "GDB"
[4]: http://www.cs.berkeley.edu/~mavam/teaching/cs161-sp11/gdb-refcard.pdf "GDB cheatsheet"
[5]: http://www.thegeekstuff.com/2012/09/objdump-examples/ "objdump"
[6]: http://insecure.org/stf/smashstack.html "smashing the stack"
[7]: http://www.mgraziano.info/docs/stsi2010.pdf "smashing 2010"
[8]: http://www.geeksforgeeks.org/memory-layout-of-c-program/ "memory layout"
[9]: http://www.drpaulcarter.com/pcasm/ "x86 guide"
