global	get_kernel_syms:function
	section	.text

get_kernel_syms:
	mov	rax, 177
	syscall
	ret