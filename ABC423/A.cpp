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

template <typename T>
bool ChMax(T& max, T val) {
	return (val > max) ? (max = val, true) : false;
}

int main(void) {
	int x, c;
	cin >> x >> c;

	int ans = 0;
	for (int i = 0;; i++) {
		int get = 1000 * i;
		int pay = c * i;
		if (x < get + pay) break;
		ChMax(ans, get);
	}

	cout << ans << endl;
	
	return 0;
}
