section .text
		global _ft_strcpy				; rdi, rsi

_ft_strcpy:
		push	rdi
		push	r8
		mov		rcx, -1
while:
		inc		rcx
		mov		r8b, byte [rsi+rcx]
		mov		byte [rdi+rcx], r8b
		cmp		byte [rdi+rcx], 0
		jne		while					; if not end of string
exit:
		pop		r8
		pop		rax
		ret
