#include <iostream>
#include <string>
using namespace std;

int main()
{
	string input;
	string ans;
	auto currCase = 1;
	while (getline(cin, input))
	{
		if (input == "#") break;

		if (input == "HELLO") ans = "ENGLISH";
		else if (input == "HOLA") ans = "SPANISH";
		else if (input == "HALLO") ans = "GERMAN";
		else if (input == "BONJOUR") ans = "FRENCH";
		else if (input == "CIAO") ans = "ITALIAN";
		else if (input == "ZDRAVSTVUJTE") ans = "RUSSIAN";
		else ans = "UNKNOWN";
		cout << "Case " << currCase << ": " << ans << endl;
		++currCase;
	}
    return 0;
}

