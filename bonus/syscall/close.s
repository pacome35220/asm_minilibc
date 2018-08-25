global	close:function
	section	.text

close:
	mov	rax, 3
	syscall
	ret