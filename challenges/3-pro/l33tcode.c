/*
 ottenere una shell di sistema

*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>


void notcallme(){
	system("/bin/sh");
}

void foo(){
	printf("fooooooo\n");
}

void magic(int usr1, int usr2){
	printf("argomenti: %d , %d \n", usr1, usr2);
	void (*fp)();
	char buf[80];
	void* p = buf;
        printf("p vale = 0x%x\n", p);	
	fp = foo;
	fp();
	
	p = p + usr1;
	memcpy(p, &usr2, 4);
	
	fp();
	printf("dropping beer or shell?\n");
}

int main(int argc, char **argv)  
{
  if(argc<2){
 	printf("usage %s intero intero \n", argv[0]);
	_exit(1);
  }
  char buffer[64];

  gets(buffer);
  magic(atoi(argv[1]), atoi(argv[2]));
}
