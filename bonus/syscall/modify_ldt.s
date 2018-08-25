global	modify_ldt:function
	section	.text

modify_ldt:
	mov	rax, 154
	syscall
	ret