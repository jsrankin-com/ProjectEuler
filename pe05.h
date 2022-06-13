//https://projecteuler.net/problem=5
/*
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
*/

bool CheckIfPrime(std::vector<long long>& primes, long long n)
{
	bool isPrime = true;

	for (int i = 0; (primes[i] * primes[i]) <= n; ++i) {
		if (n % primes[i] == 0) {
			isPrime = false;
			break;
		}
	}
	return isPrime;
}


std::vector<long long> GeneratePrimes(int limit) {
	std::vector<long long> primes;
	bool isPrime;

	primes.push_back(2);

	for (int i = 3; i <= limit; i += 2) {
		if (CheckIfPrime(primes, i)) {
			primes.push_back(i);
		}
	}

	return primes;
}

long long Divisility(long long high)
{
	std::vector<long long> v = GeneratePrimes(high);
	long long answer = 1;
	for (int i = 0; i < v.size(); i++)
	{
		long long a = floor(log(high) / log(v[i]));
		answer *= std::pow(v[i], a);
	}

	return answer;
}
