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

	int N1 = 0, M1 = 0;
	for (int i = 0; i < N; i++) N1 = (N1 << 1) + 1;
	for (int i = 0; i < M; i++) M1 = (M1 << 1) + 1;

	vector<int> S(N, 0);
	for (int i = 0; i < N; i++) {
		string Sstr;
		cin >> Sstr;
		for (char c : Sstr) {
			S[i] <<= 1;
			if (c == 'o') S[i]++;
		}
	}

	int minimum = 10000000;
	for (int combi = 0b0; combi <= N1; combi++) {
		int kinds = 0b0, count_pop = 0;
		for (int i = 0; i < N; i++) {
			if (combi & (1 << (N - 1 - i))) {
				kinds |= S[i];
				count_pop++;
			}
		}

		if (kinds == M1) minimum = min(minimum, count_pop);
	}

	cout << minimum << endl;

	return 0;
}
