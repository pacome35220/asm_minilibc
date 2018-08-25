global	flock:function
	section	.text

flock:
	mov	rax, 73
	syscall
	ret