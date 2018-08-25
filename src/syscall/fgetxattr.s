global	fgetxattr:function
	section	.text

fgetxattr:
	mov	rax, 193
	syscall
	ret