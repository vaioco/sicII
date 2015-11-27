global _start
global cstart
global cend
cstart:
	jmp heh
 
go_back:
	xor eax, eax
	xor ebx, ebx
	xor edx, edx
	mov al,0x4
	mov dl,0x9
	pop ecx
	mov bl,0x1
	int 0x80
	xor eax, eax
	inc eax
	int 0x80

heh:
   call go_back
   db 'you win!\n'
cend:
