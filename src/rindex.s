	global	rindex:function
	section	.text

rindex:
	mov	rax, rdi	; mov first parameter to rax (return value)

	;; rindex is like strchr, but start search at the end of the string
	;; so we use strlen to go until null-terminated byte

.STRLEN:
	cmp	BYTE[rax], 0	; cmp each char with 8-bit part of rsi (second parameter)
	jz	.START		; jump when end of string is reached
	inc	rax		; inc index
	jmp	.STRLEN		; strlen loop

.START:
	dec	rax		; rax == strlen(), so we use rax as index, so len - 1

.LOOP:
	cmp	BYTE[rax], 0	; cmp each char with '\0'
	jz	.EXIT		; end of loop, return NULL => not found
	cmp	BYTE[rax], sil:	; cmp each char with 8-bit part of rsi (second parameter)
	jz	.FIND		; end  of loop, found
	dec	rax		; dec index, because loop is reversed
	jmp	.LOOP		; loop

.EXIT:
	xor	rax, rax	; return NULL

.FIND:
	ret
