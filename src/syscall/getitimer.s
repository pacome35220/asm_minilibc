global	getitimer:function
	section	.text

getitimer:
	mov	rax, 36
	syscall
	ret