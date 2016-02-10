#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string input;
	getline(cin, input);

	unordered_map<string, string> alpha;
	alpha.insert(make_pair("e", "q"));
	alpha.insert(make_pair("d", "a"));
	alpha.insert(make_pair("c", "z"));
	alpha.insert(make_pair("x", "/"));
	alpha.insert(make_pair("s", "'"));
	alpha.insert(make_pair("w", "]"));
	alpha.insert(make_pair("z", "."));
	alpha.insert(make_pair("a", ";"));
	alpha.insert(make_pair("q", "["));
	alpha.insert(make_pair("r", "w"));
	alpha.insert(make_pair("f", "s"));
	alpha.insert(make_pair("v", "z"));
	alpha.insert(make_pair("t", "e"));
	alpha.insert(make_pair("g", "d"));
	alpha.insert(make_pair("b", "c"));
	alpha.insert(make_pair("y", "r"));
	alpha.insert(make_pair("h", "f"));
	alpha.insert(make_pair("n", "v"));
	alpha.insert(make_pair("u", "t"));
	alpha.insert(make_pair("j", "g"));
	alpha.insert(make_pair("m", "b"));
	alpha.insert(make_pair("i", "y"));
	alpha.insert(make_pair("k", "h"));
	alpha.insert(make_pair(",", "n"));
	alpha.insert(make_pair("o", "u"));
	alpha.insert(make_pair("l", "j"));
	alpha.insert(make_pair(".", "m"));
	alpha.insert(make_pair("p", "i"));
	alpha.insert(make_pair(";", "k"));
	alpha.insert(make_pair("/", ","));
	alpha.insert(make_pair("[", "o"));
	alpha.insert(make_pair("'", "l"));
	alpha.insert(make_pair("]", "p"));
	alpha.insert(make_pair("e", "q"));
	string res;
	string letter;
	for (size_t i = 0; i < input.length(); i++)
	{
		if (input[i] == ' ')
		{
			res += ' ';
		}
		else
		{
			letter = (i+1, input[i]);
			transform(letter.begin(), letter.end(), letter.begin(), ::tolower);
			res += alpha.at(letter);
		}
	}
	cout << res << endl;

	return 0;
}