global	getgroups:function
	section	.text

getgroups:
	mov	rax, 115
	syscall
	ret