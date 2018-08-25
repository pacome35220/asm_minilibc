global	syncfs:function
	section	.text

syncfs:
	mov	rax, 306
	syscall
	ret