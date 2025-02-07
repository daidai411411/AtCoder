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
	int m;
	cin >> m;
	vector<int> a;

	for (int i = 10; i >= 0;) {
		if (pow(3, i) <= m) {
			a.push_back(i);
			m -= pow(3, i);
		} else {
			i--;
		}
	}

	cout << a.size() << endl;
	for (int i : a) cout << i << " ";
	cout << endl;

	return 0;
}
