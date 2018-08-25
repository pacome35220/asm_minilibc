global	get_thread_area:function
	section	.text

get_thread_area:
	mov	rax, 211
	syscall
	ret