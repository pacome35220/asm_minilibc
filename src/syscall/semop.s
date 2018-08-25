global	semop:function
	section	.text

semop:
	mov	rax, 65
	syscall
	ret