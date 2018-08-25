global	read:function
	section	.text

read:
	mov	rax, 0
	syscall
	ret