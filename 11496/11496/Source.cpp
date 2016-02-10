#include <iostream>
using namespace std;

int main()
{
	freopen("output.txt", "w", stdout);
	int N, count;
	while (cin >> N)
	{
		if (N == 0) break;
		count = 0;
		int samples[10000];
		for (auto i = 0; i < N; i++)
		{
			cin >> samples[i];
		}
		if (signbit(static_cast<float>(samples[0] - samples[N-1])) == 
			signbit(static_cast<float>(samples[0] - samples[1])))
		{
			count++;
		}
		if (signbit(static_cast<float>(samples[N-1] - samples[N - 2])) ==
			signbit(static_cast<float>(samples[N-1] - samples[0])))
		{
			count++;
		}
		for (auto i = 1; i < N-1; i++)
		{
			if (signbit(static_cast<float>(samples[i] - samples[i-1])) ==
				signbit(static_cast<float>(samples[i] - samples[i+1])))
			{
				count++;
			}
		}

		cout << count << endl;
	}


	return 0;
}