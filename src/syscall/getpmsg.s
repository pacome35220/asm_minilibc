global	getpmsg:function
	section	.text

getpmsg:
	mov	rax, 181
	syscall
	ret