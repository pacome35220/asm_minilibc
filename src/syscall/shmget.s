global	shmget:function
	section	.text

shmget:
	mov	rax, 29
	syscall
	ret