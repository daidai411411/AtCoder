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
	int n;
	cin >> n;
	string s(n, '-');
	if (n % 2 == 0) s[n / 2 - 1] = s[n / 2] = '=';
	else s[(n - 1) / 2] = '=';
	cout << s << endl;
	return 0;
}
