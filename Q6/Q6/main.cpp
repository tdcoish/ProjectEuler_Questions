/**********************************************************************************************
The sum of the squares of the first ten natural numbers is,

12 + 22 + ... + 102 = 385		// note, that's supposed to be 1^2 + 2^2 ... 10^2
The square of the sum of the first ten natural numbers is,

(1 + 2 + ... + 10)^2 = 552 = 3025
Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.

Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
************************************************************************************************/

#include <fstream>

int main()
{
	int	sumOfSquares = 0;
	int	squareOfSum = 0;

	for (int i = 1; i < 101; i++) {
		sumOfSquares += i * i;
		squareOfSum += i;
	}

	squareOfSum *= squareOfSum;

	int	dif = sumOfSquares - squareOfSum;

	std::ofstream file;
	file.open("dif.txt");
	file << "Difference between sum of squares and square of sum 1-100: " << dif;
	file.close();

	return 0;
}