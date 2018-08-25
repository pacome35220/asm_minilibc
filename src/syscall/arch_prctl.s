global	arch_prctl:function
	section	.text

arch_prctl:
	mov	rax, 158
	syscall
	ret