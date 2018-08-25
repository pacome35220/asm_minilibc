global	personality:function
	section	.text

personality:
	mov	rax, 135
	syscall
	ret