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
	string s;
	cin >> s;
	int ans = 0;
	char expect = 'i';
	for (int i = 0; i < s.length();) {
		if (s[i] == expect) i++;
		else ans++;
		expect = (expect == 'i') ? 'o' : 'i';
	}
	if (s.back() == 'i') ans++;
	cout << ans << endl;
	return 0;
}
