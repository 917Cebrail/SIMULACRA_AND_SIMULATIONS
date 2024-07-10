#include <iostream>
#include <cstdlib>
#include <ctime>

class Quick_Sorting
{
		void swap(int& a, int& b) {
		int temp = a;
		a = b;
		b = temp;
	}

	int partition(int array[], int low, int high) {
		int pivot = array[high];
		int i = (low - 1);

		for (int j = low; j <= high - 1; j++) {
			if (array[j] <= pivot) {
				i++;
				swap(array[i], array[j]);
			}
		}
		swap(array[i + 1], array[high]);
		return (i + 1);
	}
public:

	void Quick_Sort(int array[], int low, int high) {
		if (low < high) {
			int pi = partition(array, low, high);
			Quick_Sort(array, low, pi - 1);
			Quick_Sort(array, pi + 1, high);
		}
	}
};

