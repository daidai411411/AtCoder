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
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;

	int count_k = 0;
	int pre_rk = 0, lk = 0, rk = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '1' and (i == 0 or s[i - 1] == '0')) {
			lk = i;
		}
		if (s[i] == '1' and (i == n - 1 or s[i + 1] == '0')) {
			pre_rk = rk;
			rk = i;
			count_k++;
			if (count_k == k) break;
		}
	}

	string t = s.substr(0, pre_rk + 1);
	t += s.substr(lk, rk - lk + 1);
	t += s.substr(pre_rk + 1, lk - pre_rk - 1);
	t += s.substr(rk + 1, n - rk - 1);
	cout << t << endl;

	return 0;
}
