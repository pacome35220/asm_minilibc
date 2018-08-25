global	mmap:function
	section	.text

mmap:
	mov	rax, 9
	syscall
	ret