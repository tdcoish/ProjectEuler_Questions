/*************************************************************************************************
By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10 001st prime number?

NOTE: Used unsigned long long because I was paranoid. Actually gives the same result as regular int
*************************************************************************************************/

#include <iostream>
#include <fstream>

bool IsPrime(unsigned long long num)
{
	// just handling the edge cases.
	if (num <= 3) {
		return true;
	}

	for (int i = 2; i < num; i++) {
		if (num%i == 0) {
			return false;
		}
	}

	return true;
}

int main()
{
	unsigned long long numPrimes = 0;
	unsigned long long testNum = 2;
	while (true) {
		if (IsPrime(testNum)) {
			numPrimes++;
		}

		if (numPrimes == 10001) {
			std::cout << "10001 Prime: " << testNum;
			break;
		}

		testNum++;
	}


	std::getchar();
	return 0;
}

