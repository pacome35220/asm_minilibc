global	clock_nanosleep:function
	section	.text

clock_nanosleep:
	mov	rax, 230
	syscall
	ret