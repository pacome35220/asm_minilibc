global	seccomp:function
	section	.text

seccomp:
	mov	rax, 317
	syscall
	ret