global	dup:function
	section	.text

dup:
	mov	rax, 32
	syscall
	ret