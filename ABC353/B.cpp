#include <algorithm>
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
#include <vector>

using namespace std;
using ll = long long;

int main() {
	int n, k;
	cin >> n >> k;

	int count_start = 0, empty = k;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (a > empty) {
			count_start++;
			empty = k;
		}
		empty -= a;
	}

	cout << count_start + 1 << endl;

	return 0;
}
