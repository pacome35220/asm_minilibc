global	clock_settime:function
	section	.text

clock_settime:
	mov	rax, 227
	syscall
	ret