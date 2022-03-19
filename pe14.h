#pragma once
#include <vector>

//https://projecteuler.net/problem=14
/*
The following iterative sequence is defined for the set of positive integers:

n -> n/2 (n is even)
n -> 3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:

13 -> 40 -> 20 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1
It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain?

NOTE: Once the chain starts the terms are allowed to go above one million.
*/

long long LongestCollatzSequence(long long high)
{
	//Memoization
	std::vector<long long> cache(high+1);
	long long largest = 0;
	long long seed = 0;
	long long sequence;

	cache[1] = 1;

	for (long long i = 2; i <= high; ++i) {
		sequence = i;
		long long counter = 0;

		//if sequence is less than i then it must be in the chache
		while (i <= sequence) {
			++counter;
			//even or odd
			if ((sequence % 2) == 0) 
				sequence /= 2;
			else 
				sequence = sequence * 3 + 1;
		}
		//Store result in cache
		cache[i] = cache[sequence] + counter;

		//Check if sequence is the best solution
		if (cache[i] > largest) {
			largest = cache[i];
			seed = i;
		}
	}

	return seed;
}
