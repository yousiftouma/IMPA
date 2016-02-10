#include <iostream>
using namespace std;

int main()
{
	int a;
	int ccase = 1;
	while (cin >> a) {
		if (a == 0) break;
		int should = 0; int has = 0;
		int inp;
		while (a--)
		{
			cin >> inp;
			if (inp == 0) has++;
			else should++;
		}
		cout << "Case " << ccase << ": " << should - has << endl;
		ccase++;
	}




	return 0;
}