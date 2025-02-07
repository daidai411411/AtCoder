#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

struct Cell {
	int r{0}, c{0};

	Cell operator+(const Cell cell) const {
		return Cell{this->r + cell.r, this->c + cell.c};
	}

	bool operator==(const Cell cell) const {
		return (this->r == cell.r && this->c == cell.c);
	}

	bool operator<(const Cell cell) const {
		if (this->r == cell.r) return (this->c < cell.c);
		else return (this->r < cell.r);
	}
};

class UnionFind {
   public:
	map<Cell, Cell> parent;
	map<Cell, int> root_size;

	UnionFind(const int h, const int w) {
		for (int r = 0; r < h; r++) {
			for (int c = 0; c < w; c++) {
				parent.insert(pair<Cell, Cell>{Cell{r, c}, Cell{r, c}});
				root_size.insert(pair<Cell, int>{Cell{r, c}, 1});
			}
		}
	}

	Cell Root(const Cell cell) {
		if (parent[cell] == cell) return cell;
		else {
			parent[cell] = this->Root(parent[cell]);
			return parent[cell];
		}
	}

	void Unite(const Cell cell1, const Cell cell2) {
		Cell root1 = this->Root(cell1);
		Cell root2 = this->Root(cell2);
		if (root1 == root2) return;
		else {
			parent[root2] = root1;
			root_size[root1] += root_size[root2];
			root_size.erase(root2);
		}
	}

	bool Same(const Cell cell1, const Cell cell2) {
		return (this->Root(cell1) == this->Root(cell2));
	}

	int Size(const Cell cell) {
		return root_size[this->Root(cell)];
	}
};

int main() {
	Cell directions[]{Cell{0, -1}, Cell{0, 1}, Cell{-1, 0}, Cell{1, 0}};

	int h, w;
	cin >> h >> w;
	vector<string> grid(h);
	for (string& s : grid) {
		cin >> s;
	}

	vector<vector<bool>> free(h, vector<bool>(w, true));
	for (int r = 0; r < h; r++) {
		for (int c = 0; c < w; c++) {
			if (grid[r][c] == '.') continue;
			free[r][c] = false;

			for (Cell d : directions) {
				Cell neighbor = Cell{r, c} + d;
				if (neighbor.r < 0 || h <= neighbor.r || neighbor.c < 0 || w <= neighbor.c) continue;

				free[neighbor.r][neighbor.c] = false;
			}
		}
	}

	UnionFind union_find(h, w);

	for (int r = 0; r < h; r++) {
		for (int c = 0; c < w; c++) {
			if (!free[r][c]) continue;

			for (Cell d : directions) {
				Cell neighbor = Cell{r, c} + d;
				if (neighbor.r < 0 || h <= neighbor.r || neighbor.c < 0 || w <= neighbor.c) continue;

				if (free[neighbor.r][neighbor.c]) union_find.Unite(Cell{r, c}, neighbor);
			}
		}
	}

	int max_size = 0;
	for (auto root_size : union_find.root_size) {
		if (free[root_size.first.r][root_size.first.c] && max_size < root_size.second) max_size = root_size.second;
	}

	cout << max_size << endl;

	return 0;
}
