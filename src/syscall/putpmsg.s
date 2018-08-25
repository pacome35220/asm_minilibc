global	putpmsg:function
	section	.text

putpmsg:
	mov	rax, 182
	syscall
	ret