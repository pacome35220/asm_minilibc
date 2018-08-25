global	sendmmsg:function
	section	.text

sendmmsg:
	mov	rax, 307
	syscall
	ret