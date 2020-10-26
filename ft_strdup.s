section .text
		global _ft_strdup				; rdi
		extern _ft_strlen
		extern _ft_strcpy
		extern _malloc
		extern ___error

_ft_strdup:
		call _ft_strlen
		push rdi
		mov rdi, rax
		inc rdi
		call _malloc
		jc exit_error
		mov rdi, rax
		pop rsi
		call _ft_strcpy
		mov rax, rdi
		ret

exit_error:
		push	r8					; save prev value
		mov		r8, rax
		call	___error
		mov		[rax], r8
		pop		r8					; return prev value to r8
		mov		rax, 0
		ret
