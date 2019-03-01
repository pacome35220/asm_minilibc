	global	memmove:function
	section	.text

	;; void *memmove(void *dest, const void *src, size_t n)

memmove:
	cmp	rsi, rdi	; if (src < dest)
	jl	.MEMCPY		; jump to basic memcpy
	mov	rax, rdi	; rax = dest
	mov	rcx, rdx	; rcx = n
	mov	rdx, rsi	; rdx = src
	cld			; clear direction flag
	rep	movsb		; magic
	mov	rsi, rdx	; restore src
	mov	rdi, rax	; restore dest
	ret			; return dest

.MEMCPY:
	mov	rax, rdi	; return a pointer to dest (rdi)
	cmp	rdx, 0		; if (n == 0)
	jz	.EXIT		; don't try to copy anything

.LOOP:				; memcpy loop
	dec	rdx		; third parameter use as index
	mov	r8b, BYTE[rsi + rdx] ; r8b = src[n]
	mov	BYTE[rdi + rdx], r8b ; dest[n] = r8b => copy
	cmp	rdx, 0		     ; if (n != 0)
	jnz	.LOOP		     ; loop

.EXIT:
	ret
