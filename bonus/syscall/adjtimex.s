global	adjtimex:function
	section	.text

adjtimex:
	mov	rax, 159
	syscall
	ret