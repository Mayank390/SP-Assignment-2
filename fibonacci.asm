section _data
	n equ 20
section .text
	global _start
_start:
	mov rdi, n
	call fibonacci
	mov rax,60
	mov rdi,0
	syscall

fibonacci:
	cmp rdi,0
	jle fibonacci_0
	cmp rdi, 1
	je fibonacci_1

	mov rax,0
	mov rbx,1

loop_continue:
	add rax, rbx
	mov rdx, rbx
	mov rbx, rax
	mov rax, rdx

	dec rdi
	jnz loop_continue

fibonacci_0:
	ret
fibonacci_1:
	mov rax, 1
	ret

