global	shmat:function
	section	.text

shmat:
	mov	rax, 30
	syscall
	ret