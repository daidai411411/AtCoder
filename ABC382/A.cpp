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
	int n, d;
	string s;
	cin >> n >> d >> s;

	int empty = count(s.begin(), s.end(), '.');
	empty += d;

	cout << empty << endl;

	return 0;
}
