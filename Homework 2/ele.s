ele:
	movl	$7, %eax // set result = 7
    subq	%rdi, %rax // i in %rdi; %rax = 7 - i
	leaq	(%rax,%rax,4), %rax // %rax = 5(7 - i)
    subq	%rsi, %rax // j in %rsi; %rax = 5(7 - i) - j
	leaq	7(%rdx,%rax,8), %rax // %rax = (k + 8 * (5(7 - i) - j)) + 7
	movq	A(,%rax,8), %rax // retrieve M[x_A +  8(8(5(7 - i) - j)) + k + 7])
	ret

