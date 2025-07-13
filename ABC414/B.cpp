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

int main() {
	int n;
	cin >> n;
	vector<char> c(n);
	vector<ll> l(n);
	for (int i = 0; i < n; i++) cin >> c[i] >> l[i];

	string decoded;
	int length = 0;
	for (int i = 0; i < n and length <= 100;) {
		decoded += c[i];
		l[i]--;
		length++;
		if (l[i] == 0) i++;
	}

	cout <<  ((length > 100) ? "Too Long" : decoded) << endl;

	return 0;
}
