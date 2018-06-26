// Addem Main Program      (AddMain.cpp) 

#include <iostream>
#include <string>
#include <stdio.h>  

using namespace std;

extern "C" int bmi(int p1, int p2);
extern "C" int broca(int x);
extern "C" int creff(int height, int wiek);
extern "C" int lorentzK(int x);
extern "C" int lorentzM(int x);

//extern "C" void print();


int main()
{
	const int BUFSIZE = 200;
	char buffer[BUFSIZE];
	char buffer1[BUFSIZE] = "abcdefghijkabcdefghijkabcdefghijkddd\0";
	int buffer2[BUFSIZE] = { 48, 49, 50, 51, 52, 53, 54, 55, 56, 57 };
	int count;				// loop count
	int p1, p2, p3;
	int i;
	int strlen;
	int wzrost, waga, wiek;
	char cPlec;
	float wynikBMI = 0.0;
	float wBroca = 0.0;
	float wCreff = 0.0;
	int wLorentzM;
	int wLorentzK;
	int wagaSrednia = 0;
	int wagaB;
	int wagaC;
	int wagaL;
	
	//*****************************************************

	cout << "Jaki jest Twoj wzrost [cm]?" << endl;
	cin >> wzrost;
	cout << endl << "Ile wazysz [kg]?" << endl;
	cin >> waga;
	cout << endl << "Ile masz lat?" << endl;
	cin >> wiek;
	cout << endl << "Jakiej jestes plci? kobieta - k, mezczyzna - m" << endl;
	cin >> cPlec;

	cout << "Total = " << wynikBMI << endl << endl;
	cout << "Klasyfikacja wskaznika BMI:" << endl;
	cout << "< 16				wyglodzenie" << endl;
	cout << "16.00-16.99			wychudzenie" << endl;
	cout << "17.00-18.49			niedowaga" << endl;
	cout << "18.50-24.99			wartosc prawidlowa" << endl;
	cout << "25.00-29.99			nadwaga" << endl;
	cout << "30.00-34.99			I stopien otylosci" << endl;
	cout << "35.00-39.99			II stopien otylosci" << endl;
	cout << ">= 40				III stopien otylosci" << endl;
	cout << endl;

	wynikBMI = bmi(waga, wzrost);
	wynikBMI = wynikBMI / 10;
	cout << "Twoje BMI wynosi: " << wynikBMI << ". Jest to: " << endl;
	wynikBMI = round(wynikBMI*10);
	int intbmi = (int)wynikBMI;
	//cout << intbmi << endl;

	char t1[BUFSIZE] = "wyglodzenie";
	char t2[BUFSIZE] = "wychudzenie";
	char t3[BUFSIZE] = "niedowaga";
	char t4[BUFSIZE] = "wartosc prawidlowa";
	char t5[BUFSIZE] = "nadwaga";
	char t6[BUFSIZE] = "I stopien otylosci";
	char t7[BUFSIZE] = "II stopien otylosci";
	char t8[BUFSIZE] = "III stopien otylosci";

	count = 20;

		__asm
		{
			mov eax, 160
			cmp intbmi, eax
			jb przepisz1

			mov eax, 170
			cmp intbmi, eax
			jb przepisz2

			mov eax, 185
			cmp intbmi, eax
			jb przepisz3

			mov eax, 250
			cmp intbmi, eax
			jb przepisz4

			mov eax, 300
			cmp intbmi, eax
			jb przepisz5

			mov eax, 350
			cmp intbmi, eax
			jb przepisz6

			mov eax, 400
			cmp intbmi, eax
			jb przepisz7

			jmp przepisz8
			jmp wyjdz2

			przepisz1:
				lea esi, t1  // Load Effective Address str. 68, 85
				jmp wyjdz2

			przepisz2:
				lea esi, t2  // Load Effective Address str. 68, 85
				jmp wyjdz2

			przepisz3 :
				lea esi, t3  // Load Effective Address str. 68, 85
				jmp wyjdz2

			przepisz4 :
				lea esi, t4  // Load Effective Address str. 68, 85
				jmp wyjdz2

			przepisz5 :
				lea esi, t5  // Load Effective Address str. 68, 85
				jmp wyjdz2

			przepisz6 :
				lea esi, t6  // Load Effective Address str. 68, 85
				jmp wyjdz2

			przepisz7 :
				lea esi, t7  // Load Effective Address str. 68, 85
				jmp wyjdz2

			przepisz8 :
				lea esi, t8  // Load Effective Address str. 68, 85
				jmp wyjdz2

			wyjdz2:
				lea edi, buffer
				mov ecx, count
				inc ecx
				L0 : mov dl, [esi]	// kopiowanie tablicy buffer1 do buffer
					mov[edi], dl	// ³¹cznie ze znakiem koñca linii -> '\0'
					inc esi
					inc edi
					loop L0
		}

		for (int i = 0; i < 20; i++) {
			cout << buffer[i];               
		}   
		cout << endl;
		                                                                                                                                                                                                    
    /*
	if (wynikBMI < 16) cout << "wyglodzenie" << endl;
    else if (wynikBMI >= 16 && wynikBMI < 17) cout << "wychudzenie" << endl;
	else if (wynikBMI >= 17 && wynikBMI < 18.5) cout << "niedowaga" << endl;
	else if (wynikBMI >= 18.5 && wynikBMI < 25) cout << "wartosc prawidlowa" << endl;
	else if (wynikBMI >= 25 && wynikBMI < 30) cout << "nadwaga" << endl;
	else if (wynikBMI >= 30 && wynikBMI < 35) cout << "I stopien otylosci" << endl;
	else if (wynikBMI >= 35 && wynikBMI < 40) cout << "II stopien otylosci" << endl;
	else if (wynikBMI >= 40) cout << "III stopien otylosci" << endl;*/

	//*****************************************************
	cout << "Twoja idealna waga wedlug: " << endl;
	wBroca = broca(wzrost);                                                 
	wCreff = creff(wzrost, wiek);
	wCreff = wCreff / 100;
	wLorentzK = lorentzK(wzrost);
	wLorentzM = lorentzM(wzrost);
	int wLorentz;

	__asm {
		cmp cPlec, 'k'
		jz przypisz1
		cmp cPlec, 'm'
		jz przypisz2
		przypisz1:
			mov eax, wLorentzK
			mov wLorentz, eax
			jmp wyjdz
		przypisz2:
			mov eax, wLorentzM
			mov wLorentz, eax
			jmp wyjdz
		wyjdz:
	}
	//if (cPlec == 'k') wLorentz = wLorentzK;
	//else if (cPlec == 'm') wLorentz = wLorentzM;
	wLorentz = wLorentz / 10;

	cout << "Broca: " << wBroca << endl << "Creff'a: " << wCreff << endl << "Lorentz'a: " << wLorentz << endl;

	//*****************************************************
	wagaC = (int)wCreff;
	wagaL = (int)wLorentz;
	wagaB = (int)wBroca;

	__asm {
		mov eax, wagaSrednia
		mov  ebx, wagaC
		add eax, ebx
		mov ebx, wagaL
		add eax, ebx
		mov ebx, wagaC
		add eax, ebx
		mov ebx, 3
		div ebx
		mov wagaSrednia, eax
	}   // asm
	cout << "Srednia waga idealna: " << wagaSrednia << endl;


	int roznica;
	__asm {
		mov eax, waga
		mov  ebx, wagaSrednia
		sub eax, ebx
		mov roznica, eax
	}   // asm

	cout << "Roznica miedzy twoja waga a srednia idealna: " << roznica << endl;


	//*****************************************************

	count = 10 - 1;

	__asm {
			lea esi, buffer2  // Load Effective Address str. 68, 85
			mov ecx, count
		L1 : mov edx, dword PTR[esi] //inty 32 bitowe
			cmp dl, 50;
			je L2
			inc  esi
			inc  esi
			inc  esi
			inc  esi
			Loop L1
		L2 : mov dword PTR[esi], 1000
			 mov dword PTR[esi + 4], 1001
	}	// asm
	
	return 0;
}


