	global	strcspn:function
	section	.text

	;; int strncmp(const char *s1, const char *s2, size_t n)

strcspn:
	mov	rax, rdi

.LOOP:
	cmp	BYTE[rax], 0
	jz	.END
	xor	rcx, rcx	; rcx use as index of rsi

.CMP:
	mov	r8b, BYTE[rsi + rcx] ; r8b -> tmp = rsi[rcx]
	cmp	r8b, 0		; while (rsi[rcx] != 0)
	jz	.END_WHILE
	cmp	BYTE[rax], r8b	; if (*s == rsi[rcx])
	jz	.END
	inc	rcx		; rcx++
	jmp	.CMP

.END_WHILE:
	inc	rax
	jmp	.LOOP

.END:
	sub	rax, rdi
	ret
