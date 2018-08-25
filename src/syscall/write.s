global	write:function
	section	.text

write:
	mov	rax, 1
	syscall
	ret