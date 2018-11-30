	global	memset:function
	section	.text

	;; void *memset(void *s, int c, size_t n)

memset:
	mov	rax, rdi	; mov first parameter to rax (return value)
	cmp	rdx, 0		; if rdx (third paramter) == 0
	jz	.EXIT		; don't try to memset anything

.LOOP:
	dec	rdx		; third parameter use as an index
	mov	BYTE[rdi + rdx], sil ; write 8-bit part of second parameter to memory
	cmp	rdx, 0		     ; if (n != 0)
	jnz	.LOOP		     ; jnz => jump if not zero

.EXIT:
	ret
