#include <algorithm>
#include <atcoder/all>
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
#include <unordered_set>
#include <vector>

using namespace std;
using ll = long long;

int main() {
	int Q;
	cin >> Q;

	int type, x;
	map<int, int> balls;
	for (int i = 0; i < Q; i++) {
		cin >> type;
		if (type == 1) {
			cin >> x;
			balls[x]++;
		} else if (type == 2) {
			cin >> x;
			balls[x]--;
			if (balls[x] == 0) balls.erase(x);
		} else if (type == 3) {
			cout << balls.size() << endl;
		}
	}

	return 0;
}
