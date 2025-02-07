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
	int row{0}, col{0};

	Cell operator+(const Cell cell) const {
		return Cell{this->row + cell.row, this->col + cell.col};
	}

	bool operator==(const Cell cell) const {
		return (this->row == cell.row && this->col == cell.col);
	}
};

int main() {
	Cell directions[]{Cell{0, -1}, Cell{0, 1}, Cell{-1, 0}, Cell{1, 0}};

	int h, w;
	cin >> h >> w;
	vector<string> grid(h);
	for (string& r : grid) cin >> r;

	int max_degree_of_freedom{0};
	vector<vector<Cell>> processed_by(h, vector<Cell>(w, Cell{-1, -1}));
	for (int r = 0; r < h; r++) {
		for (int c = 0; c < w; c++) {
			if (grid[r][c] == '#' || processed_by[r][c].row != -1) continue;

			int degree_of_freedom{0};
			Cell start{r, c};
			queue<Cell> to_be_processed;
			to_be_processed.push(start);

			while (!to_be_processed.empty()) {
				Cell current = to_be_processed.front();
				to_be_processed.pop();

				if (processed_by[current.row][current.col] == start) continue;
				processed_by[current.row][current.col] = start;
				degree_of_freedom++;

				bool current_is_free{true};
				vector<Cell> to_be_pushed;
				for (Cell direction : directions) {
					Cell neighbor = current + direction;
					if (neighbor.row < 0 || h <= neighbor.row || neighbor.col < 0 || w <= neighbor.col) continue;
					if (grid[neighbor.row][neighbor.col] == '#') {
						current_is_free = false;
						break;
					}
					to_be_pushed.push_back(neighbor);
				}
				if (current_is_free) {
					for (Cell cell : to_be_pushed) to_be_processed.push(cell);
				}
			}

			if (max_degree_of_freedom < degree_of_freedom) max_degree_of_freedom = degree_of_freedom;
		}
	}

	cout << max_degree_of_freedom << endl;

	return 0;
}
