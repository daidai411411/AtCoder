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
	int q, type, x;
	cin >> q;

	multiset<int> balls;
	for (int i = 0; i < q; i++) {
		cin >> type;
		if (type == 1) {
			cin >> x;
			balls.insert(x);
		} else {
			cout << *(balls.begin()) << endl;
			balls.erase(balls.begin());
		}
	}
	return 0;
}
