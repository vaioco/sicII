#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {
	int cookie;
	char buf[80];

	printf("buf: %08x cookie: %08x\n", &buf, &cookie);
	strcpy(buf, argv[1]);

	if (cookie == 0x41424344)
		printf("you win!\n");
}
