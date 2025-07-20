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

int main() {
	string s;
	cin >> s;

	bool first = true;
	for (int i = 1; i <= s.length(); i++) {
		if (s[i - 1] == '.') continue;
		if (first) {
			cout << i << ',';
			first = false;
		} else {
			cout << i << endl;
			first = true;
		}
	}
	return 0;
}
