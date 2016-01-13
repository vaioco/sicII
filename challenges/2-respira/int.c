#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void win(){
	printf("level complete\n");
	_exit(1);
}

void place_int_array(unsigned int slot,int value){
 int array[32];
 array[slot]=value; /* the overwrite itself.   */
 printf("filled slot %u with %d.\n",slot,value);
 return;
}
int main(int argc,char **argv){
 if(argc!=3)
  printf("syntax: %s [slot] [value]\n",argv[0]);
 else
  place_int_array(atoi(argv[1]),atoi(argv[2]));
 exit(0);
}
