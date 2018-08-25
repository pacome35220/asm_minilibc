global	kill:function
	section	.text

kill:
	mov	rax, 62
	syscall
	ret