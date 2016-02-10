#include <iostream>
#include <string>
using namespace std;

int main ()
{
	int h, u, d, f;
	string suc = "success on day ";
	string fail = "failure on day ";

	while (cin >> h >> u >> d >> f)
	{
		if (h == 0) break;
		int day = 0;
		double height = h;
		double down = d;
		double up = u;
		double fatigue = f / 100.0 * up;
		double curr = 0.0;

		while (true)
		{
			day++;
			curr += up;
			if (curr > height) {
				cout << suc << day << endl;;
				break;
			}
			curr -= down;
			if (curr < 0.0)
			{
				cout << fail << day << endl;
				break;
			}
			up -= fatigue;
			if (up < 0) up = 0;
		} 	
	}
	return 0;
}