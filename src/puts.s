	global	puts:function
	section	.text

puts:
	xor	rdx, rdx	; rdx (index) will be strlen(s) => string length

.STRLEN:
	cmp	BYTE[rdi + rdx], 0	; cmp pointer + index with '\0'
	jz	.WRITE		; now, we know lenght, jmp to call write
	inc	rdx		; rdx => string length
	jmp	.STRLEN		; loop

.WRITE:
	;; write string

	mov	rsi, rdi	; rsi => pointer (string)
	mov	rdi, 1		; rdi => stdout
	mov	rax, 1		; write : syscall 1
	syscall

	mov	rbx, rdx	; rbx => tmp length

	;; write new line

	mov	rdi, 1		; rdi => stdout
	mov	rsi, newline	; rsi => read-only data
	mov	rdx, 1		; rdx => 1 byte
	mov	rax, 1		; write : syscall 1
	syscall
	add	rbx, rax	; rbx => new length
	mov	rax, rbx	; return written length
	ret

	section .rodata
newline:	db	10	; 10 ascii => \n
