global	gettimeofday:function
	section	.text

gettimeofday:
	mov	rax, 96
	syscall
	ret