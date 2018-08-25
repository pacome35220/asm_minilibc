global	socket:function
	section	.text

socket:
	mov	rax, 41
	syscall
	ret