section .text
		global _ft_strlen	; rdi

_ft_strlen:
		mov		rax, -1
while:
		inc		rax
		mov		cl, byte [rdi+rax]
		cmp		cl, 0
		jne		while
		ret
