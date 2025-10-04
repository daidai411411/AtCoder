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
	int n;
	cin >> n;
	vector<int> l(n);
	for (auto& i : l) cin >> i;

	int left = 0, right = n;
	while (left < n and l[left] == 0) left++;
	while (right > 0 and l[right - 1] == 0) right--;
	int ans;
	if (left >= right) ans = 0;
	else ans = right - left - 1;

	cout << ans << endl;

	return 0;
}
