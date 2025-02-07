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

	vector<int> a;
	int count_hyphen = 0;
	for (char c : s) {
		if (c == '|' and count_hyphen != 0) {
			a.push_back(count_hyphen);
			count_hyphen = 0;
		}else if (c == '-'){
			count_hyphen++;
		}
	}

	for (int i : a) cout << i << " ";
	cout << endl;

	return 0;
}
