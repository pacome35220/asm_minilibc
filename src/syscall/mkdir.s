global	mkdir:function
	section	.text

mkdir:
	mov	rax, 83
	syscall
	ret