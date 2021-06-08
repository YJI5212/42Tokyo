global _ft_strcpy

section .text
	_ft_strcpy:
		xor rax, rax
		cmp rsi, 0
		je .end
	.loop:
		mov cl, byte[rsi+rax]
		mov byte[rdi+rax], cl
		cmp cl, 0
		je .end
		inc rax
		jmp .loop
	.end:
		mov rax, rdi
		ret
