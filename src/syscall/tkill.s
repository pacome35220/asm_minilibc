global	tkill:function
	section	.text

tkill:
	mov	rax, 200
	syscall
	ret