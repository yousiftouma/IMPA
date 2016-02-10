#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


bool comparer(string first, string second)
{
	auto opt1 = first + second;
	auto opt2 = second + first;
	if (opt1 > opt2)
	{
		return true;
	}
	else {
		return false;
	}
}

int main ()
{
	//freopen("out.txt", "w", stdout);
	int numbers;

	while (cin >> numbers) {
		if (numbers == 0) break;
		vector<string> concatenated;
		while (numbers--)
		{
			string inputAsString;
			cin >> inputAsString;
			concatenated.push_back(inputAsString);
		}
		sort(concatenated.begin(), concatenated.end(), comparer);

		for (auto i = 0; i < concatenated.size(); i++)
		{
			cout << concatenated[i];
		}
		cout << endl;
	}

	return 0;
}