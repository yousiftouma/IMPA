#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <locale>
#include <sstream>
#include <regex>
using namespace std;

void split(const string &s, char delim, vector<string> &elems) {
	stringstream ss;
	ss.str(s);
	string item;
	while (getline(ss, item, delim)) {
		elems.push_back(item);
	}
}

vector<string> split(const string &s, char delim) {
	vector<string> elems;
	split(s, delim, elems);
	return elems;
}

int main()
{
	int _case = 1;
	string indexterm;
	string textline;
	while (true)
	{
		bool read_empty_line_first_loop = true;
		map<string, vector<int> > index;
		while(getline(cin, indexterm))
		{
			if (indexterm.empty())
			{
				if (read_empty_line_first_loop) return 0;
				break;
			}
			read_empty_line_first_loop = false;
			vector<int> vec;
			transform(indexterm.begin(), indexterm.end(), indexterm.begin(), ::toupper);
			pair<string, vector<int> > pair;
			pair.first = indexterm;
			pair.second = vec;
			index.insert(pair);
		}
		int line = 1;
		while(getline(cin, textline))
		{
			if (textline.empty()) break;
			transform(textline.begin(), textline.end(), textline.begin(), ::toupper);
			auto words = split(textline, ' ');
			for (auto word : words)
			{
				for (auto &term : index)
				{
					auto regexstring = "(^|\W)" + term.first + "($|\W)";
					if (regex_match(word, regex(regexstring)))
					{
						// Only if not already
						term.second.push_back(line);
					}
				}
			}
			
			line++;
		}

	}
}

