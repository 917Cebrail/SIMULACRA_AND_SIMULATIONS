#include <iostream>
#include <cmath>
#include <cstring>
#include <windows.h>

class Donut
{
public:
	void render_frame(float A, float B) {
		const int width = 80;
		const int height = 22;
		const int size = width * height;
		const float pi = 3.14159265358979323846;
		char output[size];
		float zBuffer[size];

		std::fill_n(output, size, ' ');
		std::fill_n(zBuffer, size, 0);

		for (float theta = 0; theta < 2 * pi; theta += 0.07) {
			for (float phi = 0; phi < 2 * pi; phi += 0.02) {
				float sinTheta = std::sin(theta);
				float cosTheta = std::cos(theta);
				float sinPhi = std::sin(phi);
				float cosPhi = std::cos(phi);
				float cosA = std::cos(A);
				float sinA = std::sin(A);
				float cosB = std::cos(B);
				float sinB = std::sin(B);

				float circleX = cosTheta;
				float circleY = sinTheta * cosPhi + cosA * sinPhi;
				float circleZ = sinTheta * sinPhi - cosA * cosPhi;
				float Z = 1 / (circleZ + 2);
				float X = (circleX * cosB + circleY * sinB) * Z;
				float Y = (circleX * sinB - circleY * cosB) * Z;
				int x = width / 2 + (int)(width * X / 2);
				int y = height / 2 - (int)(height * Y / 2);
				int idx = x + width * y;
				if (idx >= 0 && idx < size && Z > zBuffer[idx]) {
					zBuffer[idx] = Z;
					int luminance_index = (int)(8 * ((cosPhi * sinTheta - sinPhi * cosTheta * cosA - cosTheta * sinA) / 2 + 0.5));
					const char* luminance_chars = ".,-~:;=!*#$@";
					output[idx] = luminance_chars[luminance_index];
				}
			}
		}

		std::cout << "\x1b[H";
		for (int k = 0; k < size; k++) {
			std::cout << (k % width ? output[k] : '\n');
		}
	}
	void set_console_size(int width, int height) {
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		if (hConsole == INVALID_HANDLE_VALUE) {
			std::cerr << "Error getting console handle" << std::endl;
			return;
		}
		COORD bufferSize;
		bufferSize.X = width;
		bufferSize.Y = height;
		if (!SetConsoleScreenBufferSize(hConsole, bufferSize)) {
			std::cerr << "Error setting screen buffer size" << std::endl;
			return;
		}
		SMALL_RECT windowSize;
		windowSize.Left = 0;
		windowSize.Top = 0;
		windowSize.Right = width - 1;
		windowSize.Bottom = height - 1;
		if (!SetConsoleWindowInfo(hConsole, TRUE, &windowSize)) {
			std::cerr << "Error setting console window size" << std::endl;
			return;
		}
	}
};

