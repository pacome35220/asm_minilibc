global	fchownat:function
	section	.text

fchownat:
	mov	rax, 260
	syscall
	ret