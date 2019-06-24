/************************************************************************
Comparing two numbers written in index form like 211 and 37 is not difficult, as any calculator would confirm that 211 = 2048 < 37 = 2187.

However, confirming that 632382518061 > 519432525806 would be much more difficult, as both numbers contain over three million digits.

Using base_exp.txt (right click and 'Save Link/Target As...'), a 22K text file containing one thousand lines with a base/exponent pair on each line, determine which line number has the greatest numerical value.

NOTE: The first two lines in the file represent the numbers in the example given above.

NOTE: I had no idea what the mathematical "trick" would be, since storing the result of the calculation would be impossible. Turns out we can compare logs, and 
that gives us the same result, in terms of which is greater that is.

Actually, an easier solution could just be to 
***********************************************************************/

#include <string>
#include <fstream>
#include <iostream>

// kind of gross side effects here.
void GetNumAndExp(std::string base, int* numBase, int* pow)
{
	int indComma = 0;
	for (int i = 0; i < base.length(); i++)
	{
		if (base[i] == ',') {
			indComma = i;
		}
	}

	if (indComma == 0) {
		std::cout << "No comma found" << std::endl;
	}

	std::string sBase = base.substr(0, indComma);
	std::string sPow = base.substr((indComma + 1), (base.length() - indComma));

	// now here we convert num and exp to ints
	*numBase = std::stoi(base.substr(0, indComma));
	*pow = std::atoi(sPow.c_str());
}

int main()
{
	// alright so we have to keep reading in from the text file
	std::ifstream file;
	// std::ios::in is actually the default, so I don't really need to add it.
	file.open("p099_base_exp.txt", std::ios::in);

	int base;
	int exp;
	double bigRes = 0;
	int lineNum = 0;
	int curLine = 1;

	// this prints every line of the text file.
	std::string sLine;
	while (file.is_open())
	{
		while (getline(file, sLine))
		{
			GetNumAndExp(sLine, &base, &exp);

			double res = (double)exp * log((double)base);
			res /= 1000.0;

			if (res > bigRes) {
				bigRes = res;
				lineNum = curLine;

				std::cout << "New Leader: " << lineNum << "\n";
				std::cout << "Res: " << bigRes << "\n";
			}

			curLine++;
		}
		
		file.close();
	}

	std::cout << "Line: " << lineNum;
	std::cout << "Result: " << bigRes;

	// showing result of calc between the given numbers
	std::getchar();

	return 0;
}