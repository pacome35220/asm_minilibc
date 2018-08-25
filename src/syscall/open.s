global	open:function
	section	.text

open:
	mov	rax, 2
	syscall
	ret