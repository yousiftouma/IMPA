#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int n = 32768;
int isPrime[32768];
vector<int> primes;

/*
 Eratosthenes sieve
*/
void sieve()
{
	int i, j;
	for (i = 0;i<n;i++)
		isPrime[i] = 1; // we initialize the sieve list to all 1's (True)
	isPrime[0] = 0, isPrime[1] = 0; // Set the first two numbers (0 and 1) to 0 (False)
	for (i = 2;i<sqrt(n);i++) // loop through all the numbers up to the sqrt(n)
		if (isPrime[i]) {
			for (j = i*i;j < n;j += i) // mark off each factor of i by setting it to 0 (False)
				isPrime[j] = 0;
		}
	for (i = 2; i <= n; ++i)
	{
		if (isPrime[i] == 1)
		{
			primes.push_back(i);
		}
	}
}

int main()
{
	sieve();
	int input;
	while (cin >> input && input != 0)
	{
		auto count = 0;
		for (auto prime : primes)
		{
			if (prime > input / 2) break;
			if (isPrime[input - prime] == 1) ++count;
		}
		cout << count << endl;
	}

	return 0;
}