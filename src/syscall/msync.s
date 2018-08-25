global	msync:function
	section	.text

msync:
	mov	rax, 26
	syscall
	ret