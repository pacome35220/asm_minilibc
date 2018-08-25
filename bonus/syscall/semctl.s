global	semctl:function
	section	.text

semctl:
	mov	rax, 66
	syscall
	ret