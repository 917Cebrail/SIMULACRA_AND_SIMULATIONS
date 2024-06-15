#include <iostream>
#include <random>
#include "Quick_Sorting.h"

using namespace std;

class Sorting_Algorihitms
{
public:
	void Quick_Sort(int start, int end)
	{
		Quick_Sorting quick;
		int _array[10];
		srand(time(0));

		for (int i = 0; i < 10; i++) {
			_array[i] = rand() % 100; // Random number between 0 and 99
		}

		std::cout << "Unsorted array: ";
		for (int i = 0; i < 10; i++) {
			std::cout << _array[i] << " ";
		}
		std::cout << std::endl;

		quick.Quick_Sort(_array, 0, 9);

		std::cout << "Sorted array: ";
		for (int i = 0; i < 10; i++) {
			std::cout << _array[i] << " ";
		}
		std::cout << std::endl;

	}
};

