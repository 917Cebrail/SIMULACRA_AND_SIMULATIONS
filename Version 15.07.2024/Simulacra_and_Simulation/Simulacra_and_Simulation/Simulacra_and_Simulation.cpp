#include "Logic_Gates.h"
#include "Donut.h"
#include "Executive.h"
#include "Simulacra.h"
#include "Quick_Sorting.h"
#include "Font.h"
#include "Hdd.h"
#include "Complex.h"

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
	donut.set_console_size(120,50);
	string command;
	int loop;
	bool S[8]{ 0,0,0,0,0,0,0,0 }, S1[8], S2[8], RAM[8];
	system("title SIMULACRA_AND_SIMULATIONS");
	system("color F0");
	cout << "\n System CMD Version Information";
	system("ver");
	cout << " .----------------------------------------------------." << endl;
	cout << " |   HELLO USER ! THIS IS SIMULACRA AND SIMULATIONS   |" << endl;
	cout << " '----------------------------------------------------'" << endl;
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
		else if (command == "HDD")
		{
			HDD();
		}
		else if (command == "FONT")
		{
			cout << " Enter a font name \n > ";
			string _font = "Consolas";
			cin >> _font;
			wstring w_font(_font.begin(), _font.end());
			const wchar_t* fontName = w_font.c_str();
			SHORT fontSize = 20;
			font.ChangeConsoleFont(fontName, fontSize);
			std::cout << " Successful!" << std::endl;
		}
		else if (command == "CMD")
		{
			string code;
			cout << " Enter a 'cmd' code/command \n > ";
			cin >> code;
			cout << " Result : " << endl;
			system(code.c_str());
		}
		else if (command == "HELP")
		{
			cout << "\n EXIT : Exit the  program\n CLEAR : Clear screen\n DIR : Showed the all files (Current Directory)";
			cout << "\n EXE : Executive the {*}.sl files\n BIN : Code entered a 8 bit cpu (0 and 1 style)";
			cout << "\n DONUT : Spinned the donut ?\n HDD : Reading the {*}.slh files\n SIMULACRA : Simulating the {*}.sli files";
			cout << "\n CMD : Running CMD Commands\n FONT : changed a font \n QUICK_SORTING : Randomise arrays sorting the Quick style";
			cout << "\n QBIT : Qbit simulation (DEMO)\n COMP : Complex operations\n PLOT : Drawing graph with vertex logic";
			cout << "\n VISIT : Most Popular Websites Visiting\n ABOUT : About this program\n INT : Surfing internet";
		}
		else if (command == "VISIT")
		{
			cout << ".-----------------------------." << endl;
			cout << "|      WEBSITE   MANAGER      |" << endl;
			cout << "| [1] Github     [4] Youtube  |" << endl;
			cout << "| [2] ChatGPT    [5] Slowride |" << endl;
			cout << "| [3] Google     [6] None     |" << endl;
			cout << "'-----------------------------'" << endl;
			int x;
			cout << " > ";
			cin >> x;
			if (x == 1)
			{
				std::string op = std::string("start ").append("www.github.com");
				system(op.c_str());
			}
			else if (x == 2)
			{
				std::string op = std::string("start ").append("www.chatgpt.com");
				system(op.c_str());
			}
			else if (x == 3)
			{
				std::string op = std::string("start ").append("www.google.com");
				system(op.c_str());
			}
			else if (x == 4)
			{
				std::string op = std::string("start ").append("www.youtube.com");
				system(op.c_str());
			}
			else if (x == 5)
			{
				std::string op = std::string("start ").append("www.slowride.io");
				system(op.c_str());
			}
			else
			{}
		}
		else if (command == "INT")
		{
			char url[100];
			cout << "\n Enter URL > ";
			cin >> url;
			std::string op = std::string("start ").append(url);
			system(op.c_str());
		}
		else if (command == "ABOUT")
		{
			cout << " .----------------------------------------------------------------------------------------------------------------.";
			cout << "\n  This program writted C++ language, but still have a own ecosystem. .slh , .sli , .sl files...";
			cout << "\n  APPLE I or II style but its have differents the APPLE, still have a two programming language. Binary & Executive";
			cout << "\n  Starting date : 16.06.2024    Version : 1.0.3.16  /  15.07.2024\n  Do you want a new version ? let me check it -->  https://github.com/917Cebrail/SIMULACRA_AND_SIMULATIONS";
			cout << "\n  You not know a any command ? Type 'HELP' and saw the all command and comments...";
			cout << "\n '----------------------------------------------------------------------------------------------------------------'";
		}
		else if (command == "QBIT")
		{
			double alpha = 1 / sqrt(2);
			double beta = 1 / sqrt(2);
			std::cout << "Qubit state: " << std::endl;
			std::cout << "Alpha (|0>): " << alpha << std::endl;
			std::cout << "Beta (|1>): " << beta << std::endl;
		}
		else if (command == "COMP")
		{
			int choose;
			cout << " [1] : Make some operations\n [2] : Make Complex object\n > ";
			cin >> choose;
			if (choose == 1)
			{
				int z1a, z1b, z2a, z2b;
				cout << " Z1(Re) A > ";
				cin >> z1a;
				cout << " Z1(Im) B > ";
				cin >> z1b;
				cout << " Z2(Re) A > ";
				cin >> z2a;
				cout << " Z2(Im) B > ";
				cin >> z2b;
				Complex z1(z1a, z1b);
				Complex z2(z2a, z2b);
				cout << "\n Z1(Re) : ";
				z1.getReal();
				cout << " , Z1(Im)";
				z1.getImaginary();
				cout << "\n Z2(Re) : ";
				z2.getReal();
				cout << " , Z2(Im)";
				z2.getImaginary();
				cout << "\n Auto big number is activated ?\n  ('yes' or 'no') : ";
				char chance[10];
				cin >> chance;
				if (chance == "yes")
				{
					cout << "\n";
					Complex sum = z1 + z2;
					if (z1.getReal() > z2.getReal())
					{
						Complex sub = z1 - z2;
						cout << " SUB Z1 - Z2";
						sub.print();
					}
					else
					{
						Complex sub = z2 - z1;
						cout << " SUB Z2 - Z1 : ";
						sub.print();
					}
					cout << " SUM Z1 + Z2 : ";
					sum.print();
				}
				else
				{
					cout << "\n";
					Complex sum = z1 + z2;
					Complex sub = z1 - z2;
					cout << " SUM Z1 + Z2 : ";
					sum.print();
					cout << " SUB Z1 - Z2 : ";
					sub.print();
				}
			}
			else if (choose == 2)
			{
				int z1a, z1b;
				cout << " Z1(Re) A > ";
				cin >> z1a;
				cout << " Z1(Im) B > ";
				cin >> z1b;
				Complex z1(z1a, z1b);
				cout << "\n Z1(Re) : ";
				z1.getReal();
				cout << " , Z1(Im)";
				z1.getImaginary();
				cout << "\n";
			}
			else
			{
				cout << "\n Wrong chosing... \n";
			}
		}
		else
		{
			cout << "\n Wrong Command. If you saw the commands ? Enter 'HELP' command\n";
		}

	}
	return 0;
}
