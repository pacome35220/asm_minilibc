global	syslog:function
	section	.text

syslog:
	mov	rax, 103
	syscall
	ret