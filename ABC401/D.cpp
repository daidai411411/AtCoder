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

int main() {
	int n, k;
	string s;
	cin >> n >> k >> s;

	string t = s;
	for (int i = 0; i < n; i++) {
		if (t[i] == '?' and ((i - 1 >= 0 and t[i - 1] == 'o') or (i + 1 < n and t[i + 1] == 'o'))) t[i] = '.';
	}
	vector<int> q_pos, q_len;
	for (int i = 0; i < n; i++) {
		if (t[i] != '?') continue;
		q_pos.emplace_back(i);
		q_len.emplace_back(0);
		for (; i < n and t[i] == '?'; i++) q_len.back()++;
	}

	int cnt_o = count(t.begin(), t.end(), 'o');
	int max_o = 0;
	for (int l : q_len) max_o += (l + 1) / 2;

	if (cnt_o == k) {
		replace(t.begin(), t.end(), '?', '.');
	}
	else if (cnt_o + max_o == k) {
		for (int i = 0; i < q_pos.size(); i++) {
			if (q_len[i] % 2 == 0) continue;
			for (int j = 0; j < q_len[i]; j++) {
				if (j % 2 == 0) t[q_pos[i] + j] = 'o';
				else t[q_pos[i] + j] = '.';
			}
		}
	}

	cout << t << endl;

	return 0;
}
