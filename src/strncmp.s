	global	strncmp:function
	section	.text

	;; int strncmp(const char *s1, const char *s2, size_t n)

strncmp:
	xor	rax, rax	; set return value to 0
	cmp	rdx, 0		; if (n == 0)
	jz	.EXIT		; return 0
	dec	rdx		; n is use as index, so rdx--

.LOOP:
	mov	al, BYTE[rdi]	; al is 8 bytes part of rax : al = *s1
	cmp	BYTE[rsi], al	; if (*s2 != *s1)
	jnz	.DIFF		; return *s2 - *s1
	cmp	BYTE[rdi], 0	; if (*s1 == '\0')
	jz	.EXIT		; jump to return 0
	cmp	rdx, 0		; if (n == 0)
	jz	.EXIT		; return 0
	inc	rdi		; s1++
	inc	rsi		; s2++
	dec	rdx		; n--
	jmp	.LOOP		; loop

.DIFF:
	xor	ecx, ecx	; init tmp to 0
	mov	cl, BYTE[rsi]	; cl is 8 bytes part of rcx : cl = *s2
	sub	eax, ecx	; eax (return value) = eax -= *s2
	ret			; return *s2 - *s1

.EXIT:
	xor	rax, rax	; return 0
	ret
