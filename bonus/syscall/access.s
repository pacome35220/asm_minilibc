global	access:function
	section	.text

access:
	mov	rax, 21
	syscall
	ret