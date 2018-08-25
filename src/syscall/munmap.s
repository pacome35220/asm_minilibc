global	munmap:function
	section	.text

munmap:
	mov	rax, 11
	syscall
	ret