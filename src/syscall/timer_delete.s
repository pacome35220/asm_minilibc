global	timer_delete:function
	section	.text

timer_delete:
	mov	rax, 226
	syscall
	ret