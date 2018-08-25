global	clock_adjtime:function
	section	.text

clock_adjtime:
	mov	rax, 305
	syscall
	ret