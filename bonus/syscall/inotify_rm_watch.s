global	inotify_rm_watch:function
	section	.text

inotify_rm_watch:
	mov	rax, 255
	syscall
	ret