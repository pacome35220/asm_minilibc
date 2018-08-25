global	sendto:function
	section	.text

sendto:
	mov	rax, 44
	syscall
	ret