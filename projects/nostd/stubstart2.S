.section .data

hello:	.asciz "Hello World."

.section .text

.globl _start

main:
	retq

_start:
	call main
	movl $1, %eax
	xorl %ebx, %ebx
	int  $0x80
	
