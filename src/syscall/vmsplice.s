global	vmsplice:function
	section	.text

vmsplice:
	mov	rax, 278
	syscall
	ret