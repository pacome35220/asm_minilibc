global	set_thread_area:function
	section	.text

set_thread_area:
	mov	rax, 205
	syscall
	ret