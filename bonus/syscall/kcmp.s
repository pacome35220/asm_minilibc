global	kcmp:function
	section	.text

kcmp:
	mov	rax, 312
	syscall
	ret