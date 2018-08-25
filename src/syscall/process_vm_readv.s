global	process_vm_readv:function
	section	.text

process_vm_readv:
	mov	rax, 310
	syscall
	ret