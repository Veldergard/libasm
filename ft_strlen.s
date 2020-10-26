section .text
		global _ft_strlen	; rdi

_ft_strlen:
		mov		rax, -1
while:
		inc		rax
		cmp		byte [rdi+rax], 0
		jne		while					; if not end of string
		ret
