global	_sysctl:function
	section	.text

_sysctl:
	mov	rax, 156
	syscall
	ret