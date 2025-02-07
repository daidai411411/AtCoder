#include <algorithm>
#include <atcoder/all>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_set>
#include <vector>

#define INF (1000000000)

using namespace std;
using ll = long long;

void CalcHumidArea(int h, int w, int d, vector<string>& office, vector<vector<int>>& dist, int hr, int hc) {
	queue<array<int, 2>> cell_q;
	cell_q.push({hr, hc});

	while (!cell_q.empty()) {
		array<int, 2> cell = cell_q.front();
		cell_q.pop();

		if (office[cell[0]][cell[1]] == 'H') dist[cell[0]][cell[1]] = 0;

		if (dist[cell[0]][cell[1]] == d) continue;
		for (array<int, 2> adj : vector<array<int, 2>>{{cell[0] - 1, cell[1]}, {cell[0] + 1, cell[1]}, {cell[0], cell[1] - 1}, {cell[0], cell[1] + 1}}) {
			if (not(0 <= adj[0] and adj[0] < h and 0 <= adj[1] and adj[1] < w)) continue;
			if (office[adj[0]][adj[1]] == '#') continue;
			if (dist[adj[0]][adj[1]] <= dist[cell[0]][cell[1]] + 1) continue;
			dist[adj[0]][adj[1]] = dist[cell[0]][cell[1]] + 1;
			cell_q.push(adj);
		}
	}
}

int main() {
	int h, w, d;
	cin >> h >> w >> d;
	vector<string> office(h);
	for (string& i : office) cin >> i;

	vector<vector<int>> dist(h, vector<int>(w, INF));
	for (int r = 0; r < h; r++) {
		for (int c = 0; c < w; c++) {
			if (office[r][c] == 'H') CalcHumidArea(h, w, d, office, dist, r, c);
		}
	}

	int humid_area = 0;
	for (auto i : dist) {
		for (int j : i) {
			if (j != INF) humid_area++;
		}
	}
	cout << humid_area << endl;

	return 0;
}
