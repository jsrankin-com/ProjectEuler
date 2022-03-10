//https://projecteuler.net/problem=1
/*
 * If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
 * Find the sum of all the multiples of 3 or 5 below 1000.
*/
int SumMultiplesOfThreeAndFive(int low, int high)
{
	int total = 0;
	while (low <= high)
	{
		if (low % 3 == 0)
		{
			total += low;
		}
		else if (low % 5 == 0)
		{
			total += low;
		}

		++low;
	}
	return total;
};
