#include <iostream>
#include <string>
#include <iomanip>
#include <math.h>
using namespace std;

int main ()
{
	long double speed;
	int hour, min, sec, lasth, lastm, lasts;
	long int sec_elapsed = 0;
	long double dist = 0.0;
	string line;

	while (getline(cin, line))
	{
		if (line == "") return 0;
		hour = (line.substr(0, 2)[0] - '0') * 10 + line.substr(0, 2)[1] - '0';
		min = (line.substr(3, 2)[0] - '0') * 10 + line.substr(3, 2)[1] - '0';
		sec = (line.substr(6, 2)[0] - '0') * 10 + line.substr(6, 2)[1] - '0';

		if (line.length() > 8)
		{

			if (dist > 0) {
				sec_elapsed += (hour - lasth) * 60 * 60;
				sec_elapsed += (min - lastm) * 60;
				sec_elapsed += (sec - lasts);
				dist += sec_elapsed * speed;
				sec_elapsed = 0;
			}

			lasth = hour;
			lastm = min;
			lasts = sec;

			speed = 0.0;
			
			string speed_string = line.substr(9);



			while (speed_string.length() >= 1)
			{
				speed += (speed_string[0] - '0') *
					(double)pow(10, speed_string.length() - 1);
			}

			speed = speed/ 3600.0; // km per sec
		}
		else
		{
			sec_elapsed += (hour - lasth) * 60 * 60;
			sec_elapsed += (min - lastm) * 60;
			sec_elapsed += (sec - lasts);
			dist += sec_elapsed * speed;

			cout << fixed;
			cout << setprecision(2);

			cout << line.substr(0, 2) << ":" <<
				line.substr(3, 2) << ":" << 
				line.substr(6, 2) << " " << dist << " km" << endl;

			sec_elapsed = 0;
			lasth = hour;
			lastm = min;
			lasts = sec;
		}

	}

	return 0;
}