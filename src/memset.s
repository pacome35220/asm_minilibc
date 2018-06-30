	global	memset:function
	section	.text

memset:
	mov	rax, rdi
	cmp	rdx, 0
	jz	.EXIT

.LOOP:
	dec	rdx
	mov	BYTE[rdi + rdx], sil
	cmp	rdx, 0
	jnz	.LOOP

.EXIT:
	ret
