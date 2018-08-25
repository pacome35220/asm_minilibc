global	migrate_pages:function
	section	.text

migrate_pages:
	mov	rax, 256
	syscall
	ret