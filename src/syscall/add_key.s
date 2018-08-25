global	add_key:function
	section	.text

add_key:
	mov	rax, 248
	syscall
	ret