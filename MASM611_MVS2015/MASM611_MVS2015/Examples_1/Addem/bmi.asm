; The addem Subroutine    (addem.asm)

; This subroutine links to Visual C++.

.386P
.model flat
public _bmi

.code
_bmi proc near
    push   ebp
    mov    ebp,esp
    mov    eax,[ebp+16]    ; third argument
    add    eax,[ebp+12]    ; second argument
    add    eax,[ebp+8]     ; first argument
    pop    ebp
    ret                   
_bmi endp
end

