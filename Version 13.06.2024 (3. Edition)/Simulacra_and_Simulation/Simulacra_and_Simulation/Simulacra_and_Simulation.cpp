#include "Logic_Gates.h"
#include "Executive.h"
#include <iomanip>
#include <bitset>
#include <cstdlib>
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

int main()
{
	Logic_Gates gate;
	Executive exe;
	string command;
	int loop;
	bool S[8]{ 0,0,0,0,0,0,0,0 }, S1[8], S2[8], RAM[8];
	system("color 0A");
	system("dir");
	while (true)
	{
		cout << " > ";
		cin >> command;
		if (command == "CODE")
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
		else if (command == "CLEAR")
		{
			system("cls");
		}
		else
		{
			cout << "\n Wrong Command.\n";
		}

	}
	return 0;
}
