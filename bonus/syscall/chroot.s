global	chroot:function
	section	.text

chroot:
	mov	rax, 161
	syscall
	ret