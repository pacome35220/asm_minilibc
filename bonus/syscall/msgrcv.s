global	msgrcv:function
	section	.text

msgrcv:
	mov	rax, 70
	syscall
	ret