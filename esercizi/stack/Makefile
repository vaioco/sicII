
CC=gcc
CFLAGS=-fno-stack-protector -z execstack -m32 -ggdb -mpreferred-stack-boundary=2
SRCS = $(wildcard *.c)
PROGS = $(patsubst %.c,%,$(SRCS))
all: $(PROGS)
%: %.c ; $(CC) $(CFLAGS) -o $@ $<
clean: ; rm $(PROGS)

