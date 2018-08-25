global	semtimedop:function
	section	.text

semtimedop:
	mov	rax, 220
	syscall
	ret