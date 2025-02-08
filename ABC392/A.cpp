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
	int a1, a2, a3;
	cin >> a1 >> a2 >> a3;
	if (a1 * a2 == a3 or a2 * a3 == a1 or a3 * a1 == a2) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
