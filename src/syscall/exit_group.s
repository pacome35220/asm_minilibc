global	exit_group:function
	section	.text

exit_group:
	mov	rax, 231
	syscall
	ret