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

int main() {
	int n, x;
	cin >> n;
	vector<int> a(n);
	for (int& ai : a) cin >> ai;
	cin >> x;

	bool yes = (find(a.begin(), a.end(), x) != a.end());
	if (yes) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
