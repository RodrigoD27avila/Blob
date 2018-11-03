.section .text
.globl _start

_start:
	nop
	movl $0x384, %eax
	movl $0x1f4, %ebx
	subl %ebx, %eax
	movl $0x10, %ebx
	addl %ebx, %eax
	
quit:
	movl $1, %eax
	movl $0, %ebx
	int  $0x80
