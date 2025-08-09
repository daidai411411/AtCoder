#include <algorithm>
#include <array>
#include <climits>
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
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
using ll = long long;
using ull = unsigned long long;

template <typename T>
bool ChMax(T& max, T val) {
	return (val > max) ? (max = val, true) : false;
}

double Calc(int l, int r, int x) {
	return (double)(x - 2.0) / (r - l - 1.0);
}

int main(void) {
	string s;
	cin >> s;
	int n = s.size();

	double max = 0;
	for (int l = 0; l < n; l++) {
		if (s[l] != 't') continue;
		int x = 0;
		for (int r = l; r < n; r++) {
			if (s[r] != 't') continue;
			x++;
			if (r - l >= 2) {
				ChMax(max, Calc(l, r, x));
			}
		}
	}

	cout << setprecision(16) << max << endl;

	return 0;
}
