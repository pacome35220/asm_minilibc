global	memfd_create:function
	section	.text

memfd_create:
	mov	rax, 319
	syscall
	ret