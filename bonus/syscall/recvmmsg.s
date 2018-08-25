global	recvmmsg:function
	section	.text

recvmmsg:
	mov	rax, 299
	syscall
	ret