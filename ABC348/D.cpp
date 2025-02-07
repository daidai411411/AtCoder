#include <stdlib.h>

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>

using namespace std;

struct Cell {
	int r{0}, c{0};
};

const Cell directions[]{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int main() {
	int h, w, n;
	cin >> h >> w;
	vector<string> grid(h);
	Cell s;
	for (int r = 0; r < h; r++) {
		cin >> grid[r];
		string::size_type s_pos = grid[r].find('S');
		if (s_pos != string::npos) s = Cell{r, (int)s_pos};
	}

	cin >> n;
	vector<vector<int>> mgrid(h, vector<int>(w, 0));
	for (int i = 0; i < n; i++) {
		int mr, mc, me;
		cin >> mr >> mc >> me;
		mgrid[mr - 1][mc - 1] = me;
	}

	vector<vector<int>> egrid(h, vector<int>(w, -1));
	list<Cell> processing_cells;
	processing_cells.push_back(s);

	while (processing_cells.size() > 0) {
		Cell current = processing_cells.front();
		processing_cells.pop_front();
		if (grid[current.r][current.c] == 'T') {
			cout << "Yes" << endl;
			return 0;
		}
		if (egrid[current.r][current.c] < mgrid[current.r][current.c]) {
			egrid[current.r][current.c] = mgrid[current.r][current.c];
		}
		for (Cell direction : directions) {
			Cell neighbor{current.r + direction.r, current.c + direction.c};
			if (0 <= neighbor.r && neighbor.r < h && 0 <= neighbor.c && neighbor.c < w &&
				grid[neighbor.r][neighbor.c] != '#' &&
				egrid[current.r][current.c] >= 1 &&
				egrid[neighbor.r][neighbor.c] < egrid[current.r][current.c] - 1)
			{
				egrid[neighbor.r][neighbor.c] = egrid[current.r][current.c] - 1;
				processing_cells.push_back(neighbor);
			}
		}
	}
	cout << "No" << endl;

	return 0;
}
