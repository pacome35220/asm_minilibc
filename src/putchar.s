	global	putchar:function
	section	.text

putchar:
	mov	r10, rsp	; save stack pointer to r10
	sub	rsp, 4		; space for buffer, 4 bytes (putchar parameter : int)

	;; move stack pointer backward/forward, to "allocate" stack memory
	;; sub	rsp, 4 => 1 bytes : char
	;; sub	rsp, 4 => 4 bytes : int
	;; sub	rsp, 8 => 8 bytes : pointer
	;; sub	rsp, 42 => 42 bytes : basic buffer of 42 bytes

	mov	[rsp], dil	; write parameter on stack (al is 8-bit aprt of rax)
	mov	rsi, rsp	; rsi, data pointer

	mov	rdi, 1		; rdi, fd = STDOUT_FILENO
	mov	rdx, 1		; rdx, count : 1 character

	mov	rax, 1		; write : syscall 1
	syscall			; call write
	cmp	rax, 1		; if write() == 1
	jz	.EXIT		;
	mov	rax, -1		; putchar() return EOF (-1) on error
	ret

.EXIT:
	mov	rax, [rsp]
	mov	rsp, r10	; restore stack pointer
	ret
