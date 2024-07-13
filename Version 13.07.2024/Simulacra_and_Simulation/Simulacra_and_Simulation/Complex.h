#include <iostream>

class Complex {

private:
	double real;
	double imag;

public:
	Complex(double r, double i) : real(r), imag(i) {}

	double getReal() const {
		return real;
	}

	double getImaginary() const {
		return imag;
	}

	Complex  operator+(const Complex & other) const {
		return Complex(real + other.real, imag + other.imag);
	}

	Complex  operator-(const Complex & other) const {
		return Complex(real - other.real, imag - other.imag);
	}

	void print() const {
		std::cout << real << " + " << imag << "i" << std::endl;
	}
};
