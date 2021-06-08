global _ft_strdup

extern _ft_strlen, _ft_strcpy, _malloc, ___error

section .text
	_ft_strdup:
		push rdi
		call _ft_strlen
		mov rdi, rax
		call _malloc
		jc .error
		mov rdi, rax
		pop rsi
		call _ft_strcpy
		ret
	.error:
		mov rbx, rax
		call ___error
		mov [rax], rbx
		ret
