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

	int a = 0, ab = 0, abc = 0;
	for (char c : s) {
		if (c == 'A') a++;
		else if (c == 'B') {
			if (a > 0) {
				a--;
				ab++;
			}
		} else if (c == 'C') {
			if (ab > 0) {
				ab--;
				abc++;
			}
		}
	}

	cout << abc << endl;

	return 0;
}
