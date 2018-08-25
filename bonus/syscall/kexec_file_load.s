global	kexec_file_load:function
	section	.text

kexec_file_load:
	mov	rax, 320
	syscall
	ret