global	vserver:function
	section	.text

vserver:
	mov	rax, 236
	syscall
	ret