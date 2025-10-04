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

template <typename T>
bool ChMin(T& min, T val) {
	return (val < min) ? (min = val, true) : false;
}

int Solve(void) {
	int n;
	string s;
	cin >> n >> s;

	vector<char> ch;
	vector<int> len;
	char c = s[0];
	int l = 1;
	for (int i = 1; i < n; i++) {
		if (s[i] == c) {
			l++;
		} else {
			ch.push_back(c);
			len.push_back(l);
			c = s[i];
			l = 1;
		}
	}
	ch.push_back(c);
	len.push_back(l);

	int count0 = count(s.begin(), s.end(), '0');
	int count1 = count(s.begin(), s.end(), '1');
	int ans;
	if (ch[0] == '0') {
		count0 -= len[0];
		ans = 2 * count0 + count1;
	} else {
		count1 -= len[0];
		ans = count0 + 2 * count1;
	}

	for (int i = 1; i < ch.size(); i++) {
		int operations;

		if (ch[i] == '0') {
			count0 -= len[i];
			count1 += len[i - 1];
			operations = 2 * count0 + count1;
		} else {
			count0 += len[i - 1];
			count1 -= len[i];
			operations = count0 + 2 * count1;
		}

		if (ans == -1) ans = operations;
		else ChMin(ans, operations);
	}

	return ans;
}

int main(void) {
	int t;
	cin >> t;
	vector<int> ans(t);
	for (int i = 0; i < t; i++) ans[i] = Solve();
	for (int i = 0; i < t; i++) cout << ans[i] << endl;
	return 0;
}

/*
110010111100101

221121000011212


*/