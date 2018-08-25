global	settimeofday:function
	section	.text

settimeofday:
	mov	rax, 164
	syscall
	ret