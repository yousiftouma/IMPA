#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int vTot, v0;
	
	while (cin >> vTot >> v0)
	{
		if (vTot == 0 && v0 == 0) break;
		int res = 0;
		double length;
		double D;
		double best = 0;
		//try splitting up
		for (int parts = 1; parts < 600001; parts++) {

			//how much volume we can use
			double vCurr = (double)vTot / (double)parts;


			//cant make more
			if (vCurr <= v0) {
				break;
			}
			// diameter of one disc in this iteration
			D = 0.3 * sqrt(vCurr - (double) v0);

			length = (double)parts * D;
			

			if(length >= best)
			{
				// if they are actually equal (double-comparison equal)
				if (fabs(length - best) < 1e-12)
				{
					res = 0;
					best = 0;
					break;
				}
				best = length;
				res = parts;
			}
		}
		cout << res << endl;
	}
	return 0;
}