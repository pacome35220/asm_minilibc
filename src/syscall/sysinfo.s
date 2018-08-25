global	sysinfo:function
	section	.text

sysinfo:
	mov	rax, 99
	syscall
	ret