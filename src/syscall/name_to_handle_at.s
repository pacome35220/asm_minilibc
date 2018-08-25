global	name_to_handle_at:function
	section	.text

name_to_handle_at:
	mov	rax, 303
	syscall
	ret