;
; simple dir in assembly
;
	extern opendir
	extern closedir
	extern readdir
	extern puts

;;---------------------------------
	section .bss
dir	resd	1

;;---------------------------------
	section .text
	global main

main:
	push	ebp
	mov	ebp, esp

	push	dword mydir
	call	opendir
	mov	[dir], eax

	push	eax
	call	readdir

	push	dword eax
	call	puts

	push	dword [dir]
	call	closedir	
	
	mov	esp, ebp
	pop	ebp
	mov	eax, 0
	ret

;;------------------------------------
	section .data
mydir:
	db	".",0

