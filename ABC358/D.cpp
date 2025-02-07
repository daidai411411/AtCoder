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
	int N, M;
	cin >> N >> M;
	vector<ll> A(N, 0), B(M, 0);
	for (ll& Ai : A) cin >> Ai;
	for (ll& Bi : B) cin >> Bi;
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	ll total = 0;
	for (int i = 0, j = 0;;) {
		if (j == M) break;
		else if (i == N) {
			total = -1;
			break;
		} else if (A[i] < B[j]) i++;
		else if (A[i] >= B[j]) {
			total += A[i];
			i++;
			j++;
		}
	}

	cout << total << endl;

	return 0;
}
