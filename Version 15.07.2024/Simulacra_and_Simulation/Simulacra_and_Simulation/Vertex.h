#include <iostream>
#include <vector>

const int WIDTH = 120;
const int HEIGHT = 50;

class Vertex
{

public:
	struct V {
		int x, y;

		V(int x, int y) : x(x), y(y) {}
	};

	void drawGraph(const std::vector<V>& vertices) {
		char screen[HEIGHT][WIDTH];
		for (int i = 0; i < HEIGHT; ++i) {
			for (int j = 0; j < WIDTH; ++j) {
				screen[i][j] = ' ';
			}
		}

		for (const V& v : vertices) {
			if (v.x >= 0 && v.x < WIDTH && v.y >= 0 && v.y < HEIGHT) {
				screen[v.y][v.x] = '#';
			}
		}

		for (int i = 0; i < HEIGHT; ++i) {
			for (int j = 0; j < WIDTH; ++j) {
				std::cout << screen[i][j];
			}
			std::cout << std::endl;
		}
	}
};
