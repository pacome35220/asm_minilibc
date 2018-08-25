global	msgsnd:function
	section	.text

msgsnd:
	mov	rax, 69
	syscall
	ret