#include <iomanip>
#include <bitset>
#include <cstdlib>
#include <fstream>
#include <string>
#include <iostream>

class Executive
{
public:
	uint8_t A = 0;
	uint8_t B = 0;
	uint8_t C = 0;
	std::int16_t _ram[256]{};

	void AND(uint8_t operand1, uint8_t operand2) {
		C = operand1 & operand2;
	}

	void NAND(uint8_t operand1, uint8_t operand2) {
		C = !(operand1 & operand2);
	}

	void OR(uint8_t operand1, uint8_t operand2) {
		C = operand1 | operand2;
	}

	void NOR(uint8_t operand1, uint8_t operand2) {
		C = !(operand1 | operand2);
	}

	void SUM(uint8_t operand1, uint8_t operand2, uint8_t carry_in) {
		uint16_t result = operand1 + operand2 + carry_in;
		C = result & 0xFF;
	}

	void SUB(uint8_t operand1, uint8_t operand2, uint8_t carry_in) {
		if (operand1 > operand2)
		{
			uint16_t result = (operand1 - operand2) - carry_in;
			C = result & 0xFF;
		}
		else
		{
			uint16_t result = (operand2 - operand1) - carry_in;
			C = result & 0xFF;
		}
	}

	void MUL(uint8_t operand1, uint8_t operand2, uint8_t carry_in) {
		uint16_t result = (operand1 * operand2) + carry_in;
		C = result & 0xFF;
	}

	void DIV(uint8_t operand1, uint8_t operand2, uint8_t carry_in) {
		if (operand1 > operand2)
		{
			uint16_t result = (operand1 / operand2) + carry_in;
			C = result & 0xFF;
		}
		else
		{
			uint16_t result = (operand2 / operand1) + carry_in;
			C = result & 0xFF;
		}
	}

	void execute(std::string code) {
		std::cout << " Executing Operand Code : " << code << std::endl;
		std::string keyword = "PRINT_";
		size_t pos = code.find(keyword);
		if (pos != std::string::npos) {
			std::string toPrint = code.substr(pos + keyword.length());
			std::cout << " " << toPrint << std::endl;
		}
		else if (code == "BUFFER_A") {
			C = A;
		}
		else if (code == "BUFFER_B") {
			C = B;
		}
		else if (code == "BUFFER_RAM[A]") {
			C = _ram[A];
		}
		else if (code == "BUFFER_RAM[B]") {
			C = _ram[B];
		}
		else if (code == "INPUT_A")
		{
			std::cout << " > ";
			int a_input;
			std::cin >> a_input;
			A = static_cast<uint8_t>(a_input);
		}
		else if (code == "INPUT_B")
		{
			std::cout << " > ";
			int b_input;
			std::cin >> b_input;
			B = static_cast<uint8_t>(b_input);
		}
		else if (code == "AND_A,B") {
			AND(A, B);
		}
		else if (code == "OR_A,B") {
			OR(A, B);
		}
		else if (code == "NAND_A,B") {
			NAND(A, B);
		}
		else if (code == "NOR_A,B") {
			NOR(A, B);
		}
		else if (code == "SUM_A+B_C=1") {
			SUM(A, B, 1);
		}
		else if (code == "SUM_A+B_C=0") {
			SUM(A, B, 0);
		}
		else if (code == "SUB_A-B C=1") {
			SUB(A, B, 1);
		}
		else if (code == "SUB_A-B_C=0") {
			SUB(A, B, 0);
		}
		else if (code == "MUL_A*B_C=1") {
			MUL(A, B, 1);
		}
		else if (code == "MUL_A*B_C=0") {
			MUL(A, B, 0);
		}
		else if (code == "DIV_A/B_C=1") {
			DIV(A, B, 1);
		}
		else if (code == "DIV_A/B_C=0") {
			DIV(A, B, 0);
		}
		else if (code == "C->RAM[A]")
		{
			_ram[A] = C;
		}
		else if (code == "C->RAM[B]")
		{
			_ram[B] = C;
		}
		else if (code == "RAM[A]->A")
		{
			_ram[A] = C;
		}
		else if (code == "RAM[B]->B")
		{
			_ram[B] = C;
		}
		else if (code == "RAM[A]->B")
		{
			_ram[A] = C;
		}
		else if (code == "RAM[B]->A")
		{
			_ram[B] = C;
		}
		else if (code == "IF(A=B)")
		{
			if (A == B)
			{
				C = 0;
			}
			else
			{
				C = 1;
			}
		}
		else if (code == "CHECK(C=0)")
		{
			if (C == 0)
			{
				std::cout << "TRUE" << std::endl;
			}
			else
			{
				std::cout << "FALSE, C = 1" << std::endl;
			}
		}
		else {
			std::cerr << "Unknown Command : " << code << std::endl;
		}
		std::cout << " Result : " << static_cast<int>(C) << std::endl;
	}
};

