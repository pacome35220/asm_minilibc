global	timer_getoverrun:function
	section	.text

timer_getoverrun:
	mov	rax, 225
	syscall
	ret