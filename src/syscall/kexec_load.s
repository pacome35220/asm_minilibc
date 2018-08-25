global	kexec_load:function
	section	.text

kexec_load:
	mov	rax, 246
	syscall
	ret