// Addem Main Program      (AddMain.cpp) 

#include <iostream>
using namespace std;

extern "C" int bmi(int p1, int p2, int p3);
extern "C" int broca(int x, int y, int z);
extern "C" int creff(char *strx, int *Slen);
//extern "C" int lorentzK(char *strx, int *Slen);
//extern "C" int lorentzM(char *strx, int *Slen);


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
	
	//*****************************************************
	
	float wynikBMI = bmi(10, 15, 25);
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

	wynikBMI = 23.00;
	cout << "Twoje BMI wynosi: " << wynikBMI << ". Jest to: " << endl;

	
	if (wynikBMI < 16) cout << "wyglodzenie";
	else if (wynikBMI >= 16 && wynikBMI < 17) cout << "wychudzenie" << endl;
	else if (wynikBMI >= 17 && wynikBMI < 18.5) cout << "niedowaga" << endl;
	else if (wynikBMI >= 18.5 && wynikBMI < 25) cout << "wartosc prawidlowa" << endl;
	else if (wynikBMI >= 25 && wynikBMI < 30) cout << "nadwaga" << endl;
	else if (wynikBMI >= 30 && wynikBMI < 35) cout << "I stopien otylosci" << endl;
	else if (wynikBMI >= 35 && wynikBMI < 40) cout << "II stopien otylosci" << endl;
	else if (wynikBMI >= 40) cout << "III stopien otylosci" << endl;

	//*****************************************************

	p1 = 20;  p2 = 15;  p3 = -2;
	int wynik = broca(p1, p2, p3);
	cout << "Wartosc funkcji w = 20*p3^2 - 100*p2 + p1" << endl;
	cout << "dla parametrow : p1 = "  << p1 << ", p2 = " << p2 << ", p3 = " << p3 << endl;
	cout << "wynosi ->   w = " << wynik << endl << endl;

	//*****************************************************

	for (count = 0; count < BUFSIZE; count++)  {
		if (buffer1[count] == '\0')  break;
	}
	cout << "Dlugosc lancucha znakow w tablicy buffer1 = " << count << endl;
	cout << "male litery \"PRZED\"  = " << buffer1 << endl;

	__asm {
		lea esi, buffer1  // Load Effective Address str. 68, 85
			lea edi, buffer
			mov ecx, count
			inc ecx
		L0 : mov dl, [esi]	// kopiowanie tablicy buffer1 do buffer
			 mov[edi], dl	// ³¹cznie ze znakiem koñca linii -> '\0'
			 inc esi
			 inc edi
			 loop L0

		;********

			lea esi, buffer1  // g³ówna petla -> pocz¹tek
			lea edi, buffer
			mov ecx, count
			dec ecx
		LA : mov dl, [esi]
			 cmp dl, 'd' //jesli rowne 'd' podmiana dwoch kol. znakow LB
			 jne LB
			 mov[edi], '*'
			 mov[edi + 1], '#'
		LB : inc esi
			 inc edi
			 Loop LA			// g³ówna pêtla -> koniec
	}	// asm

	cout << "male litery \"PO   \"  = " << buffer << endl << endl;

	//*****************************************************

	creff(buffer, &strlen);
	cout << "Wielkie litery          = " << buffer << endl;
	cout << "Dlugosc lancucha znakow = " << strlen << endl << endl;

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

	cout << "Liczby = ";
	for (i = 0; i < 10; i++) { cout << buffer2[i] << ", "; }
	cout << endl;



	return 0;
}


