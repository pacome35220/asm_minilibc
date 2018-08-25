global	readahead:function
	section	.text

readahead:
	mov	rax, 187
	syscall
	ret