#include <iostream>
#include <string>
using namespace std;

int main ()
{
	//freopen("output.txt", "w", stdout);
	int cases;
	cin >> cases;
	while (cases > 0)
	{
		int instr;
		int res = 0;
		cin >> instr;
		cin.ignore();
		int dir[100];
		string input;
		for (int i = 1; i <= instr; ++i)
		{
			getline(cin, input);
			if (input == "LEFT")
			{
				res -= 1;
				dir[i] = -1;
			}
			else if (input == "RIGHT")
			{
				res += 1;
				dir[i] = 1;
			}
			else
			{
				if (input.size() == 8) {
					char a = input[8];
					int ia = a - '0';
					res += dir[ia];
					dir[i] = dir[ia];
				}
				else
				{
					string a = input.substr(8, 9);
					int ia = stoi(a);
					res += dir[ia];
					dir[i] = dir[ia];
				}	
			}
		}
		cout << res << endl;
		--cases;
	}

	return 0;
}