global	sethostname:function
	section	.text

sethostname:
	mov	rax, 170
	syscall
	ret