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
	string s;
	cin >> s;
	auto e = remove(s.begin(), s.end(), '.');
	s = string(s.begin(), e);
	cout << s << endl;
	return 0;
}
