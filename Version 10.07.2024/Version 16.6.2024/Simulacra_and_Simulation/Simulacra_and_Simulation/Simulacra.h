#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

class Simulacra
{
public:
	void Main()
	{
		std::cout << " Enter a file name : ";
		std::string _path;
		std::cin >> _path;
		std::vector<std::vector<int>> city = readCityFromFile(_path);
		displayCity(city);
	}

private:
	std::vector<std::vector<int>> readCityFromFile(const std::string& filename)
	{
		std::vector<std::vector<int>> city;
		std::ifstream file(filename);

		if (!file) {
			std::cerr << "Unable to open file " << filename << std::endl;
			return city;
		}

		std::string line;
		while (std::getline(file, line)) {
			std::vector<int> row;
			std::istringstream stream(line);
			std::string value;
			while (std::getline(stream, value, ',')) {
				row.push_back(std::stoi(value));
			}
			city.push_back(row);
		}

		file.close();
		return city;
	}

	void displayCity(const std::vector<std::vector<int>>& city)
	{
		for (const auto& row : city) {
			for (const auto& cell : row) {
				if (cell == 1) {
					std::cout << '#';
				}
				else if (cell == 2) {
					std::cout << '-';
				}
				else if (cell == 3) {
					std::cout << ']';
				}
				else if (cell == 0) {
					std::cout << '|';
				}
				else {
					std::cout << std::endl;
				}
			}
			std::cout << std::endl;
		}
	}
};

