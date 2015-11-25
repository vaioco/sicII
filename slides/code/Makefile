
CC=gcc
CFLAGS=-fno-stack-protector -z execstack -m32 -ggdb
SRCS = $(wildcard *.c)
PROGS = $(patsubst %.c,%,$(SRCS))
all: $(PROGS)
%: %.c ; $(CC) $(CFLAGS) -o $@ $<
clean: ; rm $(PROGS)

