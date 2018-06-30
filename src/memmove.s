	global	memmove:function
	section	.text

memmove:
	cmp	rsi, rdi
	jb	.MEMCPY
	mov     rax, rdi
	mov     rcx, rdx
	mov     rdx, rsi
	cld
	rep     movsb
	mov     rsi, rdx
	mov     rdi, rax
	ret

.MEMCPY:
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
