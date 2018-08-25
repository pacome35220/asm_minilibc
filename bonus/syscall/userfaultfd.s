global	userfaultfd:function
	section	.text

userfaultfd:
	mov	rax, 323
	syscall
	ret