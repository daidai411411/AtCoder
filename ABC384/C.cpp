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
#include <stack>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;
using ll = long long;

int main() {
	vector<int> scores(5);
	for (int& i : scores) cin >> i;

	vector<vector<int>> players(31, vector<int>(2, 0));
	for (int i = 0; i < 31; i++) {
		players[i][1] = i + 1;
		players[i][0] = 0;
		for (int b = 0; b < 5; b++) {
			if (players[i][1] & (0b10000 >> b)) players[i][0] += scores[b];
		}
	}

	sort(players.rbegin(), players.rend());

	for (vector<int> p : players) {
		for (int b = 0; b < 5; b++) {
			if (p[1] & (0b10000 >> b)) cout << "ABCDE"[b];
		}
		cout << endl;
	}

	return 0;
}
