global	acct:function
	section	.text

acct:
	mov	rax, 163
	syscall
	ret