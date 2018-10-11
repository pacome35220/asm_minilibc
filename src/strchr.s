	global	strchr:function
	section	.text

strchr:	mov	rax, rdi

.LOOP:
	cmp	BYTE[rax], sil
	jz	.FIND
	cmp	BYTE[rax], 0
	jz	.EXIT
	inc	rax
	jmp	.LOOP

.EXIT:
	xor	rax, rax

.FIND:
	ret
