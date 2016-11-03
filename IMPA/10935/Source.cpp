#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int n;
	while (cin >> n)
	{
		if (n == 0) return 0;
		if (n == 1)
		{
			cout << "Discarded cards:\n";
			cout << "Remaining card: 1\n";
			continue;
		}
		// front is top back is bottom
		deque<int> deck;
		vector<int> discarded;
		int remaining;
		for (int i = 1; i <= n; i++)
		{
			deck.push_back(i);
		}
		while (deck.size() > 1)
		{
			discarded.push_back(deck.front());
			deck.pop_front();
			int moving = deck.front();
			deck.pop_front();
			deck.push_back(moving);
		}
		remaining = deck.front();
		cout << "Discarded cards: ";
		for (int i = 0; i < discarded.size() - 1; i++)
		{
			cout << discarded[i] << ", ";
		}
		cout << discarded[discarded.size() - 1] << "\n";
		cout << "Remaining card: " << remaining << "\n";
	}
}