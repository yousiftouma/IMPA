#include <iostream>
using namespace std;

int stepOne()
{
	return 720;
}

int stepTwo(int start, int first, int step)
{
	if (start < first)
	{
		return (start + (40 - first)) * step;
	}
	return abs(start - first) * step;
}

int stepThree()
{
	return 360;
}

int stepFour(int first, int second, int step)
{
	if (second < first) {
		return (40 - first + second) * step;
	}
	return (second - first)*step;
}

int stepFive(int second, int third, int step)
{
	if (third > second)
	{
		return (40-(40-second) + (40-third))*step;
	}
	return abs(second - third) * step;
}

int main() {
	auto oneStep = 360 / 40;
	int start, first, second, third, res;

	while (true)
	{
		cin >> start >> first >> second >> third;
		if (start + first + second + third == 0)
		{
			break;
		}
		res = stepOne() + stepTwo(start, first, oneStep) + stepThree()
			+ stepFour(first, second, oneStep) + stepFive(second, third, oneStep);
		cout << res << endl;
	}



	return 0;
}