#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int cases;
	cin >> cases;
	cin.ignore(2);
	
	string line;
	while (cases > 0)
	{
		vector<char> plain, subst;
		vector<string> sentences;
		getline(cin, line);
		for (auto i = 0; i < line.size(); ++i)
		{
			plain.push_back(line[i]);
		}
		getline(cin, line);
		for (auto i = 0; i < line.size(); ++i)
		{
			subst.push_back(line[i]);
		}
		while (getline(cin, line))
		{
			if (line.empty()) break;
			sentences.push_back(line);
		}

		for (auto i = 0; i < sentences.size(); ++i)
		{
			string sentence = sentences[i];
			for (auto j = 0; j < sentence.size(); ++j)
			{
				int x;
				int found = 0;
				for (x = 0; x < plain.size(); ++i) {
					if (plain[x] == sentence[j]) found = 1; break;
				}
				if (found) cout << subst[x];
				else cout << sentence[j];
			}
			cout << endl;
		}

	}


	return 0;
}