global	timer_gettime:function
	section	.text

timer_gettime:
	mov	rax, 224
	syscall
	ret