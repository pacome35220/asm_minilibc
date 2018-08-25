global	rt_tgsigqueueinfo:function
	section	.text

rt_tgsigqueueinfo:
	mov	rax, 297
	syscall
	ret