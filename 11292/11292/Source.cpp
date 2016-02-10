#include <iostream>
#include <set>
using namespace std;


int main()
{

	int size;
	int heads, knights;
	while (cin >> heads >> knights)
	{
		if (heads + knights == 0)
		{
			break;
		}
		else {
			multiset<int> headsizes;
			multiset<int> knightsizes;
			int res = 0;
			int kills = 0;
			while (heads > 0)
			{
				cin >> size;
				headsizes.insert(size);
				--heads;
			}
			while (knights > 0)
			{
				cin >> size;
				knightsizes.insert(size);
				--knights;
			}
			for (auto f : headsizes)
			{
				for (auto it = knightsizes.begin(); it != knightsizes.end(); ++it)
				{
					if (*it >= f)
					{
						res += *it;
						knightsizes.erase(it);
						++kills;
						break;
					}
				}
			}
			if (kills < headsizes.size())
			{

				cout << "Loowater is doomed!" << endl;
			}
			else
			{
				cout << res << endl;
			}
		}


	}


	return 0;
}

