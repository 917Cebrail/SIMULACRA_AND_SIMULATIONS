#ifndef HDD_H
#define HDD_H

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

void HDD();
std::vector<std::vector<int>> readDataFromFile(const std::string& filename);
void displayData(const std::vector<std::vector<int>>& city);

void HDD()
{
	std::cout << " Enter a file name : ";
	std::string _path;
	std::cin >> _path;
	std::vector<std::vector<int>> city = readDataFromFile(_path);
	displayData(city);
}

std::vector<std::vector<int>> readDataFromFile(const std::string& filename)
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
		while (std::getline(stream, value, '-')) {
			row.push_back(std::stoi(value));
		}
		city.push_back(row);
	}
	file.close();
	return city;
}

void displayData(const std::vector<std::vector<int>>& city)
{
	char alpha[25] = { 'A', 'B' , 'C' , 'D' , 'E' , 'F' , 'G' , 'H' , 'I' , 'J' , 'K' ,
		'L' , 'M' , 'N' , 'O' , 'P' , 'Q' , 'R' , 'S' , 'T' , 'U' , 'V' , 'W' , 'Z' , 'X' };

	for (const auto& row : city) {
		for (const auto& cell : row) {
			if (cell < 0 || cell > 25) {
				std::cout << 'A';
			}
			else {
				std::cout << alpha[cell];
			}
		}
		std::cout << std::endl;
	}
}

#endif