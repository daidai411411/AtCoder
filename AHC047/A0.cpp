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

int ArgMax(const vector<double>& v) {
	return distance(v.begin(), max_element(v.begin(), v.end()));
}

void Solve(int n, int m, int l, vector<string>& s, vector<double>& p, vector<char>& c, vector<vector<int>>& a) {
	int max_index = ArgMax(p);
    for (int i = 0; i < s[max_index].size(); i++) {
        c[i] = s[max_index][i];
        a[i][(i + 1) % s[max_index].size()] = 100;
    }
    for (int i = s[max_index].size(); i < m; i++) a[i][0] = 100;
}

int main(void) {
	int n, m, l;
	cin >> n >> m >> l;
	vector<string> s(n);
	vector<double> p(n);
	for (int i = 0; i < n; i++) cin >> s[i] >> p[i];
	vector<char> c(m, 'a');
	vector<vector<int>> a(m, vector<int>(m, 0));

	Solve(n, m, l, s, p, c, a);

	for (int i = 0; i < m; i++) {
		cout << c[i];
		for (int j = 0; j < m; j++) cout << ' ' << a[i][j];
		cout << endl;
	}
	return 0;
}