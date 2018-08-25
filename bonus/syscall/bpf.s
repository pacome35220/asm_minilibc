global	bpf:function
	section	.text

bpf:
	mov	rax, 321
	syscall
	ret