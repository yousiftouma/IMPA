#include <iostream>
using namespace std;


int main ()
{
	int n;
	while (cin >> n)
	{
		if (n == 0) break;
		auto result = 0;
		for (int i = 1; i <= n; i++)
		{
			result += i*i;
		}

		cout << result << endl;
	}

	return 0;
}

