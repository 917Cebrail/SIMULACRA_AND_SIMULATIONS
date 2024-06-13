#include <iostream>
#include <vector>
#include <bitset>

class Executive
{
public:
	uint8_t A = 0;
	uint8_t B = 0;
	uint8_t C = 0;

	void AND(uint8_t operand1, uint8_t operand2) {
		C = operand1 & operand2;
	}

	void OR(uint8_t operand1, uint8_t operand2) {
		C = operand1 | operand2;
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

	void execute(uint8_t opcode) {
		std::cout << "Executing opcode: " << std::bitset<8>(opcode) << std::endl;
		switch (opcode) {
		case 0x00:
			AND(A, B);
			break;
		case 0x01:
			OR(A, B);
			break;
		case 0x02:
			SUM(A, B, 1);
			break;
		case 0x03:
			SUM(A, B, 0);
			break;
		case 0x04:
			SUB(A, B, 1);
			break;
		case 0x05:
			SUB(A, B, 0);
			break;
		default:
			std::cerr << "Unknown instruction: " << std::bitset<8>(opcode) << std::endl;
			break;
		}
	}

};

