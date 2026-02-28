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
	string s;
	cin >> s;
	map<int, set<char>> freq_to_chars;
	for (char c = 'a'; c <= 'z'; c++) {
		freq_to_chars[count(s.begin(), s.end(), c)].insert(c);
		// cout << c << count(s.begin(), s.end(), c) << endl;
	}
	for (char c : s) {
		if ((*freq_to_chars.rbegin()).second.find(c) != (*freq_to_chars.rbegin()).second.end()) continue;
		cout << c;
	}
	cout << endl;
	return 0;
}
