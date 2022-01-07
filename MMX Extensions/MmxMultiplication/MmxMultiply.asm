					.model flat,c
					.code
MmxMultiply			proc
					push ebp
					mov ebp,esp

					movq mm0,[ebp+8]
					movq mm1,[ebp+16]

					movq mm2,mm0
					pmullw mm0,mm1
					pmulhw mm1,mm2
					movq mm2,mm0
					punpcklwd mm0,mm1
					punpckhwd mm2,mm1

					mov eax,[ebp+24]
					mov edx,[ebp+28]
					movq [eax],mm0
					movq [edx],mm2

					pop ebp
					ret

MmxMultiply			endp
					end