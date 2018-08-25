global	restart_syscall:function
	section	.text

restart_syscall:
	mov	rax, 219
	syscall
	ret