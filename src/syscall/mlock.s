global	mlock:function
	section	.text

mlock:
	mov	rax, 149
	syscall
	ret