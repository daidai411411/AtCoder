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
	string t, u;
	cin >> t >> u;

	for (int i = 0; i < t.size() - u.size() + 1; i++) {
		bool is_match = true;
		for (int j = 0; j < u.size(); j++) {
			if (t[i + j] == u[j] || t[i + j] == '?') continue;
			is_match = false;
			break;
		}
		if (is_match) {
			cout << "Yes" << endl;
			return 0;
		}
	}

	cout << "No" << endl;

	return 0;
}
