//https://projecteuler.net/problem=2
/*
 * Each new term in the Fibonacci sequence is generated by adding the previous two terms. By starting with 1 and 2, the first 10 terms will be:
 * 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
 * By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.
*/

long long Fibonacci(long long n)
{
	return n < 2 ? n : Fibonacci(n - 1) + Fibonacci(n - 2);
};

long long SumEvenFibonacciNumbers(long long high)
{
	long long total = 0;
	long long f = 2;
	for (long long i = 3; f < high; ++i)
	{
		f = Fibonacci(i);
		if (f % 2 == 0)
		{
			total += f;

		}
	}
	return total;
}

long long SumEvenFibonacciNumbersOptimized(long long high)
{
	long long total = 0;
	long long f = 2;

	//Sequence pattern OOD, ODD, EVEN,...
	long long offset = 3;

	for (long long i = 3; f < high; ++i)
	{
		f = Fibonacci(i);

		if (i == offset)
		{
			total += f;
			offset += 3;
		}

	}
	return total;
}
