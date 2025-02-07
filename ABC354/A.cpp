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
#include <unordered_set>
#include <vector>

using namespace std;
using ll = long long;

int main() {
	int H;
	cin >> H;

	for (int i = 0;; i++) {
		if (H < (1 << i) - 1) {
			cout << i << endl;
			break;
		}
	}

	return 0;
}
