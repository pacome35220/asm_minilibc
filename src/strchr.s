	global	strchr:function
	section	.text

strchr:	mov	rax, rdi

.LOOP:
	cmp	BYTE[rax], 0
	jz	.EXIT
	cmp	BYTE[rax], sil
	jz	.FIND
	inc	rax
	jmp	.LOOP

.EXIT:
	xor	rax, rax

.FIND:
	ret
