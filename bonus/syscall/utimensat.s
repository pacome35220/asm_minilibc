global	utimensat:function
	section	.text

utimensat:
	mov	rax, 280
	syscall
	ret