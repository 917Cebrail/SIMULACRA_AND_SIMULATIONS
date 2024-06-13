#include <iostream>
#include <vector>
#include <bitset>

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

		if (code == "BUFFER_A") {
			C = A;
		}
		else if (code == "BUFFER_B") {
			C = B;
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
		else {
			std::cerr << "Unknown Command : " << code << std::endl;
		}
		std::cout << " Result: " << static_cast<int>(C) << std::endl;
	}
};

