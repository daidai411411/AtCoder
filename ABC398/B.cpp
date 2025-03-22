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
	map<int, int> count;
	for (int i = 0; i < 7; i++) {
		int a;
		cin >> a;
		count[a]++;
	}

	int has_two = 0, has_three = 0;
	for (auto [a, c] : count) {
		if (c == 2) has_two++;
		else if (c >= 3) has_three++;
	}

	if (has_three >= 2 or (has_two >= 1 and has_three == 1)) cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}
