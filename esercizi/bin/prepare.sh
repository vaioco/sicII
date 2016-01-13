#!/bin/bash
USER=`whoami`
if [ $USER != 'root' ]; then
  echo 'Error: execute as root user!!'
  exit
fi
echo 0 > /proc/sys/kernel/randomize_va_space
echo 'ASLR disabilitato!'
