global	shmdt:function
	section	.text

shmdt:
	mov	rax, 67
	syscall
	ret