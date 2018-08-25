global	recvmsg:function
	section	.text

recvmsg:
	mov	rax, 47
	syscall
	ret