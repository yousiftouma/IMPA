#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	// Below (commented) won't work, trying identical solution with printf and its formatting
	/**
	double n, p;
	while (cin >> n >> p)
	{
		auto ans = pow(p, 1 / n);
		//auto tans = trunc(round(ans));
		cout << setprecision(0) << ans << "\n";
	}
	return 0;
	**/

	double n, p;
	while (cin >> n >> p)
	{
		auto ans = pow(p, 1 / n);
		printf("%.0lf", ans);
		printf("\n");
	}
}