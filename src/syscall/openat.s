global	openat:function
	section	.text

openat:
	mov	rax, 257
	syscall
	ret