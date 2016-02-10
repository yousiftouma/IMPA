#include <iostream>
using namespace std;

int Y, P, popes[100005];

// Search for the value less than or equal to x that have the largest index.
int BSearch(int i, int j, int x) {
	int start, end, mid;
	start = i; 
	end = j;
	do
	{
		mid = (start + end) / 2;
		if (popes[mid] <= x) start = mid;  // x might be in right part
		else end = mid;  // The result must in the left part

	} while (end - start > 1);   // search until end and start overlap

	if (popes[end] <= x) return(end);  // last value satisfies range

	return(start);    // if no value, first value is only to satisfy
}

int main ()
{
	
	while (cin >> Y)
	{
		int best_count = 0;
		int best_start;
		int best_end;
		//memset(popes, 0, sizeof(popes));
		cin >> P;
		for (auto i = 1; i <= P; ++i)
		{
			cin >> popes[i];
		}
		
		for (auto i = 1; i <= P; ++i)
		{
			auto start = i;
			auto end = BSearch(i, P, popes[i] + Y - 1); //find index of largest value within allowed range
			if (end - start + 1 > best_count)
			{
				best_count = end - start + 1; // the range is now the best range
				best_start = start;
				best_end = end;
			}
		}

		cout << best_count << " " << popes[best_start] << " " << popes[best_end] << endl;
	}


	return 0;
}