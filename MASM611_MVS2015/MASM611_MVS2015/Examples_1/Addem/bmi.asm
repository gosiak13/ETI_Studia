; The addem Subroutine    (bmi.asm)

; This subroutine links to Visual C++.

.386P
.model flat
public _bmi

.code
_bmi proc near
    push   ebp
    mov    ebp,esp
    mov    eax,[ebp+12]    ; wzrost
	mul    eax				
	push   eax								;wzrost*wzrost
    mov    eax,[ebp+8]     ;waga
	mov		ebx, 100000
	mul		ebx
	pop    ebx
	mov		edx,0
	div    ebx 		;pierwsze dzielenie
	;mov		esi, dword PTR[ebp+16]	; wyznaczenie drugiego argumentu funkcji - d³ugoœci ³añcucha
	;mov		[esi],edx
    pop    ebp
    ret                   
_bmi endp
end

