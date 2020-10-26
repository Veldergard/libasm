section .text
		global _ft_read				; rdi, rsi, rdx
		extern ___error

_ft_read:
		mov		rax, 0x02000003
		syscall
		jc		exit_error
		ret

exit_error:
		push	r8					; save prev value
		mov		r8, rax
		call	___error
		mov		[rax], r8
		pop		r8					; return prev value to r8
		mov		rax, -1
		ret
