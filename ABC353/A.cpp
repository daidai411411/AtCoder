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
	int n, h1;
	cin >> n >> h1;

	int higher_i = -1;
	for (int i = 2; i <= n; i++) {
		int h;
		cin >> h;

		if (h1 < h) {
			higher_i = i;
			break;
		}
	}

	cout << higher_i << endl;

	return 0;
}
