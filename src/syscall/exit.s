global	exit:function
	section	.text

exit:
	mov	rax, 60
	syscall
	ret