#include <iostream>
#include <map>
#include <vector>
using namespace std;


int fallen_rec(int domino, map<int, vector<int> > dominoes)
{
	if (dominoes[domino].empty())
	{
		return 0;
	}
	else
	{
		int new_dom = dominoes[domino].back();
		dominoes[domino].pop_back();
		return 1 + fallen_rec(new_dom, dominoes);
	}
}

int main ()
{
	int cases;
	cin >> cases;
	while(cases--)
	{
		int res = 0;
		map<int, vector<int> > dominoes;
		bool up[10001];
		int bricks, pairs, handed;

		cin >> bricks >> pairs >> handed;

		for (int i = 1; i <= bricks; i++)
		{
			vector<int> vector;
			dominoes.insert(make_pair(i, vector));
		}

		int first, second, knocked;
		while (pairs--)
		{
			cin >> first >> second;
			dominoes[first].push_back(second);
		}

		while (handed--)
		{
			cin >> knocked;
			res++;
			res += fallen_rec(knocked, dominoes);
		}

		
	}




	return 0;
}