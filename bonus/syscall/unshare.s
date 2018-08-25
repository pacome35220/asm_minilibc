global	unshare:function
	section	.text

unshare:
	mov	rax, 272
	syscall
	ret