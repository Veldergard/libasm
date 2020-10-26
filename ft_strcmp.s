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
		mov		rax, [rdi+rcx]
		sub		rax, [rsi+rcx]
		pop		r8
		ret
