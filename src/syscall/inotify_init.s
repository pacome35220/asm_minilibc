global	inotify_init:function
	section	.text

inotify_init:
	mov	rax, 253
	syscall
	ret