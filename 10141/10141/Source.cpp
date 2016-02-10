#include <iostream>
#include  <string>
#include <limits>
using namespace std;

int main ()
{
	int reqs, props, reqs_met, comp, best_comp;
	int RFP = 0;
	string tmp, name, ans;
	double value, best_value;

	while (cin >> reqs >> props)
	{
		if (reqs == 0) break;
		best_value = numeric_limits<double>::max();
		best_comp = 0;
		cin.ignore();
		if (RFP != 0) {
			cout << endl;
		}
		for (int i = 0; i < reqs; i++)
		{
			getline(cin, tmp);
		}
		for (int j = 0; j < props; j++)
		{
			getline(cin, name); // name of prop
			cin >> value;
			cin >> reqs_met;
			cin.ignore();
			for (int k = 0; k < reqs_met; k++)
			{
				getline(cin, tmp);
			}
			comp = reqs_met;
			if (comp > best_comp || comp == best_comp && value < best_value)
			{
				best_comp = comp;
				best_value = value;
				ans = name;
			}
		}


		cout << "RFP #" << ++RFP << endl << ans << endl;
	}




	return 0;
}