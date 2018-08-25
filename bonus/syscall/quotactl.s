global	quotactl:function
	section	.text

quotactl:
	mov	rax, 179
	syscall
	ret