global	symlink:function
	section	.text

symlink:
	mov	rax, 88
	syscall
	ret