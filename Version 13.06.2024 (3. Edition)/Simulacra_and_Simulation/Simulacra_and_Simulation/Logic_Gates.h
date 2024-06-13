#ifndef LOGIC_GATES_H
#define LOGIC_GATES_H
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

class Logic_Gates
{
public:
	bool memory[16];
	bool and_gate(bool s1, bool s2) { return s1 && s2; }
	bool or_gate(bool s1, bool s2) { return s1 || s2; }
	bool not_gate(bool s) { return !s; }
	bool buffer_gate(bool s) { return s; }
	bool nor_gate(bool s1, bool s2) { return !(s1 || s2); }
	bool xor_gate(bool s1, bool s2) { return s1 != s2; }
	bool nand_gate(bool s1, bool s2) { return !(s1 && s2); }

	bool Latch(bool s, bool r) 
	{
		bool output = s, res;
		res = and_gate(not_gate(r), output);
		return xor_gate(s, res);
	}

	void Half_Adder(bool s1, bool s2, bool* z) 
	{
		z[0] = (s1 != s2);
		z[1] = (s1 && s2);
	}

	void Half_Subtraction(bool s1, bool s2, bool* z)
	{
		z[0] = (s1 != s2);
		z[1] = ((!s1) && s2);
	}

	void Multiplexer(bool s1[8], bool s2[8], bool sel, bool z[8])
	{
		bool a1, a2;
		for (int i = 0; i < 8; i++)
		{
			a1 = and_gate(s1[i], sel);
			a2 = and_gate(s2[i], !sel);
			z[i] = or_gate(a1, a2);
		}
	}

	void Adder(bool s1, bool s2, bool ci, bool* z)
	{
		bool temp[2];
		Half_Adder(s1, s2, temp);
		bool sum1 = temp[0], carry1 = temp[1];
		Half_Adder(sum1, ci, temp);
		bool sum2 = temp[0], carry2 = temp[1];
		z[0] = sum2;
		z[1] = or_gate(carry1, carry2);
	}

	void Subtraction(bool s1, bool s2, bool ci, bool* z)
	{
		bool temp[2];
		Half_Subtraction(s1, s2, temp);
		bool diff1 = temp[0], borrow1 = temp[1];
		Half_Subtraction(diff1, ci, temp);
		bool diff2 = temp[0], borrow2 = temp[1];
		z[0] = diff2;
		z[1] = or_gate(borrow1, borrow2);
	}



