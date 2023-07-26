section .data
section .text
	global _start

_start:
	mov rdi, 10
	call int_to_ascii

	;exit system call
	mov rax,60
	mov rdi, 0
	syscall
int_to_ascii:
	mov rax, rdi
	add rax, '0'
	ret
