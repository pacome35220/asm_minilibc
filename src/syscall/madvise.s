global	madvise:function
	section	.text

madvise:
	mov	rax, 28
	syscall
	ret