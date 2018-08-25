global	lookup_dcookie:function
	section	.text

lookup_dcookie:
	mov	rax, 212
	syscall
	ret