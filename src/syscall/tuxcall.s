global	tuxcall:function
	section	.text

tuxcall:
	mov	rax, 184
	syscall
	ret