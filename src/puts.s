	global	puts:function
	section	.text

puts:
	xor	r8, r8	; r8 is byte written counter
	xor	rdx, rdx	; rdx (index) will be strlen(s) => string length

.STRLEN:
	cmp	BYTE[rdi + rdx], 0	; cmp pointer + index with '\0'
	jz	.WRITE		; now, we know lenght, jmp to call write
	inc	rdx		; rdx => string length
	jmp	.STRLEN		; loop

.WRITE:
	mov	rsi, rdi	; rsi => pointer (string)
	mov	rdi, 1		; rdi => stdout
	mov	rax, 1		; write : syscall 1
	syscall
	cmp	rax, rdx	; if write() != string length
	jnz	.ERROR		; return -1
	add	r8, rdx

	mov     r10, rsp	; save stack pointer to r10
	sub	rsp, 1		; space for buffer, 1 byte
	mov	BYTE[rsp], 10	; write '\n' (10 ascii) in buffer
	mov	rsi, rsp	; buffer => rsi
	mov	rdx, 1		; rdx => 1 byte
	mov	rax, 1		; write : syscall 1
	syscall
	mov	rsp, r10
	add	rax, r8
	ret

.ERROR:
	mov	rax, -1		; puts() return EOF (-1) on error
	mov     rsp, r10        ; restore stack pointer
	ret
