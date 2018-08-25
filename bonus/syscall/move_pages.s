global	move_pages:function
	section	.text

move_pages:
	mov	rax, 279
	syscall
	ret