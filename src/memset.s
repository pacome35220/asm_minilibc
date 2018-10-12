	global	memset:function
	section	.text

memset:
	mov	rax, rdi	; mov first parameter to rax (return value)
	cmp	rdx, 0		; if rdxx (third paramter) == 0, donc do anything ...
	jz	.EXIT		; ... just return the pointer

.LOOP:
	dec	rdx		; third parameter use as an index
	mov	BYTE[rdi + rdx], sil ; write 8-bit part of second parameter to memory
	cmp	rdx, 0		     ; check for end of loop
	jnz	.LOOP		     ; jnz => jump if not zero

.EXIT:
	ret
