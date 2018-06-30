	global	rindex:function
	section	.text

rindex:
	mov	rax, rdi

.STRLEN:
	cmp	BYTE[rax], 0
	jz	.START
	inc	rax
	jmp	.STRLEN

.START:
	dec	rax		; rax = strlen() -> use as index so len - 1

.LOOP:
	cmp	BYTE[rax], 0
	jz	.EXIT
	cmp	BYTE[rax], sil
	jz	.FIND
	dec	rax
	jmp	.LOOP

.EXIT:
	xor	rax, rax

.FIND:
	ret
