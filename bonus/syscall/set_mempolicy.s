global	set_mempolicy:function
	section	.text

set_mempolicy:
	mov	rax, 238
	syscall
	ret