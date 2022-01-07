				.model flat,c
				.code

MmxShifter		proc
			push ebp
			mov ebp,esp

			xor eax,eax
			mov edx,[ebp+16]
			cmp edx,ShiftOpTableCount					;compare to table count
			jae BadShiftOp


			mov eax,1										;load 'a'
			movq mm0,[ebp+8]								;load 'b'
			movd mm1,dword ptr [ebp+20]
			jmp [ShiftOpTable+edx*4]							;jump to specified 'add_op'

MmxPsllw:	psllw mm0,mm1									;shift left logical word
			jmp SaveResult

MmxPsrlw:	psrlw mm0,mm1									;shift right logical word
			jmp SaveResult

MmxPsraw:	psraw mm0,mm1									;shift right arithmetic
			jmp SaveResult

MmxPslld:	pslld mm0,mm1									;packed word addition using wraparound
			jmp SaveResult

MmxPsrld:	psrld mm0,mm1									;packed word addition using signed saturation
			jmp SaveResult

MmxPsrad:	psrad mm0,mm1									;packed word addition using unsigned saturation
			jmp SaveResult
			ret

BadShiftOp:	pxor mm0,mm0

SaveResult: mov edx, [ebp+24]								;eaxm=low dword mm0
			movq [edx],mm0									;swap high 7 low dwords
			emms											;clear mmx stat
			pop ebp

			ret

			align 4

ShiftOpTable:
		dword MmxPsllw, MmxPsrlw, MmPsraw
		dword MmxPslld, MmxPsrld, MmxPsrad

ShiftOpTableCount equ ($-ShiftOpTable)/ size dword


MmxShifter		endp
				end