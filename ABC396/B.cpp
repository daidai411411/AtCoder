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
	int q;
	cin >> q;

	vector<int> cards(100, 0);
	int t, x;
	for (int i = 0; i < q; i++) {
		cin >> t;
		if (t == 1) {
			cin >> x;
			cards.push_back(x);
		} else {
			cout << cards.back() << endl;
			cards.pop_back();
		}
	}

	return 0;
}
