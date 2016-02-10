#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> topological_sorting(vector< vector<int> > graph) {
	vector<int> indegree(graph.size(), 0);
	queue<int> q;
	vector<int> solution;

	for (int i = 1; i < graph.size(); i++) {
		for (int j = 0; j < graph[i].size(); j++) { //iterate over all edges
			indegree[graph[i][j]]++;
		}
	}

	//enqueue all nodes with indegree 0
	for (int i = 1; i < graph.size(); i++) {
		if (indegree[i] == 0) {
			q.push(i);
		}
	}

	//remove one node after the other
	while (q.size() > 0) {
		int currentNode = q.front();
		q.pop();
		solution.push_back(currentNode);
		for (int j = 0; j < graph[currentNode].size(); j++) { //remove all edges
			int newNode = graph[currentNode][j];
			indegree[newNode]--;
			if (indegree[newNode] == 0) { //target node has now no more incoming edges
				q.push(newNode);
			}
		}
	}
	return solution;
}

int main()
{
	int tasks, relations, relone, reltwo;
	while (cin >> tasks >> relations)
	{
		if (tasks + relations == 0)
		{
			break;
		}
		vector<vector <int> > graph(tasks + 1);
		while (relations > 0)
		{
			cin >> relone >> reltwo;
			graph[relone].push_back(reltwo);
			--relations;
		}


		auto ans = topological_sorting(graph);
		for (auto integ : ans)
		{
			cout << integ << " ";
		}
		cout << endl;
	}

	return 0;
}
