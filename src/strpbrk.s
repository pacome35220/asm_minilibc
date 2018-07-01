	global	strpbrk:function
	section	.text

strpbrk:
	mov	rax, rdi

.LOOP:
	cmp	BYTE[rax], 0
	jz	.EXIT
	xor	rcx, rcx	; rcx use as index

.CMP:
	mov	r8b, BYTE[rsi + rcx]
	cmp	r8b, 0		; while (rsi[rcx] != 0)
	jz	.END_WHILE
	cmp	BYTE[rax], r8b	; if (*s == rsi[rcx])
	jz	.FIND
	inc	rcx		; rcx++
	jmp	.CMP

.END_WHILE:
	inc	rax
	jmp	.LOOP

.EXIT:
	xor	rax, rax

.FIND:
	ret
