global	capset:function
	section	.text

capset:
	mov	rax, 126
	syscall
	ret