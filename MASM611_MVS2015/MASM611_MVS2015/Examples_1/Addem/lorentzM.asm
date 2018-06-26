title The fun Subroutine    (lorentzM.asm)

; This subroutine links to Visual C++ 6.0.

.386P
.model flat
public _lorentzM

.code
_lorentzM proc near   ; Zamiana w tablicy ma³ych liter na wielkie
    push ebp
    mov ebp, esp

    mov esi, dword PTR[ebp+8]	; pierwszy argument funkcji
    mov ecx, 100h		; maksymalny zakres poszukiwania koñca ³añcucha  znaków -> 256 znakow
	mov edi, 0			; licznik d³ugoœci ³añcucha
ptl:
	mov dl, [esi]
	cmp dl, 0h
	je dalej
	inc esi
	inc edi
	loop ptl
dalej:				
	mov esi, dword PTR[ebp+12]	; wyznaczenie drugiego argumentu funkcji - d³ugoœci ³añcucha
	mov [esi], edi

	mov ecx, edi				; d³ugoœæ pêtli = d³ugoœci ³añcucha znaków
    mov esi, dword PTR[ebp+8]
ptl1:
	mov dl, [esi]
	cmp dl, 'a'
	jb nierob
	cmp dl, 'z'
	ja nierob
	sub dl, 20h
nierob:
    mov [esi], dl
	inc esi
	loop ptl1
	 
	mov eax, 0h		; return 0
    pop ebp
    ret                   
_lorentzM endp
end

