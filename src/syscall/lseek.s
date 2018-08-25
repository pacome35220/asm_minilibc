global	lseek:function
	section	.text

lseek:
	mov	rax, 8
	syscall
	ret