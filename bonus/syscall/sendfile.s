global	sendfile:function
	section	.text

sendfile:
	mov	rax, 40
	syscall
	ret