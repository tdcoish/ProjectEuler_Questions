/*************************************************************************************************
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

Note: Evenly divisible means no remainder when divided by.
*************************************************************************************************/

#include <fstream>

bool EvenlyDivisible(int num)
{
	for (int i = 1; i < 21; i++) {
		if (num%i != 0)
			return false;
	}

	return true;
}

int main()
{
	int testNum = 20;

	while (true) {
		if (EvenlyDivisible(testNum)) {
			std::ofstream file;
			file.open("num.txt");
			file << "First num evenly divisible by 1-20: " << testNum;
			file.close();
			break;
		}

		testNum++;
	}

	return 0;
}