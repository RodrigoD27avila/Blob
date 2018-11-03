	extern printf

	section .text
	global main

main:
	push	ebp
	mov	ebp, esp

	mov	[myint], dword 900
	mov	eax, [myint]
	push	eax
	push	format
	call	printf
	
	inc	dword [myint]
	mov	eax, [myint]
	push	eax
	push	format
	call	printf

	mov	esp, ebp
	pop	ebp
	mov	eax, 0
	ret

	section	.data

format	db	"> %i",10,0

	section .bss

myint	resd	1
