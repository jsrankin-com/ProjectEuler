//https://projecteuler.net/problem=15
/*
Starting in the top left corner of a 2x2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.
How many such routes are there through a 20x20 grid?
*/

long long Routes(long long high)
{
	const int gridSize = high;
	long long paths = 1;

	for (long long i = 0; i < gridSize; ++i) {
		paths *= (2 * gridSize) - i;
		paths /= i + 1;
	}
	return paths;
}
