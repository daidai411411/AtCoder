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

int main() {
	string s;
	cin >> s;

	char prev = '#';
	for (char& c : s) {
		if (prev == '#' and c == '.') c = 'o';
		prev = c;
	}

	cout << s << endl;
	return 0;
}
