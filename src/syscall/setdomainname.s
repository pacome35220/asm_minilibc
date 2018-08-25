global	setdomainname:function
	section	.text

setdomainname:
	mov	rax, 171
	syscall
	ret