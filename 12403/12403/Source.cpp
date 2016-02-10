#include <iostream>
#include <string>
using namespace std;

int main ()
{
	long sum = 0;
	int ops;
	long inp;
	string op;
	cin >> ops;
	while (ops--)
	{
		cin >> op;
		if (op == "donate")
		{
			cin >> inp;
			sum += inp;
		}
		else cout << sum << endl;
	}

	return 0;
}