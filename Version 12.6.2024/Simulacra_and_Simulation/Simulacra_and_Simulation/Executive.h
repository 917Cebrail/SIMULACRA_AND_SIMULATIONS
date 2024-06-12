#include <iostream>
#include <vector>
#include <bitset>
#include <cstdint>

class Executive
{
public:
	// Ana veri giriþi
	uint8_t A = 0;
	uint8_t B = 0;
	uint8_t C = 0;
	std::vector<uint8_t> memory;
	Executive() : memory(256) {}

	void BUFFER(uint8_t operand){
		C = operand;
	}

	void NOT(uint8_t operand) {
		C = !operand;
	}

	void AND(uint8_t operand1, uint8_t operand2) {
		C = operand1 & operand2;
	}

	void NAND(uint8_t operand1, uint8_t operand2) {
		C = !(operand1 & operand2);
	}

	void OR(uint8_t operand1, uint8_t operand2) {
		C = operand1 | operand2;
	}

	void XOR(uint8_t operand1, uint8_t operand2) {
		C = operand1 != operand2;
	}

	void NOR(uint8_t operand1, uint8_t operand2) {
		C = !(operand1 | operand2);
	}

	void SUM(uint8_t operand1, uint8_t operand2, uint8_t carry_in) {
		uint16_t result = operand1 + operand2 + carry_in;
		C = result & 0xFF;
	}

	void execute(uint8_t opcode) {
		switch (opcode) {
		case 0x00:
			BUFFER(A);
			break;
		case 0x01:
			BUFFER(B);
			break;
		case 0x02:
			NOT(A);
			break;
		case 0x03:
			NOT(B);
			break;
		case 0x04:
			AND(A, B);
			break;
		case 0x05:
			OR(A, B);
			break;
		case 0x06:
			XOR(A, B);
			break;
		case 0x07:
			NOR(A, B);
		case 0x08:
			NAND(A, B);
			break;
		case 0x09:
			SUM(A, B, 1);
			break;
		case 0x10:
			SUM(A, B, 1);
			break;
		default:
			std::cerr << "Unknown Command: " << std::bitset<8>(opcode) << std::endl;
			break;
		}
	}
};

