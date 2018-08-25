global	reboot:function
	section	.text

reboot:
	mov	rax, 169
	syscall
	ret