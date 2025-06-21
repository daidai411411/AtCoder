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
	int n, q;
	cin >> n >> q;
	vector<int> a(q);
	for (int& ai : a) {
		cin >> ai;
		ai--;
	}

	int count = 0;
	vector<bool> is_black(n, false);
	for (int ai : a) {
		is_black[ai] = not is_black[ai];
		bool left_is_black = (ai > 0) and (is_black[ai - 1]);
		bool right_is_black = (ai < n - 1) and (is_black[ai + 1]);
		if (is_black[ai]) {
			if (not left_is_black and not right_is_black) count++;
			else if (left_is_black and right_is_black) count--;
		} else {
			if (not left_is_black and not right_is_black) count--;
			else if (left_is_black and right_is_black) count++;
		}
		cout << count << endl;
	}
	return 0;
}
