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

int main() {
	int q;
	cin >> q;

	ll removed_len = 0;
	deque<ll> head, len;
	ll type, l, k;
	for (int i = 0; i < q; i++) {
		cin >> type;
		if (type == 1) {
			cin >> l;
			if (head.empty()) head.push_back(0);
			else head.push_back(head.back() + len.back());
			len.push_back(l);
		} else if (type == 2) {
			removed_len += len.front();
			head.pop_front();
			len.pop_front();
		} else {
			cin >> k;
			cout << head[k - 1] - removed_len << endl;
		}
	}

	return 0;
}
