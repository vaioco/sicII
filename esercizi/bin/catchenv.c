#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

  char *pointer;

  if(argc != 2) {
    printf("Usage: %s <variable>\n", argv[0]);
    exit(-1);
  }

  pointer = getenv(argv[1]);

  if(pointer == NULL) {
    printf("Environmental variable %s does not exist!\n", argv[1]);
    exit(-1);
   }

  printf("%s is stored at address 0x%lx\n", argv[1], pointer);
  
  return 1;
}
