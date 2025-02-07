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
	int a, b, ans;
	cin >> a >> b;

	if (a == b) ans = 1;
	else if((abs(a - b) % 2) == 1) ans = 2;
	else ans = 3;

	cout << ans << endl;

	return 0;
}
