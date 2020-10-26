section .text
		global _ft_strcmp				; rdi, rsi

_ft_strcmp:
		push	r8
		mov		rcx, -1
while:
		inc		rcx
		mov		r8b, [rdi+rcx]
		cmp		r8b, [rsi+rcx]
		jne		exit
		cmp		byte [rdi+rcx], 0
		jne		while					; if not end of string
exit:
		mov		rax, 0
		mov		al, [rdi+rcx]
		mov		r8, 0
		mov		r8b, [rsi+rcx]
		sub		rax, r8
		pop		r8
		ret
