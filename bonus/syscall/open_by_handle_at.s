global	open_by_handle_at:function
	section	.text

open_by_handle_at:
	mov	rax, 304
	syscall
	ret