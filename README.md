# sicII

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

