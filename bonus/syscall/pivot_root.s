global	pivot_root:function
	section	.text

pivot_root:
	mov	rax, 155
	syscall
	ret