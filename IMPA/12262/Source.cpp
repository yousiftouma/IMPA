/* Competitive programming template. */
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(auto i=decltype(a)(a); i < (b); ++i)
#define repincl(i,a,b) for(auto i=decltype(a)(a); i <= (b); ++i)
// must dereference it to get each object
#define foreach(it,c) for (auto it = (c).begin(); it != (c).end(); ++it)
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef long long ll;
typedef unsigned long long ull;
const double PI = acos(-1);
const int INF = ~(1 << 31); // 2147483647
const double EPS = 1e-9;
void solve();
int main() { ios::sync_with_stdio(false);cin.tie(NULL);solve();return 0; }
/* End of header. */

void solve() {
	int cases;
	cin >> cases;
	while (cases--)
	{
		double alpha, beta, vmax, f, x, y;
		int r;
		cin >> alpha >> beta >> vmax >> f;
		cin >> r;
		vd lengths, slopes;
		rep(i, 0, r)
		{
			cin >> x >> y;
			// calc the length of the segment using Pythagoras
			lengths.push_back(sqrt(x*x + y*y) * 0.001);
			// the slope of the segment is deltaY/deltaX where
			// for every segment deltaY is the change in height (y)
			// and deltaX is the horizontal change (x)
			slopes.push_back(y / x);
		}

		// binary search for the highest possible average speed
		// we can keep to not run out of fuel
		auto leftPtr = 0.0;
		auto rightPtr = vmax;
		auto vAverage = -1.0;
		rep(i,0,100)
		{
			auto vcurr = (leftPtr + rightPtr) * 0.5;
			auto fuelUsed = 0.0;
			rep(j, 0, r)
			{
				auto consumption = max(0.0, alpha * vcurr + beta * slopes[j]);
				fuelUsed += consumption * lengths[j];
			}
			if (fuelUsed <= f)
			{
				// we check if we can go faster and stay within limit f
				vAverage = vcurr;
				leftPtr = vcurr;
			}
			else
			{
				// we check for slower velocities to stay within limit f
				rightPtr = vcurr;
			}
		}
		if (vAverage != -1.0)
		{
			auto result = 0.0;
			rep (i,0,r)
			{
				auto consumption = alpha * vAverage + beta * slopes[i];
				// need to handle possible negative consumptions on some segments
				// using the average velocity
				if (consumption < 0.0)
				{
					// find the actual velocity we can use in this downward slope
					// choose it if its less than vmax
					auto velocity = min(-beta*slopes[i] / alpha, vmax);
					result += lengths[i] / velocity;
				}
				else result += lengths[i] / vAverage;
			}
			printf("%.6f\n", result);
		}
		else cout << "IMPOSSIBLE" << endl;
	}
}