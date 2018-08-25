global	get_robust_list:function
	section	.text

get_robust_list:
	mov	rax, 274
	syscall
	ret