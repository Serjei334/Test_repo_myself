#include <iostream>
#include <math.h>
namespace T1 {
	void ArrayInit(float array[], int size) {
		for (int i = 0; i < size; i++) {
			array[i] = (static_cast<float>(i) / 4) - 2;
		}
	}

	void ArrayPrint(float array[], int size) {
		for (int i = 0; i < size; i++) {
			std::cout << array[i] << " || ";
		}
		std::cout << std::endl;
	}

	void ArrayResults(float array[], int size) {
		int a = 0, b = 0, c = 0, d = 0;

		for (int i = 0; i < size; i++) {
			if (array[i] == 0)
				c++;
			else {
				d = static_cast<int>(fabs(array[i]) / array[i]);
				switch (d)
				{
				case 1:
					a++;
					break;
				case -1:
					b++;
					break;
				}
			}

		}
		std::cout << "Above zero = " << a << "\n" << "Below zero = " << b << "\n" << "Zero = " << c << "\n";
	}}