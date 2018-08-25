global	sync_file_range:function
	section	.text

sync_file_range:
	mov	rax, 277
	syscall
	ret