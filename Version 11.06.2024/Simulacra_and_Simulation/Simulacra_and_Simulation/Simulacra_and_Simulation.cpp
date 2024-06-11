#include "Logic_Gates.h"
#include <cstdlib>
#include <iostream>
using namespace std;

int main()
{
	Logic_Gates gate;

	/*
	Denemelik 8 bitlik veriler, istediğiniz şekilde kullanın.
	bool S[8]{false, false , false , false , false , false , true , true }; // 1-1
	bool ex[8]{ false, true, true, false, false, false, false, true }; // 0-1-1-0-0-0-0-1
	bool s1[8]{ false, true, true, false, false, false, true, false }; // 0-1-1-0-0-0-1-0
	bool s2[8]{ false, true, true, false, false, false, true, true }; // 0-1-1-0-0-0-1-1
	bool s3[8]{ false, true, true, false, false, true, false, false }; // 0-1-1-0-0-1-0-0
	bool s4[8]{ false, true, true, false, false, true, false, true }; // 0-1-1-0-0-1-0-1
	*/


	// Örnek : 2 sayıyı toplayan ve 2 sayıyı çıkaran kod.
	// Aslında kod 00000010, 00000011, 00001110, 00001111 olsa da gerçekte ifadesi, yukarıdaki açıklamadır.
	bool result[2], z[8], sel1, sel2, x, y;
	system("color F0");
	cout << "\n  NOTE : 204 = Null \n" << "  Read the outputs (for example 0 1) from right to left \n" << endl;

	// Burada 'true' ya da 'false' yerine 1 ve 0 koyabilirdim. Yapmamamın nedeni
	// halen daha işlemciye kod eklense de bu işlem bilgisayardan yapılıyor.
	bool CL1[8]{ false, false , false , false , false , false , true , false };
	bool CL2[8]{ false, false , false , false , false , false , true , true };
	bool CL3[8]{ false, false , false , false , true , true , true , false };
	bool CL4[8]{ false, false , false , false , true , true , true , true };

	cout << " Enter A {1 or 0} : ";
	cin >> x;
	cout << " Enter B {1 or 0} : ";
	cin >> y;
	bool A[8]{x, 0, 0, 0, 0, 0, 0, 0};
	bool B[8]{y, 0, 0, 0, 0, 0, 0, 0 };
	cout << "\n";

	cout << "\n = = = = = = = = A D D E R = = = = = = = = \n" << endl;
	cout << "YOUR CODE : 00000010 | A : "<< A[0] <<" | B : " << B[0] << " | C_in : 1 \n" << endl;
	gate.CPU(CL1, A, B, z);
	cout << "Z | Carry" << endl;
	for (int i = 0; i < 2; i++)
	{ cout << z[i] << "   "; }
	cout << "\n = = = = = = = = = = = = = = = = = = = = \n" << endl;

	gate.CPU(CL2, A, B, z);
	cout << "YOUR CODE : 00000011 | A : " << A[0] << " | B : " << B[0] << " | C_in : 0 \n" << endl;
	cout << "Z | Carry" << endl;
	for (int i = 0; i < 2; i++)
	{ cout << z[i] << "   "; }

	cout << "\n = = = = = = = = = S U B =  = = = = = = = = = \n" << endl;

	cout << "YOUR CODE : 00001110 | A : " << A[0] << " | B : " << B[0] << " | C_in : 1 \n" << endl;
	gate.CPU(CL3, A, B, z);
	cout << "D | B" << endl;
	for (int i = 0; i < 2; i++)
	{ cout << z[i] << "   "; }
	cout << "\n = = = = = = = = = = = = = = = = = = = = \n" << endl;

	gate.CPU(CL4, A, B, z);
	cout << "YOUR CODE : 00001111 | A : " << A[0] << " | B : " << B[0] << " | C_in : 0 \n" << endl;
	cout << "D | B" << endl;
	for (int i = 0; i < 2; i++)
	{ cout << z[i] << "   "; }

	cout << "\n" << endl;
	cin >> x ;
	return 0;
}

/*
Renk Kodları
0 = Black
1 = Blue
2 = Green
3 = Aqua
4 = Red
5 = Purple
6 = Yellow
7 = White
8 = Gray
9 = Light Blue
A = Light Green
B = Light Aqua
C = Light Red
D = Light Purple
E = Light Yellow
F = Bright White
*/
