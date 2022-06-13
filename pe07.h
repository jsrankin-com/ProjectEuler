//https://projecteuler.net/problem=7
/*
By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
What is the 10 001st prime number?
*/

/*
	CheckIfPrime(primes, counter) is from question 5!
*/

long long PrimeAtIndex(long long index) {
	std::vector<long long> primes;
	long long counter = 1;
	bool isPrime;

	primes.push_back(2);

	//loop until prime is found
	while (primes.size() < index) {
		counter += 2;

		if (CheckIfPrime(primes, counter)) {
			primes.push_back(counter);
		}
	}

	return primes.back();
}
