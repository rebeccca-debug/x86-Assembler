						.model flat,c
						.const
AbsMask qword 7fffffffffffffffh, 7fffffffffffffffh
						.code

AVX_fp_Arith	proc
				push ebp
				mov ebp,esp

;Load arguments
				mov eax,[ebp+24]				;eax = pointer to results array
				vmovsd xmm0,real8 ptr [ebp+8]	;xmm0 = a
				vmovsd xmm1,real8 ptr [ebp+16]	;xmm1 = b

			;Addition
				vaddsd xmm2,xmm0,xmm1			;xmm1=a+b
			;Subtraction
				vsubsd xmm3,xmm0,xmm1			;xmm1=a-b
			;Multiplication
				vmulsd xmm4,xmm0,xmm1			;xmm1=a*b
			;Division
				vdivsd xmm5,xmm0,xmm1			;xmm1=a/b
		;Save results
				vmovsd real8 ptr [ebp+0],xmm2	;save a+b
				vmovsd real8 ptr [ebp+8],xmm3	;save a-b
				vmovsd real8 ptr [ebp+16],xmm4	;save a*b
				vmovsd real8 ptr [ebp+24],xmm5	;save a/b

		;Min(a,b)
				vminsd xmm2,xmm0,xmm1			;xmm2 = min(a,b)
		;Max(a,b)
				vmaxsd xmm3,xmm0,xmm1			;xmm3 = max(a,b)
		;sqrt(a)
				vsqrtsd xmm4,xmm0,xmm0			;xmm4 = sqrt(a)
		;fabs(b)
				vandpd xmm5,xmm1,xmmword ptr[AbsMask]		;xmm5 = fabs(b)

		;Save results
				vmovsd real8 ptr [ebp+32],xmm2	;save min(a,b)
				vmovsd real8 ptr [ebp+40],xmm3	;save max(a,b)
				vmovsd real8 ptr [ebp+48],xmm4	;save sqrt(a)
				vmovsd real8 ptr [ebp+56],xmm5	;save fabs(b)

				pop ebp
				ret

AVX_fp_Arith	endp
			end