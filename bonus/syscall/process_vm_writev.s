global	process_vm_writev:function
	section	.text

process_vm_writev:
	mov	rax, 311
	syscall
	ret