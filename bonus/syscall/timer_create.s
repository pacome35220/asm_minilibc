global	timer_create:function
	section	.text

timer_create:
	mov	rax, 222
	syscall
	ret