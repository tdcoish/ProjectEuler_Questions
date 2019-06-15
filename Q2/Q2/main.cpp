/**********************************************************************************************
Each new term in the Fibonacci sequence is generated by adding the previous two terms. By starting with 1 and 2, the first 10 terms will be:

1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...

By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.

Note: They don't really word these questions very well.
Also, I'm saving to a text file.
**********************************************************************************************/

#include <iostream>
#include <fstream>

int main()
{
	// int wrapping would bite us, just easier to use a long
	// oh you know what, it's actually 2.147 billion, not million. Of course.
	int								sum = 0;
	int								num = 1;
	int								prevNum = 0;
	while (num < 4000000) {
		int temp = num;
		num = prevNum + num;
		prevNum = temp;

		if (num % 2 == 0) {
			sum += num;
		}
	}

	std::cout << "Sum: " << sum;
	std::getchar();

	std::ofstream file;
	file.open("sum.txt");
	file << "Even Fibonacci's: " << sum;
	return 0;
}