global	fremovexattr:function
	section	.text

fremovexattr:
	mov	rax, 199
	syscall
	ret