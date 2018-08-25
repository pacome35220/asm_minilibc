global	utime:function
	section	.text

utime:
	mov	rax, 132
	syscall
	ret