global	fstatfs:function
	section	.text

fstatfs:
	mov	rax, 138
	syscall
	ret