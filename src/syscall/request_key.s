global	request_key:function
	section	.text

request_key:
	mov	rax, 249
	syscall
	ret