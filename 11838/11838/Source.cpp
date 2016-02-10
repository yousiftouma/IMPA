#include <iostream>
#include <vector>

using namespace std;


struct node
{
	int name;
	bool visited;

	explicit node(int n, bool v = false) : name(n), visited(v){}
};

struct graph
{
	vector<node> nodes;
	vector<pair<int, int> > edges;
};

int main ()
{
	int nodes, edges, node1, node2, one_or_two_way;

	while (cin >> nodes >> edges)
	{
		if (nodes + edges == 0)
		{
			return 0;
		}
		graph G;
		for (int i = 1; i <= nodes; i++)
		{
			node my_node(i, false);
			G.nodes.push_back(my_node);
		}









	}

	return 0;
}