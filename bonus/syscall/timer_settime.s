global	timer_settime:function
	section	.text

timer_settime:
	mov	rax, 223
	syscall
	ret