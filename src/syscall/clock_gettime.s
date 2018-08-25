global	clock_gettime:function
	section	.text

clock_gettime:
	mov	rax, 228
	syscall
	ret