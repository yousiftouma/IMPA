#include <iostream>
#include <string>
using namespace std;

int main ()
{
	string hajj = "Hajj-e-Akbar";
	string umrah = "Hajj-e-Asghar";

	int case_ = 1;

	string input;
	while (cin >> input)
	{
		if (input == "*") break;
		else if (input == "Hajj") cout << "Case " << case_ << ": " << hajj << endl;
		else cout << "Case " << case_ << ": " << umrah << endl;
		case_++;
	}


	return 0;
}