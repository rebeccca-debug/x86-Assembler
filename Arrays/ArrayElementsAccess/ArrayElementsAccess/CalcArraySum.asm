.model flat,c
.code

CalcArraySumASM proc
			push ebp
			mov ebp,esp

			mov edx,[ebp+8]				;edx='x'
			mov ecx,[ebp+12]			;ecx='n'
			xor eax,eax					;eax=sum

			cmp ecx,0
			jle InvalidCount

@@:			add eax,[edx]				; add next element to sum
			add edx, 4					; set pointer to next element
			dec ecx						; counter--
			jnz @B						; jump backward to the next @@ label if not equal to zero

InvalidCount
		pop ebp
		ret

CalcArraySumASM		endp
	end