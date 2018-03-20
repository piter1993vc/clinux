	.file	"fork.c"
	.section	.rodata
.LC0:
	.string	"Before fork"
.LC1:
	.string	"This is a child process"
.LC2:
	.string	"child process: %d\n"
.LC3:
	.string	"Thi is the parrent process"
.LC4:
	.string	"parent process:%d\n"
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
	subq	$16, %rsp
	movl	$0, -12(%rbp)
	movl	$0, -8(%rbp)
	movl	$.LC0, %edi
	call	puts
	movl	$5, %edi
	call	sleep
	call	fork
	movl	%eax, -4(%rbp)
	cmpl	$0, -4(%rbp)
	jne	.L2
	movl	$.LC1, %edi
	call	puts
	jmp	.L3
.L4:
	movl	-12(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC2, %edi
	movl	$0, %eax
	call	printf
	movl	$1, %edi
	call	sleep
	addl	$1, -12(%rbp)
.L3:
	cmpl	$9, -12(%rbp)
	jle	.L4
	jmp	.L5
.L2:
	movl	$.LC3, %edi
	call	puts
	jmp	.L6
.L7:
	movl	-8(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC4, %edi
	movl	$0, %eax
	call	printf
	movl	$1, %edi
	call	sleep
	addl	$1, -8(%rbp)
.L6:
	cmpl	$19, -8(%rbp)
	jle	.L7
.L5:
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.9) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
