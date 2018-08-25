global	mprotect:function
	section	.text

mprotect:
	mov	rax, 10
	syscall
	ret