global	prlimit64:function
	section	.text

prlimit64:
	mov	rax, 302
	syscall
	ret