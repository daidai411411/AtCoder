#include <stdlib.h>

#include <algorithm>
#include <iostream>
#include <list>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

bool eqcontents(vector<int> v1, vector<int> v2) {
	for (auto c : v1) {
		auto itr = find(v2.begin(), v2.end(), c);
		if (itr == v2.end()) return false;
		v2.erase(itr);
	}
	return true;
}

bool comp(int n1, int n2, vector<int> order) {
	for (int o : order) {
		if (n1 == o) return true;
		if (n2 == o) return false;
	}

	return false;
}

vector<pair<int, int>> shakersort(vector<int> v, vector<int> order) {
	vector<pair<int, int>> s;
	int l = 0, r = v.size() - 1;
	int d = 1;
	while (l < r) {
		if (d == 1) {
			for (int i = l; i < r; i++) {
				if (comp(v[i], v[i + 1], order) == false) {
					swap(v[i], v[i + 1]);
					s.push_back(pair<int, int>(i, i + 1));
				}
			}
			r--;
			d = -1;
		} else {
			for (int i = r - 1; i >= l; i--) {
				if (comp(v[i], v[i + 1], order) == false) {
					swap(v[i], v[i + 1]);
					s.push_back(pair<int, int>(i, i + 1));
				}
			}
			l++;
			d = 1;
		}
	}

	return s;
}

int main() {
	int h, w;
	cin >> h >> w;

	vector<vector<int>> a(h, vector<int>(w)), b(h, vector<int>(w));

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> b[i][j];
		}
	}

	// aの0行と内容が同じbの行を探す
	int bi_same_a0j = -1;
	for (int bi = 0; bi < h; bi++) {
		if (eqcontents(a[0], b[bi]) == true) {
			bi_same_a0j = bi;
		}
	}
	if (bi_same_a0j == -1) {
		cout << "-1" << endl;
		return 0;
	}
	auto swapc = shakersort(b[bi_same_a0j], a[0]);

	for (auto sc : swapc) {
		for (int i = 0; i < h; i++) {
			swap(b[i][sc.first], b[i][sc.second]);
		}
	}

	// 転置
	vector<int> ai0(h);
	vector<vector<int>> bt(w, vector<int>(h));
	for (int i = 0; i < h; i++) {
		ai0[i] = a[i][0];
		for (int j = 0; j < w; j++) {
			bt[j][i] = b[i][j];
		}
	}

	// aの0列と内容が同じbの列を探す
	int bj_same_ai0 = -1;
	for (int bj = 0; bj < h; bj++) {
		if (eqcontents(ai0, bt[bj]) == true) {
			bj_same_ai0 = bj;
		}
	}
	if (bj_same_ai0 == -1) {
		cout << "-1" << endl;
		return 0;
	}
	auto swapr = shakersort(bt[bj_same_ai0], ai0);

	for (auto sr : swapr) {
		swap(b[sr.first], b[sr.second]);
	}

	// 最終チェック
	bool ok = true;
	for (int i = 0; i < h && ok == true; i++) {
		for (int j = 0; j < w && ok == true; j++) {
			if (a[i][j] != b[i][j]) ok = false;
		}
	}

	if (ok == true)
		cout << swapc.size() + swapr.size() << endl;
	else
		cout << "-1" << endl;

	return 0;
}