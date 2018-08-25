global	setitimer:function
	section	.text

setitimer:
	mov	rax, 38
	syscall
	ret