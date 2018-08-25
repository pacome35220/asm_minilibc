global	stat:function
	section	.text

stat:
	mov	rax, 4
	syscall
	ret