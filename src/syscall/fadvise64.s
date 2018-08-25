global	fadvise64:function
	section	.text

fadvise64:
	mov	rax, 221
	syscall
	ret