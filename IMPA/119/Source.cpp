#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <stdio.h>
#include <cmath>
using namespace std;

int main()
{
	int n;
	auto first = true;
	while (cin >> n)
	{
		if (cin.eof()) return 0;
		if (first)
		{
			first = false;
		}
		else
		{
			cout << endl;
		}
		map<string, double> people;
		vector<string> names;
		for (int i = 0; i < n; i++)
		{
			string person;
			cin >> person;
			people.insert(make_pair(person, 0.0));
			names.push_back(person);
		}
		for (int i = 0; i < n; i++)
		{
			string curr;
			double people_to_spend_on;
			double money_to_spend;
			cin >> curr >> money_to_spend >> people_to_spend_on;
			if (money_to_spend > 0.0 && people_to_spend_on > 0.0)
			{
				double per_person = trunc(money_to_spend / people_to_spend_on);
				people[curr] -= per_person * people_to_spend_on;

				for (double j = 0.0; j < people_to_spend_on; j += 1.0)
				{
					cin >> curr;
					people[curr] += per_person;
				}
			}
			else if (people_to_spend_on > 0.0)
			{
				string dummy;
				for (double j = 0.0; j < people_to_spend_on; j+= 1.0)
				{
					cin >> dummy;
				}
			}
		}
		for (auto person : names)
		{
			cout << person << " ";
			printf("%.0f\n", people[person]);
		}
	}
}