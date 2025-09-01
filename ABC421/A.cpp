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
	int n, x;
	string y;
	cin >> n;
	vector<string> s(n);
	for (auto& i : s) cin >> i;
	cin >> x >> y;

	if (s[x - 1] == y) cout << "Yes" << endl;
	else cout << "No" << endl;
	
	return 0;
}
