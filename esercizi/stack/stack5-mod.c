/* stack5-stdin.c                               *
 * specially crafted to feed your brain by gera */

#include <stdio.h>

int main(int argc, char** argv) {
	if(argc < 2){
        printf("argument missed!!\n");
        return 0;
    }

	myfunc(argv[1]);
	printf("this is the return address for myfunc\n");

}

void myfunc(char* src)
{
	int cookie;
	char buf[80];
	printf("buf: %08x cookie: %08x\n", &buf, &cookie);
	strcpy(buf,src);
	if (cookie == 0x000d0a00)
		printf("you loose!\n");
}
