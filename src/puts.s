	global	puts:function
	section .rodata

	;; int puts(const char *s)

NEWLINE:	db	10	; 10 ascii => \n

	section	.text

puts:
	xor	rdx, rdx	; rdx (index) will be strlen(s) => string length

.STRLEN:
	cmp	BYTE[rdi + rdx], 0	; cmp pointer + index with '\0'
	jz	.WRITE		; now, we know lenght, jmp to call write
	inc	rdx		; rdx => string length
	jmp	.STRLEN		; loop

.WRITE:
	mov	rbx, rdx	; rbx => tmp length
	cmp	rdx, 0		; if (*s == '\0')
	jz	.WRITE_NEWLINE	; just display newline

	;; write string

	mov	rsi, rdi	; rsi => pointer (string)
	mov	rdi, 1		; rdi => stdout
	mov	rax, 1		; write : syscall 1
	syscall


	;; write new line

.WRITE_NEWLINE:

	mov	rdi, 1		; rdi => stdout
	mov	rsi, NEWLINE	; rsi => read-only data
	mov	rdx, 1		; rdx => 1 byte
	mov	rax, 1		; write : syscall 1
	syscall

	add	rax, rbx	; add old length (rbx) => return written length
	ret
