	global	my_sort_int_array:function
	section	.text

my_sort_int_array:
	cmp	esi, 2		; if (size < 2)
	jl	.EXIT		; don't try to sort anything, jump if lower
	xor	r8d, r8d	; r8d use a index
	dec	rsi		; rsi is array's size, size - 1 == last index

.LOOP:
	cmp	r8d, esi	; if (index < size)
	jz	.EXIT		; end of array => exit
	mov	ecx, r8d	; ecx tmp index
	mov	edx, DWORD[rdi + rcx * 4]     ; edx = arr[i * sizeof(int)]
	mov	eax, DWORD[rdi + rcx * 4 + 4] ; eax = arr[i * sizeof(int) + 1]

	cmp	eax, edx	; if (arr[i + 1] >= arr[i])
	jge	.ADD		; continue loop, jump if greater or equal

	;;  else, swap
	mov	DWORD[rdi + rcx * 4], eax ; arr[i] = rax
	inc	rcx			  ; i++
	mov	DWORD[rdi + rcx * 4], edx ; arr[i] = rdx

	xor	r8d, r8d		  ; reset index to 0
	jmp	.LOOP

.ADD:
	inc	r8d		; inc index
	jmp	.LOOP		; loop

.EXIT:
	ret
