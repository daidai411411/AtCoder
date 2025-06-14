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
	int n, k;
	cin >> n;
	vector<int> a(n);
	for (int& i : a) cin >> i;
	cin >> k;

	int count = 0;
	for (int i : a) {
		if (k <= i) count++;
	}

	cout << count << endl;
	return 0;
}
