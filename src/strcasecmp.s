	global	strcasecmp:function
	section	.text

	;; int strcasecmp(const char *s1, const char *s2)

strcasecmp:
	xor	rax, rax
	xor	r8, r8
	xor	r9, r9

.LOOP:
	mov	r8b, BYTE[rdi]	; r8b = *s1
	mov	r9b, BYTE[rsi]	; r9b = *s2
	cmp	r8b, 0x41	; 0x41 -> 'A'
	jl	.ARGV_2		; if (r8b < 'A')
	cmp	r8b, 0x5A	; 0x51 -> 'Z'
	jg	.ARGV_2		; if (r8b > 'Z')
	add	r8b, 0x20	; "else" 0x20 -> ' ' -> ('a' - 'A')

.ARGV_2:
	cmp	r9b, 0x41	; if (*s2 < 'A')
	jl	.STRCMP		; jump to compare
	cmp	r9b, 0x5A	; if (*s2 > 'Z')
	jg	.STRCMP		; jump to compare
	add	r9b, 0x20	; "else" 0x20 -> ' ' -> ('a' - 'A')

.STRCMP:
	mov	al, r8b		; al is 8 bytes part of rax : al = *s1
	cmp	r9b, al		; if (*s2 != *s1)
	jnz	.DIFF		; return *s2 - *s1
	cmp	r8b, 0		; if (*s1 == '\0')
	jz	.EXIT		; return 0
	inc	rdi		; s1++
	inc	rsi		; s2++
	jmp	.LOOP		; loop

.DIFF:
	xor	rcx, rcx	; init tmp to 0
	mov	cl, r9b		; cl is 8 bytes part of rcx : cl = *s2
	sub	eax, ecx	; eax (return value) = eax -= *s2
	ret			; return *s2 - *s1

.EXIT:
	xor	rax, rax	; return 0
	ret
