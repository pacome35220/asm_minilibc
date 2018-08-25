global	munlockall:function
	section	.text

munlockall:
	mov	rax, 152
	syscall
	ret