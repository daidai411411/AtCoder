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

using namespace std;
using ll = long long;

int main() {
	vector<bool> row_has_piece(8, false);
	vector<bool> col_has_piece(8, false);
	for (int r = 0; r < 8; r++) {
		for (int c = 0; c < 8; c++) {
			char p;
			cin >> p;
			if (p == '#') {
				row_has_piece[r] = true;
				col_has_piece[c] = true;
			}
		}
	}

	int ans = count(row_has_piece.begin(), row_has_piece.end(), false) * count(col_has_piece.begin(), col_has_piece.end(), false);

	cout << ans << endl;

	return 0;
}
