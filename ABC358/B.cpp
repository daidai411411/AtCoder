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
	int N, A;
	cin >> N >> A;

	int T, pre_T = 0, waiting = 0;
	for (int i = 0; i < N; i++) {
		cin >> T;
		waiting -= T - pre_T;
		if (waiting < 0) waiting = 0;

		waiting += A;
		cout << T + waiting << endl;

		pre_T = T;
	}

	return 0;
}
