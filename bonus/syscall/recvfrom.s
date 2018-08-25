global	recvfrom:function
	section	.text

recvfrom:
	mov	rax, 45
	syscall
	ret