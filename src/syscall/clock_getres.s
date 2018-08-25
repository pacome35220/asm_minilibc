global	clock_getres:function
	section	.text

clock_getres:
	mov	rax, 229
	syscall
	ret