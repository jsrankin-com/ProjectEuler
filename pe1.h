#pragma once
#include <string>

//https://projecteuler.net/problem=1
/*
 * If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
 * Find the sum of all the multiples of 3 or 5 below 1000.
*/
int SumMultiplesOfThreeAndFive(int low, int high)
{
	int total = 0;
	while (low < high)
	{
		if (low % 3 == 0 || low % 5 == 0)
		{
			total += low;
		}

		++low;
	}
	return total;
};

int SumDigits(std::string n)
{

	int total = 0;

	for (char c : n)
	{
		total += static_cast<int>(c);
	}

	return total;
}

int OptimizedMultiplesOfThreeAndFive(int low, int high)
{
	int total = 0;
	std::string low_str;
	while (low <= high)
	{
		low_str = std::to_string(low);
		if (SumDigits(low_str) % 3 == 0)
		{
			std::cout << "Multiple of 3: " << low << std::endl;
			total += low;
		}
		else if (low_str.back() == '5' || low_str.back() == '0')
		{
			std::cout << "Multiple of 5: " << low << std::endl;
			total += low;
		}

		++low;
	}
	return total;
};
