#include <iostream>
#include <algorithm>
using namespace std;

int main ()
{
	int a, b, c;

	while (cin >> a >> b >> c)
	{
		if (a + b + c == 0) break;
		if (a > c) swap(a, c);
		if (b > c) swap(b, c);
		if (a*a + b*b == c*c) cout << "right" << endl;
		else cout << "wrong" << endl;
	}



	return 0;
}