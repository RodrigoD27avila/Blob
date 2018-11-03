	org 100h
	section	.text

start:
	mov	ah, 0
	mov	al, 0x13
	int	0x10

	mov	ax, 0xa000
	mov	es, ax
	mov	ax, 67
	mov	bx, 112
	mov	cx, 320
	add	ax, bx
	mov	di, ax
	mov	dl, 7
	mov	[es:di], dl

wl:	mov	ah, 0
	int 	0x16
	jz	wl

	mov	ah, 0
	mov	al, 3
	int	0x10
