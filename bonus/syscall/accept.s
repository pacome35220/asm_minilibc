global	accept:function
	section	.text

accept:
	mov	rax, 43
	syscall
	ret