	global	memcpy:function
	section	.text

	;; void *memcpy(void *dest, const void *src, size_t n)

memcpy:
	mov	rax, rdi	; return a pointer to dest (rdi)
	cmp	rdx, 0		; if (n == 0)
	jz	.EXIT		; don't try to copy anything

.LOOP:
	dec	rdx		; third parameter use as index
	mov	r8b, BYTE[rsi + rdx] ; r8b = src[n]
	mov	BYTE[rdi + rdx], r8b ; dest[n] = r8b => copy
	cmp	rdx, 0		     ; if (n != 0)
	jnz	.LOOP		     ; loop

.EXIT:
	ret
