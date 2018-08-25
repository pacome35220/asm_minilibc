global	alarm:function
	section	.text

alarm:
	mov	rax, 37
	syscall
	ret