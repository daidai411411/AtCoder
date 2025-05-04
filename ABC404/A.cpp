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
	for (char c = 'a'; c <= 'z' ; c++) {
		if (s.find(c) == string::npos) {
			cout << c << endl;
			return 0;
		}
	}
	return 0;
}
