	global	atoi:function
	section	.text

	;; int atoi(const char *nptr)

atoi:
	xor	eax, eax	; set integer result to 0, eax is 32-bit part of rax
	xor	r8, r8		; set r8 to 0
	cmp	BYTE[rdi], 0x2D	; 0x2D => '-'
	jnz	.LOOP		; if first byte != '-', jump to loop

.INIT_NEG:			; ... else
	inc	rdi		; nptr++ to skip '-'
	mov	dl, 1		; set a flag to remember integer is negative

.LOOP:
	mov	r8b, BYTE[rdi]	; r8b use as tmp variable (8-bit part of r8)
	cmp	r8b, 0x30	; 0x30 => '0'
	jb	.EXIT		; jump if (r8b < 'A')
	cmp	r8b, 0x39	; 0x39 => '9'
	ja	.EXIT		; jump if (r8b > 'Z')

	imul	eax, 10		; eax *= 10
	add	eax, r8d	; 64-bit (complete) of r8b
	sub	eax, 0x30	; Ox30 => '0'

	inc	rdi		; nptr++
	jmp	.LOOP		; loop

.EXIT:
	cmp	dl, 1		; if flag if set
	jz	.NEG_IT		; jump to neg the integer
	ret			; or just simply return

.NEG_IT:
	neg	eax		; set sign bit
	ret			; and return negative integer
