#include <algorithm>
#include <array>
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
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
using ll = long long;
using ull = unsigned long long;

void ChMax(ull& a, ull b) {
	if (b > a) a = b;
}

bool Exists(int w, int e, int i, int j) {
	return e & (1 << (i * w + j));
}

void Put(int w, int& e, int i, int j) {
	e ^= 1 << (i * w + j);
}

void Remove(int w, int& e, int i, int j) {
	e ^= 1 << (i * w + j);
}

void Dfs(int h, int w, const vector<vector<ull>>& a, int& e, set<int>& seen, ull& x, ull& mx) {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w - 1; j++) {
			if (Exists(w, e, i, j) or Exists(w, e, i, j + 1)) continue;
			Put(w, e, i, j);
			Put(w, e, i, j + 1);
			if (seen.find(e) == seen.end()) {
				seen.insert(e);
				x = x ^ a[i][j] ^ a[i][j + 1];
				ChMax(mx, x);
				Dfs(h, w, a, e, seen, x, mx);
				x = x ^ a[i][j] ^ a[i][j + 1];
			}
			Remove(w, e, i, j);
			Remove(w, e, i, j + 1);
		}
	}

	for (int i = 0; i < h - 1; i++) {
		for (int j = 0; j < w; j++) {
			if (Exists(w, e, i, j) or Exists(w, e, i + 1, j)) continue;
			Put(w, e, i, j);
			Put(w, e, i + 1, j);
			if (seen.find(e) == seen.end()) {
				seen.insert(e);
				x = x ^ a[i][j] ^ a[i + 1][j];
				ChMax(mx, x);
				Dfs(h, w, a, e, seen, x, mx);
				x = x ^ a[i][j] ^ a[i + 1][j];
			}
			Remove(w, e, i, j);
			Remove(w, e, i + 1, j);
		}
	}
}

int main() {
	int h, w;
	cin >> h >> w;
	vector<vector<ull>> a(h, vector<ull>(w));
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) cin >> a[i][j];
	}

	int e = 0;
	set<int> seen;
	ull x = 0, mx = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) x ^= a[i][j];
	}
	mx = x;
	Dfs(h, w, a, e, seen, x, mx);

	cout << mx << endl;

	return 0;
}
