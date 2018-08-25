global	vhangup:function
	section	.text

vhangup:
	mov	rax, 153
	syscall
	ret