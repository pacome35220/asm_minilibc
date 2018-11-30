	global	strcmp:function
	section	.text

	;; int strcmp(const char *s1, const char *s2)

strcmp:
	xor	rax, rax

.LOOP:
	mov	al, BYTE[rdi]
	cmp	BYTE[rsi], al
	jnz	.DIFF
	cmp	BYTE[rdi], 0
	jz	.EXIT
	inc	rsi
	inc	rdi
	jmp	.LOOP

.DIFF:
	xor	ecx, ecx
	mov	cl, BYTE[rsi]
	sub	eax, ecx
	ret

.EXIT:
	xor	rax, rax
	ret
