	extern printf	

	section .text
	global main
main:
	push	ebp
	mov	ebp, esp

	push	dword hellocdecl
	call	printf

	push	dword 1
	push	dword 2
	push	dword 3
	call	customfunc

	push	eax
	push	format
	call	printf

	mov	esp, ebp
	pop	ebp
	ret

customfunc:
	
	push	ebp
	mov	ebp, esp

	mov	eax, [esp+8]
	mov	ebx, [esp+12]
	add	eax, ebx
	mov	ebx, [esp+16]
	add	eax, ebx

	mov	esp, ebp
	pop	ebp
	ret

	section .data
hellocdecl:
	db	"Hello cdecl!!",10,0

format:
	db	"%d",10,0
	
