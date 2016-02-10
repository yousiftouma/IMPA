#include <iostream>
#include <vector>
using namespace std;

int main()
{
	//freopen("out.txt", "w", stdout);
	long long num, numbers;
	long long track;
	int casee = 1;
	vector<long long> tempvec;
	while (cin >> numbers)
	{
		long long res = 0;
		vector<long long> seq;
		while (numbers > 0)
		{
			cin >> num;
			seq.push_back(num);
			--numbers;
		}
		for (size_t i = 0; i < seq.size(); i++)
		{
			if (seq[i] > res) res = seq[i];
			track = seq[i];
			tempvec.assign(seq.begin() + i + 1, seq.end());
			for (auto f : tempvec)
			{
				if (track * f > res) res = track * f;
				track = track * f;
			}
		}
		cout << "Case #" << casee << ": The maximum product is " << res << "." << endl;
		cout << endl;
		++casee;
	}
	return 0;
}