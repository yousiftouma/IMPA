#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {

	int cases;
	cin >> cases;
	for (auto h = 1; h <= cases; ++h)
	{
		int r, c, imp, nonimp;
		cin >> r >> c >> imp >> nonimp;
		cin.ignore();
		map<char, int> freq;
		char letter;
		string line;
		for (auto i = 0; i < r; ++i)
		{
			getline(cin, line);
			for (auto j = 0; j < c; ++j)
			{
				if (freq.find(line[j]) == freq.end())
				{
					freq.insert(make_pair(line[j], 1));
				}
				else
				{
					freq[line[j]]++;
				}
			}
		}
		int bestval = 0;
		for (auto k : freq)
		{
			if (k.second > bestval)
			{
				bestval = k.second;
			}
		}
		
		int res = 0;
		for (auto g:freq)
		{
			if (g.second == bestval) res += imp*g.second;
			else res += nonimp*g.second;
		}
		cout << "Case " << h << ": " << res << endl;

	}
	return 0;
}