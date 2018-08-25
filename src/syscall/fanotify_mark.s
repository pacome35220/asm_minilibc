global	fanotify_mark:function
	section	.text

fanotify_mark:
	mov	rax, 301
	syscall
	ret