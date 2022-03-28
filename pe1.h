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

	//Implicit cast
	for (int c : n)
	{
		total += c;
	}

	return total;
}

int MultiplesOfThreeAndFiveAlternate(int low, int high)
{
	int total = 0;
	std::string low_str;
	while (low <= high)
	{
		low_str = std::to_string(low);
		if (low_str.back() == '5' || low_str.back() == '0'))
		{
			total += low;
		}
		else if (SumDigits(low_str) % 3 == 0)
		{
			total += low;
		}

		++low;
	}
	return total;
};

long long MultiplesOfThreeAndFiveOptimized(int low, int high)
{
	long long total = 0;
	long long threes = 3;
	long long fives = 5;


	//Handle starting vaue greater than 3
	if (low > 3)
	{
		if (low % 3 == 0)
		{
			threes = low;
		}
		else
		{
			threes = low + (3-(low % 3));
		}
	}

	//Handle starting vaue greater than 5
	if (low > 5)
	{
		if (low % 5 == 0)
		{
			fives = low;
		}
		else
		{
			fives = low + (5 - (low % 5));
		}
	}

	while (fives <= high)
	{
		total += fives;
		fives += 5;
		
	}
	while (threes <= high)
	{
		//Already added if 5 is a factor
		if (threes % 5 != 0)
			total += threes;
		threes += 3;
	}

	return total;
};
