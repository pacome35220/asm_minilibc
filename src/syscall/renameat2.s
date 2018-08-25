global	renameat2:function
	section	.text

renameat2:
	mov	rax, 316
	syscall
	ret