global	copy_file_range:function
	section	.text

copy_file_range:
	mov	rax, 326
	syscall
	ret