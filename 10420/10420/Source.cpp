#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int main ()
{
	map<string, int> res;

	int lines;
	string country, dummy;
	cin >> lines;
	while (lines--)
	{
		cin >> country;
		//cin.ignore();
		getline(cin, dummy);
		res[country]++;
	}
	for (auto f : res)
	{
		cout << f.first << " " << f.second << endl;
	}

	return 0;
}