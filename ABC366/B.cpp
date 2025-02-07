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
	int N, M = 0;
	cin >> N;
	vector<string> S(N);
	for (int i = 0; i < N; i++) {
		cin >> S[i];
		M = max(M, (int)(S[i].length()));
	}

	vector<string> T(M, "");
	for (int j = 0; j < M; j++) {
		bool is_tail = true;
		for (int i = 0; i < N; i++) {
			if (j < S[i].length()) {
				T[j] = S[i][j] + T[j];
				is_tail = false;
			} else if (!is_tail) {
				T[j] = "*" + T[j];
			}
		}
		cout << T[j] << endl;
	}

	return 0;
}
