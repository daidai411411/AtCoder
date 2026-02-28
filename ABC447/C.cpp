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

vector<int> CountA(string str, string removed) {
	vector<int> a_count(removed.length() + 1, 0);
	for (int i = 0, j = 0; i < a_count.size() and j < str.length(); j++) {
		if (str[j] == 'A') a_count[i]++;
		else i++;
	}
	return a_count;
}

int main(void) {
	string s, t;
	cin >> s >> t;

	string s_removed = s, t_removed = t;
	auto s_end = remove(s_removed.begin(), s_removed.end(), 'A');
	auto t_end = remove(t_removed.begin(), t_removed.end(), 'A');
	s_removed.erase(s_end, s_removed.end());
	t_removed.erase(t_end, t_removed.end());
	if (s_removed != t_removed) {
		cout << -1 << endl;
		return 0;
	}
	vector<int> s_count = CountA(s, s_removed);
	vector<int> t_count = CountA(t, t_removed);
	ll ans = 0;
	for (int i = 0; i < s_count.size(); i++) ans += abs(s_count[i] - t_count[i]);

	cout << ans << endl;

	return 0;
}
