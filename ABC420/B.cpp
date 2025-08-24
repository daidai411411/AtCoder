#include <algorithm>
#include <array>
#include <climits>
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

int main(void) {
	int n, m;
	cin >> n >> m;
	vector<string> s(n);
	for (string& si : s) cin >> si;

	vector<int> scores(n);
	for (int j = 0; j < m; j++) {
		int x = 0, y = 0;
		for (int i = 0; i < n; i++) {
			if (s[i][j] == '0') x++;
			else y++;
		}
		if (x == 0 or y == 0) {
			for (int i = 0; i < n; i++) scores[i]++;
		} else if (x < y) {
			for (int i = 0; i < n; i++) {
				if (s[i][j] == '0') scores[i]++;
			}
		} else {
			for (int i = 0; i < n; i++) {
				if (s[i][j] == '1') scores[i]++;
			}
		}
	}

	map<int, set<int>> scores_to_persons;
	for (int i = 0; i < n; i++) scores_to_persons[scores[i]].insert(i + 1);

	for (int i : (*(scores_to_persons.rbegin())).second) cout << i << ' ';
	cout << endl;
	return 0;
}
