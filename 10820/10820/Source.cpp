#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

typedef long long int ll;

ll totients[50001];



ll getTotient(ll i)
{

	if (i == 1) return 1ll;

	ll res = i;

	/* Check for divisibility by every prime number below the square root. */
	/* Start with 2. */
	if (i % 2 == 0)
	{
		res -= res / 2;
		do
		{
			i /= 2;
		}
		while (i % 2 == 0);
	}

	/* Since this doesn't use a list of primes, check every odd number. Ideally, skip past composite numbers.*/
	for (int j = 3; j*j <= i; j += 2)
	{
		if (i % j == 0)
		{
			res -= res / j;
			do {
				i /= j;
			} 
			while (i % j == 0);
		}
	}

	/* If i>1, then it's the last factor at this point. */
	if (i > 1) res -= res / i;

	/* Return the result. */
	return res;
}

ll getAnswer(ll i)
{
	if (i == 1) return 1;
	else return getAnswer(i - 1) + 2 * getTotient(i);
}

int main ()
{
	ll input;
	while (cin >> input && input != 0)
	{
		cout << getAnswer(input) << endl;
	}


	return 0;
}