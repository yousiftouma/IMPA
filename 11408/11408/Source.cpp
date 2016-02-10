#include <iostream>
#include <math.h>
using namespace std;

#define n 5000001
int isPrime[n];
int primeFactSum[n];


void sieve()
{
	for (int i = 2; i < n; i++)
	{
		if (isPrime[i] == 1)
		{
			primeFactSum[i] += i;
				for (int j = 2*i; j < n; j += i)
				{
					isPrime[j] = 0;
					primeFactSum[j] += i;

				}
			
		}
	}
}

int main ()
{
	for (int i = 0; i < n; i++)
	{
		isPrime[i] = 1;
		primeFactSum[i] = 0;
	}
	isPrime[0] = 0;
	isPrime[1] = 0;
	
	sieve();

	int a, b;
	while(cin >> a)
	{
		if (a == 0) break;
		else cin >> b;
		int res = 0;
		for (int i = a; i <= b; i++)
		{
			if (isPrime[primeFactSum[i]]) res++;
		}
		cout << res << endl;
	}

	return 0;
}