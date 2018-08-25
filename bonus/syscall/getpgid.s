global	getpgid:function
	section	.text

getpgid:
	mov	rax, 121
	syscall
	ret