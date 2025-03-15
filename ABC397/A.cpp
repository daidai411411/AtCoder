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
	double x;
	cin >> x;
	int ans;
	if (x >= 38.0) ans = 1;
	else if (x >= 37.5) ans = 2;
	else ans = 3;
	cout << ans << endl;
	return 0;
}
