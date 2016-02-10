#include <iostream>
using namespace std;

int main ()
{
	int T, students;
	cin >> T;
	while (T--)
	{
		cin >> students;
		int curr, max, best_diff = -100000;
		cin >> max;
		students--;
		while (students--)
		{
			cin >> curr;
			if ((max - curr) > best_diff)
			{
				best_diff = max - curr;
			}
			if (curr > max) max = curr;
		}
		cout << best_diff << endl;
	}



	return 0;
}