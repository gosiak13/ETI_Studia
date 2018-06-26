title The fun Subroutine    (creff.asm)

; This subroutine links to Visual C++ 6.0.

.386P
.model flat
public _creff

.code
_creff proc near   ;	creffFormula(wzrost,wiek);

    push   ebp
    mov    ebp,esp
    mov		eax,  sdword PTR[ebp+8]	;first argument - height 
	mov		ebx, 100 
	sub		eax, ebx
	mov     ebx, 10
	mul     ebx
    mov		ebx, sdword PTR[ebp+12]	;second argument - age
	add     eax,  ebx
	mov     ebx, 9
	mul     ebx
    pop    ebp
    ret             
	      
_creff endp
end

