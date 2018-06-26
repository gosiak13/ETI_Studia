title The fun Subroutine    (lorentzM.asm)

; This subroutine links to Visual C++ 6.0.

.386P
.model flat
public _lorentzM

.code
_lorentzM proc near   ; (height - 100 - ((height - 150) / 4)
    push   ebp
    mov    ebp,esp
    mov		eax,  sdword PTR[ebp+8]	;first argument - height 
    mov		ebx, 10
	mul     ebx
	mov     ebx,  1000
    sub     eax, ebx
	push    eax
	mov		eax,  sdword PTR[ebp+8]	;first argument - height 
    mov		ebx, 10
	mul     ebx
	mov     ebx,  1500
	sub		eax, ebx
	mov     ebx, 4
	div     ebx
	pop ebx
	sub   ebx, eax
	mov   eax, ebx
    pop    ebp
    ret                   
_lorentzM endp
end

