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
	string s;
	cin >> s;
	map<char, int> count;
	for (char c : s) count[c]++;
	if ((*count.begin()).second == 1) cout << (*count.begin()).first << endl;
	else cout << (*count.rbegin()).first << endl;
	return 0;
}
