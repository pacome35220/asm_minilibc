global	set_tid_address:function
	section	.text

set_tid_address:
	mov	rax, 218
	syscall
	ret