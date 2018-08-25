global	accept4:function
	section	.text

accept4:
	mov	rax, 288
	syscall
	ret