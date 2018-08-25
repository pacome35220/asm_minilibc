global	sendmsg:function
	section	.text

sendmsg:
	mov	rax, 46
	syscall
	ret