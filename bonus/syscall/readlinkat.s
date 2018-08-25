global	readlinkat:function
	section	.text

readlinkat:
	mov	rax, 267
	syscall
	ret