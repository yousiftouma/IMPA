#include <iostream>
using namespace std;

int main()
{
	int x = -1;
	if (x < 0)
		cout << "x was negative" << endl;
		x = -x;
	cout << x << endl;
	return 0;
}