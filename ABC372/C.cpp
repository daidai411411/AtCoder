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
	int n, q;
	string s;
	cin >> n >> q >> s;

	int count = 0;
	vector<bool> is_abc(n, false);
	size_t pos = 0;
	while (true) {
		pos = s.find("ABC", pos);
		if (pos == string::npos) break;
		count++;
		is_abc[pos] = is_abc[pos + 1] = is_abc[pos + 2] = true;
		pos += 3;
	}

	for (int i = 0; i < q; i++) {
		int x;
		char c;
		cin >> x >> c;
		x--;

		if (s[x] == c) {
			cout << count << endl;
		} else {
			if (is_abc[x]) {
				count--;

				if (s[x] == 'A') is_abc[x] = is_abc[x + 1] = is_abc[x + 2] = false;
				else if (s[x] == 'B') is_abc[x - 1] = is_abc[x] = is_abc[x + 1] = false;
				else if (s[x] == 'C') is_abc[x - 2] = is_abc[x - 1] = is_abc[x] = false;
			}

			if (c == 'A' and x + 2 < n and s[x + 1] == 'B' and s[x + 2] == 'C') {
				count++;
				is_abc[x] = is_abc[x + 1] = is_abc[x + 2] = true;
			}
			if (c == 'B' and 0 <= x - 1 and x + 1 < n and s[x - 1] == 'A' and s[x + 1] == 'C') {
				count++;
				is_abc[x - 1] = is_abc[x] = is_abc[x + 1] = true;
			}
			if (c == 'C' and 0 <= x - 2 and s[x - 2] == 'A' and s[x - 1] == 'B') {
				count++;
				is_abc[x - 2] = is_abc[x - 1] = is_abc[x] = true;
			}

			s[x] = c;
			cout << count << endl;
		}
	}

	return 0;
}
