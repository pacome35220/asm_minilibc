	global	memcpy:function
	section	.text

memcpy:
	mov	rax, rdi
	cmp	rdx, 0
	jz	.EXIT

.LOOP:
	dec	rdx
	mov	r8b, BYTE[rsi + rdx]
	mov	BYTE[rdi + rdx], r8b
	cmp	rdx, 0
	jnz	.LOOP

.EXIT:
	ret
