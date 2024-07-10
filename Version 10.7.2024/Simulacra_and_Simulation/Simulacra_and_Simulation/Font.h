#include <windows.h>
#include <iostream>

class Font
{
public:
	void ChangeConsoleFont(const wchar_t* fontName, SHORT fontSize) {
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		if (hConsole == INVALID_HANDLE_VALUE) {
			std::cerr << " Font Failure." << std::endl;
			return;
		}

		CONSOLE_FONT_INFOEX cfi;
		cfi.cbSize = sizeof(cfi);
		cfi.nFont = 0;
		cfi.dwFontSize.X = 0;
		cfi.dwFontSize.Y = fontSize;
		cfi.FontFamily = FF_DONTCARE;
		cfi.FontWeight = FW_NORMAL;
		wcscpy_s(cfi.FaceName, fontName);

		if (!SetCurrentConsoleFontEx(hConsole, FALSE, &cfi)) {
			std::cerr << " Not changed a font." << std::endl;
		}
	}
};

