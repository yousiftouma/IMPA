#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int n;
	double ha, hb, hc;
	cin >> n;
	while (cin >> ha >> hb >> hc)
	{
		if (ha <= 0 || hb <= 0 || hc <= 0)
		{
			cout << "These are invalid inputs!\n";
			n--;
			if (n == 0) return 0;
			continue;
		}
		double fact1 = 1.0 / ha + 1.0 / hb + 1.0 / hc;
		double fact2 = 1.0 / hb + 1.0 / hc - 1.0 / ha;
		double fact3 = 1.0 / hc + 1.0 / ha - 1.0 / hb;
		double fact4 = 1.0 / ha + 1.0 / hb - 1.0 / hc;
		double denom = fact1*fact2*fact3*fact4;
		double q = 1.0 / denom;
		if (q < 0.0)
		{
			cout << "These are invalid inputs!\n";
			n--;
			if (n == 0) return 0;
			continue;
		}
		double ans = sqrt(q);
		printf("%.3f\n", ans);
	}
}
