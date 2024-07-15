#ifndef TUI_H
#define TUI_H

#include <iostream>
#include <vector>
#include <string>

class Window {
public:
	Window(int width, int height, int startx, int starty);
	~Window();

	void draw_box();
	void print(int x, int y, const std::string &str);
	void refresh();
	void clear();

	int getch();

private:
	int width, height, startx, starty;
	std::vector<std::string> buffer;

	void move_cursor(int x, int y);
	void clear_line(int line);
};

#endif // TUI_H
