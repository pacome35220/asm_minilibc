	global	strcspn:function
	section	.text

	;; size_t strcspn(const char *s, const char *reject)

strcspn:
	mov	rax, rdi	; mov first parameter to rax (return value)

.LOOP:
	cmp	BYTE[rax], 0	; if (*s == '\0')
	jz	.END		; return rax - s
	xor	rcx, rcx	; rcx use as index

.CMP:
	mov	r8b, BYTE[rsi + rcx] ; r8b -> tmp = reject[rcx]
	cmp	r8b, 0		; while (reject[rcx] != 0)
	jz	.END_WHILE	; jump to rcx++
	cmp	BYTE[rax], r8b	; if (*s == reject[rcx])
	jz	.END		; return rax - s
	inc	rcx		; rcx++
	jmp	.CMP		; loop reject[rcx]

.END_WHILE:
	inc	rax		; rax++
	jmp	.LOOP		; main loop

.END:
	sub	rax, rdi	; rax -= s
	ret
