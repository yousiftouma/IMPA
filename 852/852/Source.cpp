#include <iostream>
#include <string>
using namespace std;

// definitions help code readability
#define BLACK 'X'
#define WHITE 'O'
#define NONE '.'

char grid[15][15]; // the game board
int seen[15][15]; // keeps track of visits
int dx[4] = { -1,1,0,0 }; // used to fill area
int dy[4] = { 0,0,1,-1 }; // used to fill area
int black, white; // results
int black_borders, white_borders; // border count for nodes

// flood fill algorithm implementation, tries to "fill" the empty spaces
// with the color they are owned by
int floodfill(int x, int y)
{
	int i, r, nx, ny;
	r = 0;
	switch (grid[x][y])
	{
	case BLACK: black_borders++;
		break;
	case WHITE: white_borders++;
		break;
	default:
		if (seen[x][y]) return 0; // already visited
		seen[x][y] = 1; // now its visited
		r++;
		// recursive calls to try to fill an area
		for (i = 0; i < 4; i++)
		{
			nx = x + dx[i];
			ny = y + dy[i];
			if (nx >= 0 && nx < 9 && ny >= 0 && ny < 9)
				r += floodfill(nx, ny);
		}
		break;
	}
	return r;
}

int main()
{
	int cases;
	cin >> cases;
	cin.ignore();
	while (cases > 0) {
		int black = 0;
		int white = 0;
		int region;
		string line;
		// fill grid
		for (auto i = 0; i < 9; ++i)
		{
			getline(cin, line);
			for (auto j = 0; j < 9; ++j)
			{
				grid[i][j] = line[j];
				seen[i][j] = 0;
			}
		}

		// determine points
		for (auto i = 0; i < 9; ++i)
		{
			for (auto j = 0; j < 9; j++)
			{
				if (grid[i][j] == BLACK) ++black;
				else if (grid[i][j] == WHITE) ++white;
				else if (grid[i][j] == NONE && !seen[i][j])
				{
					black_borders = white_borders = 0;
					region = floodfill(i, j);
					// no black borders, region is white
					if (black_borders == 0) white += region; 
					// no white borders, region is black
					else if (white_borders == 0) black += region; 
					// else the region is not owned, do nothing
				}
			}
		}	
		cout << "Black " << black << " White " << white << endl;
		--cases;
	}

	return 0;
}