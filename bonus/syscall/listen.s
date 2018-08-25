global	listen:function
	section	.text

listen:
	mov	rax, 50
	syscall
	ret