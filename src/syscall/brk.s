global	brk:function
	section	.text

brk:
	mov	rax, 12
	syscall
	ret