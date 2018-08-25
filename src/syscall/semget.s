global	semget:function
	section	.text

semget:
	mov	rax, 64
	syscall
	ret