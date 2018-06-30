	global	strcasecmp:function
	section	.text

strcasecmp:
	xor	rax, rax
	xor	r8, r8
	xor	r9, r9

.LOOP:
	mov	r8b, BYTE[rdi]	; r8b = *s1
	mov	r9b, BYTE[rsi]	; r9b = *s2
	cmp	r8b, 0x41	; 0x41 -> 'A'
	jb	.ARGV_2		; if (r8b < 'A')
	cmp	r8b, 0x5A	; 0x51 -> 'Z'
	ja	.ARGV_2		; if (r8b > 'Z')
	add	r8b, 0x20	; "else" 0x20 -> ' ' -> ('a' - 'A')

.ARGV_2:
	cmp	r9b, 0x41
	jb	.STRCMP
	cmp	r9b, 0x5A
	ja	.STRCMP
	add	r9b, 0x20

.STRCMP:
	mov	al, r8b
	cmp	r9b, al
	jnz	.DIFF
	cmp	r8b, 0
	jz	.EXIT
	inc	rsi
	inc	rdi
	jmp	.LOOP

.DIFF:
	xor	rcx, rcx
	mov	cl, r9b
	sub	eax, ecx
	ret

.EXIT:
	xor	rax, rax
	ret
