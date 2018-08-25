global	remap_file_pages:function
	section	.text

remap_file_pages:
	mov	rax, 216
	syscall
	ret