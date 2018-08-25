global	getegid:function
	section	.text

getegid:
	mov	rax, 108
	syscall
	ret