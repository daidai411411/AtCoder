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
	int n;
	cin >> n;
	int lpos = 0, rpos = 0, fatigue = 0;

	for (int i = 0; i < n; i++) {
		int a;
		char s;
		cin >> a >> s;
		if (s == 'L') {
			if (lpos != 0) fatigue += abs(lpos - a);
			lpos = a;
		} else {
			if (rpos != 0) fatigue += abs(rpos - a);
			rpos = a;
		}
	}

	cout << fatigue << endl;

	return 0;
}
