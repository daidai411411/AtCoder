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

void Dfs(vector<string>& seqs, int n, int k, const vector<string>& s, int d = 0, string seq = "") {
	if (d == k) {
		seqs.push_back(seq);
		return;
	}
	for (const string& si : s) {
		Dfs(seqs, n, k, s, d + 1, seq + si);
	}
}

int main() {
	int n, k, x;
	cin >> n >> k >> x;
	vector<string> s(n);
	for (string& si : s) cin >> si;

	vector<string> seqs;
	Dfs(seqs, n, k, s);
	sort(seqs.begin(), seqs.end());

	cout << seqs[x - 1] << endl;

	return 0;
}
