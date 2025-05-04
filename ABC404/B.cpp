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

int CountDiff(vector<string> s, vector<string> t) {
	int n = s.size();
	int count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			count += s[i][j] != t[i][j];
		}
	}
	return count;
}

vector<string> Rotate(vector<string> s) {
	int n = s.size();
	vector<string> dst(s);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dst[j][n - 1 - i] = s[i][j];
		}
	}
	return dst;
}

void ChMin(int& a, int b) {
	if (a > b) a = b;
}

int main() {
	int n;
	cin >> n;
	vector<string> s(n), t(n);
	for (string& i : s) cin >> i;
	for (string& i : t) cin >> i;

	int ans = 10000000;
	for (int i = 0; i < 4; i++) {
		ChMin(ans, i + CountDiff(s, t));
		s = Rotate(s);
	}

	cout << ans << endl;
	return 0;
}
