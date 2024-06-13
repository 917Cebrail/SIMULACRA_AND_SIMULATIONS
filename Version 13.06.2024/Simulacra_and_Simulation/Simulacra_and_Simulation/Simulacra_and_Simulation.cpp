#include "Logic_Gates.h"
#include "Executive.h"
#include <iomanip>
#include <bitset>
#include <cstdlib>
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
		// Yeni Method
		else if (command == "EXE")
		{
			std::cout << "Enter A value (int): ";
			int a_input;
			std::cin >> a_input;
			exe.A = static_cast<uint8_t>(a_input);

			std::cout << "Enter B value (int): ";
			int b_input;
			std::cin >> b_input;
			exe.B = static_cast<uint8_t>(b_input);

			std::vector<uint8_t> program = { 0x03, 0x02, 0x04, 0x05 };

			for (auto opcode : program) {
				exe.execute(opcode);
				std::cout << "Result after executing " << std::bitset<8>(opcode) << ": " << static_cast<int>(exe.C) << std::endl;
			}

		}
		else if (command == "EXIT")
		{
			break;
		}
		else
		{
			cout << " Wrong Command.";
		}

	}
	return 0;
}
