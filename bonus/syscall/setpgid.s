global	setpgid:function
	section	.text

setpgid:
	mov	rax, 109
	syscall
	ret