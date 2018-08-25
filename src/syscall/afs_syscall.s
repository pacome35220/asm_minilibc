global	afs_syscall:function
	section	.text

afs_syscall:
	mov	rax, 183
	syscall
	ret