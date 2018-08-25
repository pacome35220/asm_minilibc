global	getpgrp:function
	section	.text

getpgrp:
	mov	rax, 111
	syscall
	ret