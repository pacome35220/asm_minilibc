global	wait4:function
	section	.text

wait4:
	mov	rax, 61
	syscall
	ret