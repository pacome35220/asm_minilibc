global	pause:function
	section	.text

pause:
	mov	rax, 34
	syscall
	ret