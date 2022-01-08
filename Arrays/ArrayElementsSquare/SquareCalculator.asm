			.model flat,c
			.code

CalcArraySquaresASM    proc
				push ebp
				mov ebp,esp
				push ebx
				push esi
				push edi

				;Load arguments

				mov edi,[ebp+8]
				mov esi,[ebp+12]
				mov ecx,[ebp+16]

				xor eax,eax						; eax = sum of 'y' array
				cmp ecx,0
				jle EmptyArray
				shl ecx, 2						; ecx = size of array in bytes
				xor ebx,ebx						; ebx = array element offset

@@:				mov edx,[esi+ebx]				; load next x[i]
				imul edx,edx
				mov [edi+ebx],edx				; save result to y[i]
				add eax,edx
				add ebx,4						; update array element offset
				cmp ebx,ecx
				jl @B							; jump if not finished

EmptyArray:
				pop edi
				pop esi
				pop ebx
				pop ebp
				ret

CalcArraySquaresASM		endp
				end