global	inotify_init1:function
	section	.text

inotify_init1:
	mov	rax, 294
	syscall
	ret