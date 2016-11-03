#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int l, h, r;
	int max = 0;
	int min = 10001;
	int heights[10001];
	fill(heights, heights + 10001, 0);
	vector<int> result;
	while (cin >> l >> h >> r)
	{
		if (cin.eof()) break;
		for (int i = l; i < r; i++)
		{
			if (heights[i] < h)
			{
				heights[i] = h;
			}
			if (r > max) max = r;
			if (l < min) min = l;
		}
	}
	// printing loop
	int prev = 0;
	for (int i = min; i < max; i++)
	{
		if (prev != heights[i])
		{
			// some change in height has happened
			// print the coord the change happens and where it goes
			cout << i << " " << heights[i] << " ";
			prev = heights[i];
		}
	}
	cout << max << " " << 0 << "\n";



	return 0;
}