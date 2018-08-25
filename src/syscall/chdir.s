global	chdir:function
	section	.text

chdir:
	mov	rax, 80
	syscall
	ret