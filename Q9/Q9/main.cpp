/******************************************************************************************

A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,

a2 + b2 = c2
For example, 32 + 42 = 9 + 16 = 25 = 52.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.

******************************************************************************************/

#include <iostream>
#include <fstream>

// a must be less than b, must be less than c
bool IsTriplet(int a, int b, int c)
{
	if (a < b && b < c) {
		int sum = a * a;
		sum += b * b;
		if (sum == c * c)
			return true;
	}

	return false;
}


int main()
{
	for (int i = 0; i < 1000; i++) {
		for (int j = i + 1; j < 1000; j++) {
			for (int u = j + 1; u < 1000; u++) {
				if (IsTriplet(i, j, u)) {
					if (i + j + u == 1000) {
						std::ofstream file;
						file.open("Nums.txt");
						file << "A: " << i << " B: " << j << " C: " << u;
						file << "\n" << "Product: " << (i*j*u);
						file.close();

						return 0;
					}
				}
			}
		}
	}

	return 0;
}