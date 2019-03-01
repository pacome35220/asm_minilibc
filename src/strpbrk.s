	global	strpbrk:function
	section	.text

	;; char *strpbrk(const char *s, const char *accept)

strpbrk:
	mov	rax, rdi	; mov first parameter to rax (return value)

.LOOP:
	cmp	BYTE[rax], 0	; if (*s == '\0')
	jz	.EXIT		; return NULL
	xor	rcx, rcx	; rcx use as index

.CMP:
	mov	r8b, BYTE[rsi + rcx] ; r8b -> tmp = accept[rcx]
	cmp	r8b, 0		; while (rsi[rcx] != 0)
	jz	.END_WHILE	; jump to rcx++
	cmp	BYTE[rax], r8b	; if (*s == accept[rcx])
	jz	.FIND		; return rax
	inc	rcx		; rcx++
	jmp	.CMP		; loop accept[rcx]

.END_WHILE:
	inc	rax		; rax++
	jmp	.LOOP		; main loop

.EXIT:
	xor	rax, rax	; return 0

.FIND:
	ret			; return ptr
