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
	double a, b;
	cin >> a >> b;

	if (a / b - floor(a / b) < ceil(a / b) - a / b) cout << (int)floor(a / b) << endl;
	else cout << (int)ceil(a / b) << endl;

	return 0;
}
