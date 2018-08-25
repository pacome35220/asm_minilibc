global	gettid:function
	section	.text

gettid:
	mov	rax, 186
	syscall
	ret