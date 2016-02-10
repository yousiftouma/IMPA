#include <iostream>
#include <vector>
#include <set>
using namespace std;

set<int> ladies_set;
int middle;

int binarySearch(const std::vector<int>& vec, int start, int end, const int& key)
{
	// Termination condition: start index greater than end index
	if (start > end)
	{
		return middle;
	}

	// Find the middle element of the vector and use that for splitting
	// the array into two pieces.
	middle = start + ((end - start) / 2);

	if (vec[middle] == key)
	{
		return middle;
	}
	else if (vec[middle] > key)
	{
		return binarySearch(vec, start, middle - 1, key);
	}

	return binarySearch(vec, middle + 1, end, key);
}

int main()
{
	int N, Q;
	int lady, luchu;
	cin >> N;
	cin >> lady;
	ladies_set.insert(lady);
	auto it = ladies_set.begin();
	while (N>1){
		cin >> lady;
		ladies_set.insert(it, lady);
		++it;
		--N;
	}
	//vector with unique elements
	vector<int> ladies(ladies_set.begin(), ladies_set.end());
	int size = ladies.size();

	cin >> Q;
	while (Q > 0)
	{
		cin >> luchu;
		//special cases
		if (luchu < ladies[0])
		{
			cout << "X " << ladies[0] << endl;
		}
		else if(luchu > ladies[size-1])
		{
			cout << ladies[size - 1] << " X" << endl;
		}
		else {
			//binary search for Luchu's height in the vector
			//to isolate lower and upper bounds
			middle = 0;
			middle = binarySearch(ladies, 0, size, luchu);

			// if Luchu's height is present we try to choose
			// values to the left and right of this value, if possible
			// otherwise there is no answer
			if (ladies[middle] == luchu)
			{
				if (middle - 1 >= 0) cout << ladies[middle - 1] << " "; //ans is GLB
				else cout << "X "; //no GLB, Luchu is short

				if (middle + 1 < size) cout << ladies[middle + 1]; //ans is LUB
				else cout << "X"; //no LUB, Luchu is tall
				cout << endl;
			}
			// otherwise we try to choose the best value compared to Luchu
			else
			{
				// this is the highest value lower than luchu
				if (ladies[middle] < luchu) cout << ladies[middle] << " ";
				else if (middle - 1 >= 0) cout << ladies[middle - 1] << " ";
				else cout << "X "; //No value was lower than luchu

				// this is the lowest value higher than luchu
				if (ladies[middle] > luchu) cout << ladies[middle];
				else if (middle + 1 < size) cout << ladies[middle + 1];
				else cout << "X"; //No value was higher than luchu
				cout << endl;
			}
		}--Q;
	}

	return 0;
	
}

