#include <stdio.h>
/* 

     convert .s to shellcode. typo/teso (typo@inferno.tusculum.edu)

$ cat lala.s
.globl cbegin
.globl cend
cbegin:
        xorl %eax, %eax
  ...
cend:
$ gcc -Wall lala.s outp.c -o lala
$ ./lala
unsigned char shellcode[] =
"\x31\xc0\x31\xdb\x31\xc9\xb3\x0f\xb1\x0f\xb0\x47\xcd\x80\xeb\x1e\x5b"
"\x31\xc0\x88\x43\x07\x89\x5b\x08\x89\x43\x0c\x8d\x4b\x08\x8d\x53\x0c"
"\xb0\x0b\xcd\x80\x89\xc3\x31\xc0\xb0\x01\xcd\x80\xe8\xdd\xff\xff\xff"
"\x2f\x74\x6d\x70\x2f\x74\x73\x74\x65\x73\x6f\x63\x72\x65\x77\x21\x21";
...

*/

extern void     cstart();
extern void     cend();

int main() {
    char *buf = (char *) cstart;
    int i = 0, x = 0;

    printf("unsigned char shellcode[] = \n\"");
    for (; (*buf) && (buf < (char *) cend); buf++) {
        if (i++ == 17) i = 1;
        if (i == 1 && x != 0) printf("\"\n\""); 
        x = 1;
        printf("\\x%02x", (unsigned char) *buf);
    }
    printf("\";\n");
	
	printf("int main() {"
    "void (*f)();"
    "f = (void *) shellcode;"
    "printf(\"%%d\\n\", strlen(shellcode));"
    "f();}");

    return(0);
}

