global	fanotify_init:function
	section	.text

fanotify_init:
	mov	rax, 300
	syscall
	ret