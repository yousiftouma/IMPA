#include <iostream>
using namespace std;

int numDigits(int number)
{
	int digits = 0;
	while (number) {
		number /= 10;
		digits++;
	}
	return digits;
}

int main ()
{
	int integer;
	cout << "PERFECTION OUTPUT" << endl;
	while (cin >> integer)
	{
		if (integer == 0) break;
		int digits = numDigits(integer);
		bool abundant = false;
		int sum = 0;
		bool was_one = true;
		for (int i = 1; i < integer; i++)
		{
			was_one = false;
			if (integer % i == 0) sum += i;
			if (sum > integer) {
				abundant = true;
				break;
			}
		}
		if (was_one) cout << "    " << 1 << "  ";
		else if (digits == 1) cout << "    " << integer << "  ";
		else if (digits == 2) cout << "   " << integer << "  ";
		else if (digits == 3) cout << "  " << integer << "  ";
		else if (digits == 4) cout << " " << integer << "  ";
		else cout << integer << "  ";
		
		if (abundant) cout << "ABUNDANT" << endl;
		else if (sum == integer) cout << "PERFECT" << endl;
		else cout << "DEFICIENT" << endl;
	}

	cout << "END OF OUTPUT" << endl;
	return 0;
}