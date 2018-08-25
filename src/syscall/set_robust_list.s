global	set_robust_list:function
	section	.text

set_robust_list:
	mov	rax, 273
	syscall
	ret