section .text
		global _ft_read	; rdi, rsi, rdx

_ft_read:
		mov		rax, 0x02000003
		syscall
		jc exit_error
		mov		rax, r8
		ret

exit_error:
		mov		rax, -1
		ret
