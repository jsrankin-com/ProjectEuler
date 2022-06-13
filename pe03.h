#pragma once
#include <vector>

//https://projecteuler.net/problem=3
/*
 * The prime factors of 13195 are 5, 7, 13 and 29.
 * What is the largest prime factor of the number 600851475143 ?
*/
std::vector<long long> PrimeFactor(long long high)
{
	std::vector<long long> factors;

	//hard coded detection for 2
	while ((high % 2) == 0) {
		factors.push_back(2);
		high /= 2;
	}

	//hard coded detection for 3
	while (high % 3 == 0) {
		factors.push_back(3);
		high /= 3;
	}
	//6k ± 1 optimization
	for (long long i = 5; i <= sqrt(high); i += 6) {
		while (high % i == 0) {
			factors.push_back(i);
			high /= i;
		}
		while (high % (i + 2) == 0) {
			factors.push_back(i + 2);
			high = high / (i + 2);
		}
	}

	//remainder is prime
	if (high > 4)
		factors.push_back(high);

	return factors;
}

long long LargestPrimeFactor(long long high)
{
	std::vector<long long> v = PrimeFactor(high);
	return v.back();
}
