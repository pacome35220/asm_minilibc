global	umount2:function
	section	.text

umount2:
	mov	rax, 166
	syscall
	ret