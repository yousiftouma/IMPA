#include <iostream>
using namespace std;

int main()
{
	char first, second, third;
	int brown[3], green[3], clear[3], temp, best;
	while (cin >> brown[0] >> green[0] >> clear[0] >> brown[1] >> green[1] >>
		clear[1] >> brown[2] >> green[2] >> clear[2])
	{
		// start with something
		best = brown[1] + brown[2] + clear[0] + clear[2] + green[0] + green[1]; // BCG
		first = 'B'; second = 'C'; third = 'G';

		temp = brown[1] + brown[2] + green[0] + green[2] + clear[0] + clear[1]; // BGC
		if (temp < best)
		{
			best = temp;
			first = 'B'; second = 'G'; third = 'C';
		}

		temp = clear[1] + clear[2] + brown[0] + brown[2] + green[0] + green[1]; // CBG
		if (temp < best)
		{
			best = temp;
			first = 'C'; second = 'B'; third = 'G';
		}

		temp = clear[1] + clear[2] + green[0] + green[2] + brown[0] + brown[1]; // CGB
		if (temp < best)
		{
			best = temp;
			first = 'C'; second = 'G'; third = 'B';
		}

		temp = green[1] + green[2] + brown[0] + brown[2] + clear[0] + clear[1]; // GBC
		if (temp < best)
		{
			best = temp;
			first = 'G'; second = 'B'; third = 'C';
		}

		temp = green[1] + green[2] + clear[0] + clear[2] + brown[0] + brown[1]; // GCB
		if (temp < best)
		{
			best = temp;
			first = 'G'; second = 'C'; third = 'B';
		}

		cout << first << second << third << " " << best << endl;
	}

	return 0;
}