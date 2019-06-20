/******************************************************************************************************
The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.
******************************************************************************************************/

#include <iostream>

bool IsPrime(int num)
{
	// simplifies code and lets me write the more optimized for loop below
	if (num <= 1)
		return false;
	if (num <= 3)
		return true;
	if (num % 2 == 0)
		return false;

	// More optimized prime function. Should work at 4x the speed.
	for (int i = 3; i < (num/2 + 1); i+=2) {
		if (num%i == 0)
			return false;
	}

	return true;
}

int main()
{

	unsigned long long sum = 0;
	for (int i = 0; i < 2000000; i++) {
		if (IsPrime(i))
			sum += i;
	}

	std::cout << sum;
	std::getchar();

	return 0;
}