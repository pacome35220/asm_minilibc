global	swapoff:function
	section	.text

swapoff:
	mov	rax, 168
	syscall
	ret