//https://projecteuler.net/problem=6
/*
*
* Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
*
*/

long long SumOfSquares(long long high)
{
	return (((high * (high + 1)) * ((2 * high) + 1)) / 6);
}

long long SquareOfSum(long long high)
{
	return high * (high + 1) / 2;
}

long long SumSquareDifference(long long high)
{
	return (high < 0) ? 0 : std::pow(SquareOfSum(high), 2) - SumOfSquares(high);
}
