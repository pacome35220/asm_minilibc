	global	strstr:function
	section	.text

	;; char *strstr(const char *haystack, const char *needle)

strstr:
	mov	rax, rdi
	cmp	BYTE[rax], 0	; if (*s1 == '\0') && ... => handle strstr("", "")
	jnz	.LOOP
	cmp	BYTE[rsi], 0	; ... (*s2 == '\0') => return s1
	jnz	.LOOP
	ret

.LOOP:
	cmp	BYTE[rax], 0
	jz	.EXIT
	xor	rcx, rcx	; rcx = 0 -> rcx is index

.CMP:
	mov	r8b, BYTE[rax]
	cmp	BYTE[rsi + rcx], r8b ; while (*s1 == s2[rcx] && ...
	jnz	.FINAL
	cmp	r8b, 0		; ... *s != '\0')
	jz	.FINAL
	inc	rax
	inc	rcx
	jmp	.CMP

.FINAL:
	cmp	BYTE[rsi + rcx], 0
	jz	.FIND
	inc	rax
	jmp	.LOOP

.EXIT:
	xor	rax, rax
	ret

.FIND:
	sub	rax, rcx	; rax -> end of string after matchig, so rax -= rcx
	ret