	void CPU(bool S[8], bool s1[8], bool s2[8], bool z[8])
	{
		try
		{
		if (S[0] == 0 && S[1] == 0 && S[2] == 0 && S[3] == 0 && S[4] == 0 && S[5] == 0 && S[6] == 0 && S[7] == 0)
		{ for (int i = 0; i < 8; i++) { z[i] = s1[i]; }	}
		else if (S[0] == 0 && S[1] == 0 && S[2] == 0 && S[3] == 0 && S[4] == 0 && S[5] == 0 && S[6] == 0 && S[7] == 1)
		{ for (int i = 0; i < 8; i++) { z[i] = s2[i]; }	}
		else if (S[0] == 0 && S[1] == 0 && S[2] == 0 && S[3] == 0 && S[4] == 0 && S[5] == 0 && S[6] == 1 && S[7] == 0)
		{ Adder(s1, s2, true, z); }
		else if (S[0] == 0 && S[1] == 0 && S[2] == 0 && S[3] == 0 && S[4] == 0 && S[5] == 0 && S[6] == 1 && S[7] == 1)
		{ Adder(s1, s2, false, z); }
		else if (S[0] == 0 && S[1] == 0 && S[2] == 0 && S[3] == 0 && S[4] == 0 && S[5] == 1 && S[6] == 0 && S[7] == 0) 
		{ for (int i = 0; i < 8; i++) { z[i] = and_gate(s1[i], s2[i]); } }
		else if (S[0] == 0 && S[1] == 0 && S[2] == 0 && S[3] == 0 && S[4] == 0 && S[5] == 1 && S[6] == 0 && S[7] == 1)
		{ for (int i = 0; i < 8; i++) { z[i] = or_gate(s1[i], s2[i]); } }
		else if (S[0] == 0 && S[1] == 0 && S[2] == 0 && S[3] == 0 && S[4] == 0 && S[5] == 1 && S[6] == 1 && S[7] == 0)
		{ for (int i = 0; i < 8; i++) { z[i] = not_gate(s1[i]); } }
		else if (S[0] == 0 && S[1] == 0 && S[2] == 0 && S[3] == 0 && S[4] == 0 && S[5] == 1 && S[6] == 1 && S[7] == 1)
		{ for (int i = 0; i < 8; i++) { z[i] = not_gate(s2[i]); } }
		else if (S[0] == 0 && S[1] == 0 && S[2] == 0 && S[3] == 0 && S[4] == 1 && S[5] == 0 && S[6] == 0 && S[7] == 0)
		{ for (int i = 0; i < 8; i++) { z[i] = buffer_gate(s1[i]); } }
		else if (S[0] == 0 && S[1] == 0 && S[2] == 0 && S[3] == 0 && S[4] == 1 && S[5] == 0 && S[6] == 0 && S[7] == 1)
		{ for (int i = 0; i < 8; i++) { z[i] = buffer_gate(s2[i]); } }
		else if (S[0] == 0 && S[1] == 0 && S[2] == 0 && S[3] == 0 && S[4] == 1 && S[5] == 0 && S[6] == 1 && S[7] == 0)
		{ for (int i = 0; i < 8; i++) { z[i] = nand_gate(s1[i], s2[i]); } }
		else if (S[0] == 0 && S[1] == 0 && S[2] == 0 && S[3] == 0 && S[4] == 1 && S[5] == 0 && S[6] == 1 && S[7] == 1)
		{ for (int i = 0; i < 8; i++) { z[i] = nor_gate(s1[i], s2[i]); } }
		else if (S[0] == 0 && S[1] == 0 && S[2] == 0 && S[3] == 0 && S[4] == 1 && S[5] == 1 && S[6] == 0 && S[7] == 0)
		{ for (int i = 0; i < 8; i++) { z[i] = xor_gate(s1[i], s2[i]); } }
		else if (S[0] == 0 && S[1] == 0 && S[2] == 0 && S[3] == 0 && S[4] == 1 && S[5] == 1 && S[6] == 0 && S[7] == 1)
		{ for (int i = 0; i < 8; i++) { z[i] =	Latch(s1, s2); } }
		else if (S[0] == 0 && S[1] == 0 && S[2] == 0 && S[3] == 0 && S[4] == 1 && S[5] == 1 && S[6] == 1 && S[7] == 0)
		{ Subtraction(s1, s2, true, z); }
		else if (S[0] == 0 && S[1] == 0 && S[2] == 0 && S[3] == 0 && S[4] == 1 && S[5] == 1 && S[6] == 1 && S[7] == 1)
		{ Subtraction(s1, s2, false, z); }
		else if (S[0] == 0 && S[1] == 0 && S[2] == 0 && S[3] == 1 && S[4] == 0 && S[5] == 0 && S[6] == 0 && S[7] == 0)
		{ Multiplexer(s1, s2, true, z); }
		else if (S[0] == 0 && S[1] == 0 && S[2] == 0 && S[3] == 1 && S[4] == 0 && S[5] == 0 && S[6] == 0 && S[7] == 1)
		{ Multiplexer(s1, s2, false, z); }
		else { for (int i = 0; i < 8; i++) { z[i] = 1; } }
		}

		catch (const std::out_of_range& e) {
			std::cerr << "Array index out of range: " << e.what() << std::endl;
		}

		catch (const std::logic_error& e) {
			std::cerr << "Logic error: " << e.what() << std::endl;
		}

		catch (const std::runtime_error& e) {
			std::cerr << "Runtime error: " << e.what() << std::endl;
		}

		catch (const std::exception& e) {
			std::cerr << "An error occurred: " << e.what() << std::endl;
		}

		catch (...) {
			std::cerr << "An unknown error occurred." << std::endl;
		}
	}
};

#endif
