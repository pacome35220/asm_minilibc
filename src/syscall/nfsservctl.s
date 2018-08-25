global	nfsservctl:function
	section	.text

nfsservctl:
	mov	rax, 180
	syscall
	ret