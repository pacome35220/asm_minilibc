global	inotify_add_watch:function
	section	.text

inotify_add_watch:
	mov	rax, 254
	syscall
	ret