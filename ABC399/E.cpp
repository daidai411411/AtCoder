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

bool CountCyclesExceptLoops(map<char, bool>& visited, const map<char, char>& replace_to, char c) {
	if (visited[c]) {
		if (replace_to.at(c) == c) return false;
		else return true;
	}
	visited[c] = true;
	if (replace_to.find(c) == replace_to.end()) return false;
	return CountCyclesExceptLoops(visited, replace_to, replace_to.at(c));
}

int Solve() {
	int n;
	string s, t;
	cin >> n >> s >> t;

	set<char> t_types;
	map<char, char> replace_to;
	for (int i = 0; i < n; i++) {
		t_types.insert(t[i]);
		if (replace_to.find(s[i]) == replace_to.end()) replace_to[s[i]] = t[i];
		else if (replace_to[s[i]] != t[i]) return -1;
	}

	if (t_types.size() == 26) return -1;

	int numof_cycles = 0;
	map<char, bool> visited;
	for (char c = 'a'; c <= 'z'; c++) {
		if (visited[c]) continue;
		numof_cycles += CountCyclesExceptLoops(visited, replace_to, c);
	}

	int ans = 0;

	return ans;
}

int main() {
	cout << Solve() << endl;
	return 0;
}
