	section .text
	global main

main:
	push	ebp
	mov	ebp, esp



	mov	esp, ebp
	pop	ebp
	mov	eax, 0
	ret

myfunc1:
	push	ebp
	mov	ebp, esp
