global	getrandom:function
	section	.text

getrandom:
	mov	rax, 318
	syscall
	ret