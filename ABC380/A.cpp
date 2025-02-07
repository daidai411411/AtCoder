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
	string n;
	cin >> n;
	int count_1 = 0, count_2 = 0, count_3 = 0;
	for (char c : n) {
		if (c == '1') count_1++;
		else if (c == '2') count_2++;
		else if (c == '3') count_3++;
	}

	if (count_1 == 1 and count_2 == 2 and count_3 == 3) cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}
