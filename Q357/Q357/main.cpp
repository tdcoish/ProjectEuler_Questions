/********************************************************************
Consider the divisors of 30: 1,2,3,5,6,10,15,30.
It can be seen that for every divisor d of 30, d+30/d is prime.

Find the sum of all positive integers n not exceeding 100 000 000
such that for every divisor d of n, d+n/d is prime.

NOTE: Yet again, writing an IsPrime() function.

Huh, what if we first precomputed a whole bunch of primes, then we just checked
if our prime was in there, since we're recalculating primes a whole bunch of times.

That could really save a lot of time.
*******************************************************************/


#include <fstream>
#include <math.h>

bool IsPrime(int num)
{
	if (num <= 1)
		return false;
	if (num <= 3)
		return true;

	// so I can skip over testing all the even numbers in the for loop
	if (num % 2 == 0)
		return false;

	// sqrt optimization, because rt(num) * rt(num) == num, so we don't have to test any nums higher than that, we should have already "caught" it.
	int sqrt = sqrtf((float)num);
	for (int i = 3; i < sqrt+1; i+=2) {
		if(num%i == 0)
			return false;
	}

	return true;
}

// first we have to find the divisors
bool AllDivisorsPrime(int num)
{
	// we can skip over all of the numbers that are greater than half our num,
	// so for instance, if we're doing 30, we can test 1-14, then just skip over 15-30
	// in fact, this might work for a lot of numbers. I sort of feel on to something.
	// we could also skip testing 11-14.
	if (!IsPrime(num + (num / num))) {
		return false;
	}

	// you know, this would actually be faster if we went the other direction
	for (int i = 1; i < num/2 + 1; i++)
	{
		if (num%i == 0)
			if (!IsPrime(i + (num / i))) {
				return false;
			}
	}

	return true;
}

int main()
{

	// basically, just cheating, since it's true for 1.
	long long sum = 1;

	// we can skip all the odd numbers, since they will always fail the test
	for (int i = 2; i < 100000000; i+=2) {
		if (AllDivisorsPrime(i)) {
			//std::cout << "i: " << i << std::endl;
			sum += i; 
		}
	}

	std::ofstream file;
	file.open("Sum.txt");
	file << "SUM: " << sum;
	file.close();

	return 0;
}
