global	vfork:function
	section	.text

vfork:
	mov	rax, 58
	syscall
	ret