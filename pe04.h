//https://projecteuler.net/problem=4
/*
 * A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 x 99.
 * Find the largest palindrome made from the product of two 3-digit numbers.
*/


bool IsPalindromicString(long long n)
{
	//Convert to positive
	if (n < 0)
	{
		n = -n;
	}

	std::string str = std::to_string(n);
	int length = str.length();

	for (int i = 0; i < (length / 2); ++i)
	{
		if (str[i] != str[length - i - 1])
			return false;
	}

	return true;
}

bool IsPalindromicNumber(long long n)
{
	//Convert to positive
	if (n < 0)
	{
		n = -n;
	}

	long long og = n;
	int reversed = 0;

	while (n > 0) {
		reversed *= 10;
		reversed += n % 10;
		n /= 10;
	}

	return reversed == og;
}


long long LargestPalindromicNumber(long long low, long long high)
{
	long long found = 0;

		for (long long lhs = high; low < lhs; --lhs)
		{
			//Stop checking if results will be less than found
			if ((lhs * lhs) < found)
			{
				return found;
			}
			for (long long rhs = lhs; low < rhs; --rhs)
			{
				if (IsPalindromicNumber(lhs * rhs))
				{
					if (found < (lhs * rhs))
					{
						found = lhs * rhs;
					}
				}
			}
		}
	
	return found;
}
