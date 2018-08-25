global	swapon:function
	section	.text

swapon:
	mov	rax, 167
	syscall
	ret