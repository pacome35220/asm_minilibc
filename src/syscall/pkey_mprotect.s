global	pkey_mprotect:function
	section	.text

pkey_mprotect:
	mov	rax, 329
	syscall
	ret