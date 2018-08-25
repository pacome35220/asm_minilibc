global	sysfs:function
	section	.text

sysfs:
	mov	rax, 139
	syscall
	ret