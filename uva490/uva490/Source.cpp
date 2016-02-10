#include <iostream>
#include <string>
#include <list>
using namespace std;

int main()
{
	list<string> sentences;
	auto loops = 100;
	string s;
	while (true)
	{
		getline(cin, s);
		if (s.empty()) break;
		sentences.push_front(s);
		--loops;
	}
	string res;
	for (size_t i = 0; i < 100; i++)
	{
		auto check = 0;
		for (auto sentence : sentences)
		{
			if (i + 1 <= sentence.length())
			{
				res += sentence[i];
			}
			else
			{
				res += " ";
				++check;
			}
		}
		if (check == sentences.size()) break;
		res += "\n";
	}
	cout << res << endl;
	return 0;
}