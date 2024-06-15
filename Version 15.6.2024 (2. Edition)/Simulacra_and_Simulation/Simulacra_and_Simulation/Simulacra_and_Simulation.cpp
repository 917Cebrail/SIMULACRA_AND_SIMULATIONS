#include "Logic_Gates.h"
#include "Donut.h"
#include "Executive.h"
#include "Simulacra.h"
#include "Quick_Sorting.h"
#include "Font.h"
#include <iomanip>
#include <bitset>
#include <cstdlib>
#include <fstream>
#include <string>
#include <iostream>
#include <cmath>
#include <cstring>
#include <thread>
#include <chrono>
using namespace std;

int main()
{
	Logic_Gates gate;
	Executive exe;
	Donut donut;
	Simulacra sim;
	Quick_Sorting qs;
	Font font;
	donut.set_console_size(100,50);
	string command;
	int loop;
	bool S[8]{ 0,0,0,0,0,0,0,0 }, S1[8], S2[8], RAM[8];
	system("title SIMULACRA_AND_SIMULATIONS");
	system("color 0A");
	system("dir");
	while (true)
	{
		cout << "\n > ";
		cin >> command;
		if (command == "BIN")
		{
			cout << " NOTE : 204 = null\n";
			cout << "Enter a S1 values {only 1 and 0}\n";
			for (int i = 0; i < 8; i++)
			{
				cout << " > ";
				cin >> S1[i];
			}
			cout << "\nEnter a S2 values {only 1 and 0}\n";
			for (int i = 0; i < 8; i++)
			{
				cout << " > ";
				cin >> S2[i];
			}
			system("cls");
			for (int i = 0; i < 8; i++)
			{
				cout << " " << S1[i];
			}
			cout << "\n";
			for (int i = 0; i < 8; i++)
			{
				cout << " " << S2[i];
			}
			cout << "\nHow many code line entered you will ?\n > ";
			cin >> loop;
			for (int i = 0; i < loop; i++)
			{
				cout << "\n" << "Enter the " << 1 + i << ". line code \n";
				for (int i = 0; i < 8; i++)
				{
					cout << " > ";
					cin >> S[i];
				}
				gate.CPU(S, S1, S2, RAM);
				cout << " = = R E S U L T S = = \n";
				for (int i = 0; i < 8; i++)
				{
					cout << " " << S[i];
				}
				cout << "\n";
				for (int i = 0; i < 8; i++)
				{
					cout << " " << S1[i];
				}
				cout << "\n";
				for (int i = 0; i < 8; i++)
				{
					cout << " " << S2[i];
				}
				cout << "\n " << 1 + i << ". Code line result\n";
				for (int i = 0; i < 8; i++)
				{
					cout << " " << RAM[i];
				}
			}
		}
		else if (command == "EXE")
		{
			int count;
			string chance;
			cout << "\nYou have a code file ? (*.sl)\n ('yes' or 'no') > ";
			cin >> chance;
			if (chance == "no")
			{
				cout << "\n How many code line entered you will ?\n > ";
				cin >> count;
				std::string code;
				system("cls");
				for (int i = 0; i < count; i++)
				{
					cout << " Code > ";
					cin >> code;
					exe.execute(code);
				}
			}
			else
			{
				std::string file_name;
				cout << "\n Enter file name \n > ";
				cin >> file_name;
				std::ifstream file(file_name);
				std::string line;
				if (!file.is_open()) {
					std::cerr << " File not opened : " << file_name << std::endl;
					return 1;
				}
				while (std::getline(file, line)) {
					std::cout << line << std::endl;
					exe.execute(line);
				}
				file.close();
			}
		}
		else if (command == "EXIT")
		{
			break;
		}
		else if (command == "QUICK_SORTING")
		{
			cout << " Enter array length\n > ";
			int leng = 10;
			cin >> leng;
			int* _array = new int[leng];
			srand(time(0));

			for (int i = 0; i < leng; i++) {
				_array[i] = rand() % 100;
			}

			cout << " Unsorted array : ";
			for (int i = 0; i < leng; i++) {
				cout << _array[i] << " ";
			}
			cout << endl;

			qs.Quick_Sort(_array, 0, leng - 1);

			cout << "\n Sorted array : ";
			for (int i = 0; i < leng; i++) {
				cout << _array[i] << " ";
			}
			std::cout << std::endl;
		}
		else if (command == "CLEAR")
		{
			system("cls");
		}
		else if (command == "DIR")
		{
			system("dir");
		}
		else if (command == "DONUT")
		{
			float A = 0, B = 0;
			while (true) {
				donut.render_frame(A, B);
				A += 0.04;
				B += 0.02;
				std::this_thread::sleep_for(std::chrono::milliseconds(30));
				system("cls");
			}
		}
		else if (command == "SIMULACRA")
		{
			sim.Main();
		}
		else if (command == "FONT")
		{
			cout << " Enter a font name \n > ";
			string _font = "Consolas";
			cin >> _font;
			wstring w_font(_font.begin(), _font.end());
			const wchar_t* fontName = w_font.c_str();
			SHORT fontSize = 24;
			font.ChangeConsoleFont(fontName, fontSize);
			std::cout << " Successful!" << std::endl;
		}
		else if (command == "HELP")
		{
			cout << "EXIT : Exit the  program\nCLEAR : Clear screen\nDIR : Showed the all files (Current Directory)";
			cout << "\nEXE : Executive the {*}.sl files\nBIN : Code entered a 8 bit cpu (0 and 1 style)";
		}
		else
		{
			cout << "\n Wrong Command.\n";
		}

	}
	return 0;
}
