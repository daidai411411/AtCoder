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
	int n, r;
	cin >> n >> r;
	vector<int> l(n);
	for (auto& i : l) cin >> i;

	int left = 0, right = n;
	while (left < n and l[left] == 1) left++;
	while (right > 0 and l[right - 1] == 1) right--;
	int ans;
	if (left >= right) ans = 0;
	else {
		if (left > r) left = r;
		if (right < r) right = r;
		ans = right - left;
		for (int i = left; i < right; i++) ans += l[i];
	}

	cout << ans << endl;

	return 0;
}

// r0 d0 r1 d1 r2 d2 ...... r(n-1) d(n-1) rn