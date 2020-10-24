section .text
		global _ft_write	; rdi, rsi, rdx

_ft_write:
		mov		rax, 0x02000004
		syscall
		jc exit_error
		jmp exit

exit_error:
		mov		rax, -1
		ret

exit:
		mov		rax, r8
		ret
