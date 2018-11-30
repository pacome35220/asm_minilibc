	global	strlen:function
	section	.text

	;; size_t strlen(const char *s)

strlen:	xor	rax, rax	; set index to 0

.LOOP:
	cmp	BYTE[rdi + rax], 0 ; cmp pointer + index with '\0'
	jz	.EXIT		   ; end of loop
	inc	rax		   ; inc index
	jmp	.LOOP		   ; loop

.EXIT:
	ret
