	org 100h
	section	.text

start:
	mov	ah, 0
	mov	al, 0x13
	int	0x10

	mov	ax, 0xa000
	mov	es, ax
	mov	cx, 320
	add	di, 67
	add	di, 112
	mov	dl, 7
	mov	[es:di], dl

wl:	mov	ah, 0
	int 	0x16
	jz	wl

	mov	ah, 0
	mov	al, 3
	int	0x10
