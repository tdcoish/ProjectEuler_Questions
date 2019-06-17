/**************************************************************************************************************
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.

Note: Let's try the brute force solution first. Just crank through every damn possible number.
**************************************************************************************************************/

#include <iostream>


// means that start digit is equal to end digit, and so on and so forth.
bool IsPalindrome(int num)
{
	// new plan, just shove it into an array chopping the number off by 10 each time.
	int nums[32];
	for (int i = 0; i < 32; i++) {
		nums[i] = 0;
	}

	int ind = 0;
	while (num>0) {
		nums[ind] = num % 10;
		ind++;
		num /= 10;
	}

	for (int i = 0; i < ind; i++) {
		if (nums[i] != nums[ind - i - 1])
			return false;
	}

	return true;
}

int main()
{
	int largestPally = 0;
	
	int res;
	for (int i = 100; i < 1000; i++) {
		for (int j = 100; j < 1000; j++) {
			res = i * j;
			if (IsPalindrome(res)) {
				if (res > largestPally) {
					largestPally = res;
				}
			}
		}
	}

	std::cout << "Largest Palindrome: " << largestPally << std::endl;

	std::getchar();
	
}