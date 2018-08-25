global	munlock:function
	section	.text

munlock:
	mov	rax, 150
	syscall
	ret