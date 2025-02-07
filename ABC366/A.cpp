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
	int N, T, A;
	cin >> N >> T >> A;

	if ((T <= A && N - T - A > A - T) || (A <= T && N - T - A > T - A)) cout << "No" << endl;
	else cout << "Yes" << endl;

	return 0;
}
