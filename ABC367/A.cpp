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
	int a, b, c;
	cin >> a >> b >> c;
	if ((c < a and a < b) or (a < b and b < c) or (b < c and c < a)) cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}
