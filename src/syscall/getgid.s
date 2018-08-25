global	getgid:function
	section	.text

getgid:
	mov	rax, 104
	syscall
	ret