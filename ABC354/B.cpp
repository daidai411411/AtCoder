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
	int N;
	cin >> N;
	vector<string> S(N);
	ll T = 0;
	for (int i = 0; i < N; i++) {
		int C;
		cin >> S[i] >> C;
		T += C;
	}
	sort(S.begin(), S.end());

	cout << S[T % N] << endl;

	return 0;
}
