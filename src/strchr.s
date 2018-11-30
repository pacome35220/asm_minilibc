	global	strchr:function
	section	.text

	;; char *strchr(const char *s, int c)

strchr:	mov	rax, rdi	; mov first parameter to rax (return value)

.LOOP:
	cmp	BYTE[rax], sil	; cmp each char with 8-bit part of rsi (second parameter)
	jz	.FIND		; end of loop, found
	cmp	BYTE[rax], 0	; cmp each char with '\0'
	jz	.EXIT		; end of loop, return NULL => not found
	inc	rax		; inc index
	jmp	.LOOP		; loop

.EXIT:
	xor	rax, rax	; return NULL

.FIND:
	ret
