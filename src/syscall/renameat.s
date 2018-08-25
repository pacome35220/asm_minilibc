global	renameat:function
	section	.text

renameat:
	mov	rax, 264
	syscall
	ret