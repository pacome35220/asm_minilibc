	global	strcmp:function
	section	.text

	;; int strcmp(const char *s1, const char *s2)

strcmp:
	xor	rax, rax	; set return value to 0

.LOOP:
	mov	al, BYTE[rdi]	; al is 8 bytes part of rax : al = *s1
	cmp	BYTE[rsi], al	; if (*s2 != *s1)
	jnz	.DIFF		; return *s2 - *s1
	cmp	al, 0		; if (*s1 == '\0')
	jz	.EXIT		; jump to return 0
	inc	rdi		; s1++
	inc	rsi		; s2++
	jmp	.LOOP		; loop

.DIFF:
	xor	ecx, ecx	; init tmp to 0
	mov	cl, BYTE[rsi]	; cl is 8 bytes part of rcx : cl = *s2
	sub	eax, ecx	; eax (return value) = eax -= *s2
	ret			; return *s2 - *s1

.EXIT:
	xor	rax, rax	; return 0
	ret
