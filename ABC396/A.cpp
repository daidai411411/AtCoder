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
	int n;
	cin >> n;
	vector<int> a(n);
	for (int& i : a) cin >> i;

	bool yes = false;
	for (int i = 0; i < n - 2; i++) {
		if (a[i] == a[i + 1] and a[i] == a[i + 2]) {
			yes = true;
			break;
		}
	}

	if (yes) cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}
