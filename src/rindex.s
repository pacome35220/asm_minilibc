	global	rindex:function
	section	.text

	;; char *rindex(const char *s, int c)

rindex:
	xor	eax, eax	; init rax to NULL because not found return NULL

.LOOP:
	mov	cl, BYTE[rdi]	; cl = *s (cl is 8-bit part of rcx, use as tmp)
	cmp	cl, sil		; sil is the searched byte
	cmove	rax, rdi	; if (*s == c) => save address

	;; cmove is performed if condition flag is set

	inc	rdi		; s++
	cmp	cl, 0		; if (*(s - 1) == '\0')
	jne	.LOOP		; loop
	ret			; return
