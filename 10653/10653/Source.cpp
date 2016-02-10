#include <iostream>
#include <queue>

using namespace std;

char board[1000][1000];
bool visited[1000][1000];
int rows, columns;

int breadthFirstSearch(pair<int, int> start, pair<int, int> end)
{
	pair<pair<int, int>, int> cur;
	queue<pair<pair<int, int>, int> > que;
	que.push(make_pair(start, 0));
	visited[start.first][start.second] = true;
	while (!que.empty())
	{
		cur = que.front();
		que.pop();

		if (cur.first == end) return cur.second;

		if (cur.first.first > 0 && !visited[cur.first.first - 1][cur.first.second] &&
			board[cur.first.first -1][cur.first.second] != '*')
		{
			visited[cur.first.first - 1][cur.first.second] = true;
			que.push(make_pair(make_pair(cur.first.first - 1, cur.first.second),
				cur.second + 1));	
		}
		if (cur.first.first + 1 < rows && !visited[cur.first.first + 1][cur.first.second] &&
			board[cur.first.first + 1][cur.first.second] != '*')
		{
			visited[cur.first.first + 1][cur.first.second] = true;
			que.push(make_pair(make_pair(cur.first.first + 1, cur.first.second), 
				cur.second + 1));
			
		}
		if (cur.first.second > 0  && !visited[cur.first.first][cur.first.second - 1] &&
			board[cur.first.first][cur.first.second - 1] != '*')
		{
			visited[cur.first.first][cur.first.second - 1] = true;
			que.push(make_pair(make_pair(cur.first.first, cur.first.second - 1), 
				cur.second + 1));
			
		}
		if (cur.first.second + 1 < columns && !visited[cur.first.first][cur.first.second + 1] &&
			board[cur.first.first][cur.first.second + 1] != '*')
		{
			visited[cur.first.first][cur.first.second + 1] = true;
			que.push(make_pair(make_pair(cur.first.first, cur.first.second + 1), 
				cur.second + 1));
		}
	}
	return -1; //wont happen in this problem
}

int main ()
{
	while (cin >> rows >> columns && (columns || rows)) {
		for (auto i = 0; i < 1000; ++i)
		{
			for (auto j = 0; j < 1000; ++j)
			{
				board[i][j] = ' ';
				visited[i][j] = false;
			}
		}
		int bombRows, bombRow, bombCols, bombCol;
		cin >> bombRows;
		while (bombRows > 0)
		{
			cin >> bombRow >> bombCols;
			while (bombCols > 0)
			{
				cin >> bombCol;
				board[bombRow][bombCol] = '*';
				--bombCols;
			}
			--bombRows;
		}
		int startRow, startCol, endRow, endCol;
		cin >> startRow >> startCol >> endRow >> endCol;
		auto start = make_pair(startRow, startCol);
		auto end = make_pair(endRow, endCol);

		cout << breadthFirstSearch(start, end) << endl;

	}


	return 0;
}