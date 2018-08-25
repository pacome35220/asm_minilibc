global	shmctl:function
	section	.text

shmctl:
	mov	rax, 31
	syscall
	ret