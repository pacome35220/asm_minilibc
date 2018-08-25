global	getpriority:function
	section	.text

getpriority:
	mov	rax, 140
	syscall
	ret