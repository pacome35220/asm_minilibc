	global	strlen:function
	section	.text

strlen:	xor	rax, rax

.LOOP:
	cmp	BYTE[rdi + rax], 0
	jz	.EXIT
	inc	rax
	jmp	.LOOP

.EXIT:
	ret
