title The fun Subroutine    (broca.asm)

; This subroutine links to Visual C++ 6.0.

.386P
.model flat
public _broca

.code
_broca proc near   ; weight = height - 100
    push   ebp
    mov    ebp,esp

 
    mov		eax,  sdword PTR[ebp+8]	;second argument - height 
    mov		ebx, 100
    sub     eax, ebx
    pop    ebp
    ret                   
_broca endp
end

