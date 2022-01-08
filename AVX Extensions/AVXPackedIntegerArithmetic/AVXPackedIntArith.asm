					.model flat,c
					.code

AVXPackedInt_16		proc
					push ebp
					mov ebp,esp

					mov eax,[ebp+8]					;eax = pointer to a
					mov ecx,[ebp+12]				;ecx = pointer to b
					mov edx,[ebp+16]				;edx = pointer to c

					vmovdqa ymm0, ymmword ptr [eax]	;ymm0 = a
					vmovdqa ymm1, ymmword ptr [ecx] ;ymm1 = b

					vpaddw ymm2,ymm0,ymm1			;ymm2 = ymm0 + ymm1
					vpaddsw ymm3,ymm0,ymm1			;ymm3 = ymm0 + ymm1, signed

					vpsubw ymm4,ymm0,ymm1
					vpsubsw ymm5,ymm0,ymm1			;signed saturation subtraction

					vpminsw ymm6,ymm0,ymm1			;signed minimum
					vpmaxsw ymm7,ymm0,ymm1			;signed maximum

				;Save results
					vmovdqa ymmword ptr [edx],ymm2
					vmovdqa ymmword ptr [edx+32],ymm3
					vmovdqa ymmword ptr [edx+64],ymm4
					vmovdqa ymmword ptr [edx+96],ymm5
					vmovdqa ymmword ptr [edx+128],ymm6
					vmovdqa ymmword ptr [edx+160],ymm7

					vzeroupper
					pop ebp
					ret
AVXPackedInt_16		endp

AVXPackedInt_32		proc
					push ebp
					mov ebp,esp

					vmovdqa ymm0, ymmword ptr [eax]	;ymm0 = a
					vmovdqa ymm1, ymmword ptr [ecx] ;ymm1 = b

					vphaddd ymm2,ymm0,ymm1			;horizontal add
					vphsubd ymm3,ymm0,ymm1			;horizontal sub
					vpmulld ymm4,ymm0,ymm1			;signed mul
					vpsllvd ymm5,ymm0,ymm1			;logical shift left
					vpsravd ymm6,ymm0,ymm1			;arithmetic shift right

				;Save results
					vmovdqa ymmword ptr [edx],ymm2
					vmovdqa ymmword ptr [edx+32],ymm3
					vmovdqa ymmword ptr [edx+64],ymm4
					vmovdqa ymmword ptr [edx+96],ymm5
					vmovdqa ymmword ptr [edx+128],ymm6

					vzeroupper
					pop ebp
					ret
AVXPackedInt_32		endp
					end