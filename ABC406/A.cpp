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
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if (c < a || (c == a && d < b)) cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}
