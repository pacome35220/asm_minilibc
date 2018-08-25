global	get_mempolicy:function
	section	.text

get_mempolicy:
	mov	rax, 239
	syscall
	ret