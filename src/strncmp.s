	global	strncmp:function
	section	.text

	;; int strncmp(const char *s1, const char *s2, size_t n)

strncmp:
	xor	rax, rax
	cmp	rdx, 0
	jz	.EXIT
	dec	rdx

.LOOP:
	mov	al, BYTE[rdi]
	cmp	BYTE[rsi], al
	jnz	.DIFF
	cmp	BYTE[rdi], 0
	jz	.EXIT
	cmp	rdx, 0
	jz	.EXIT
	inc	rsi
	inc	rdi
	dec	rdx
	jmp	.LOOP

.DIFF:
	xor	ecx, ecx
	mov	cl, BYTE[rsi]
	sub	eax, ecx
	ret

.EXIT:
	xor	rax, rax
	ret
