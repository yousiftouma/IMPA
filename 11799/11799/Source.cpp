#include <iostream>
#include <set>
using namespace std;

int main ()
{
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++)
	{
		set<int> speeds;
		int speed;
		int runners;
		cin >> runners;
		while(runners--)
		{
			cin >> speed;
			speeds.insert(speed);
		}
		int ans = *speeds.rbegin();
		cout << "Case " << i << ": " << ans << endl;
	}


	return 0;
}