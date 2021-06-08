global _ft_strcmp

section .text
	_ft_strcmp:
		xor rax, rax
		xor rbx, rbx
		mov rcx, -1
	.loop:
		inc rcx
		mov al, byte[rdi+rcx]
		mov bl, byte[rsi+rcx]
		cmp al, 0
		je .end
		cmp bl, 0
		je .end
		cmp al, bl
		je .loop
	.end:
		sub rax, rbx
		ret


