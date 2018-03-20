	.file	"readwrite.c"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
.L2:
	leaq	-32(%rbp), %rax
	movl	$20, %edx
	movq	%rax, %rsi
	movl	$0, %edi
	call	read
	movl	%eax, -36(%rbp)
	leaq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	puts
	jmp	.L2
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.9) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
