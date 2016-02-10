#include <iostream>
using namespace std;

int main()
{
	bool firstRun = true;
	int k;
	while (cin >> k && k != 0) {
		int subset[13];
		if (!firstRun) {
			cout << endl;
		}
		else firstRun = false;

		for (int i = 0; i < k; i++)
		{
			cin >> subset[i];
		}

		for (int a = 0; k - a > 5; a++)
		{
			for (int b = a + 1; k - b > 4; b++)
			{
				for (int c = b + 1; k - c > 3; c++)
				{
					for (int d = c + 1; k - d > 2; d++)
					{
						for (int e = d + 1; k - e > 1; e++)
						{
							for (int f = e + 1; k - f > 0; f++)
							{
								cout << subset[a] << " " << subset[b] 
									<< " " << subset[c] << " " << subset[d] << 
									" " << subset[e] << " " << subset[f] << endl;
							}
						}
					}
				}
			}
		}


	}

	return 0;
}