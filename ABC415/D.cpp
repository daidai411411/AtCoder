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

struct AB {
	ll a, b, loss;
};

int main() {
	ll n, m;
	cin >> n >> m;
	vector<AB> ab(m);
	for (int i = 0; i < m; i++) {
		cin >> ab[i].a >> ab[i].b;
		ab[i].loss = ab[i].a - ab[i].b;
	}

	sort(ab.begin(), ab.end(), [](const AB& l, const AB& r) { return (l.loss < r.loss); });
	// for (int i = 0; i < m; i++) cout << ab[i].a << ' ' << ab[i].b << endl;
	ll stickers = 0;
	for (int i = 0; i < m; i++) {
		cout << n << "  ";
		ll exchange_times = (n - ab[i].a) / ab[i].loss;
		n -= exchange_times * ab[i].loss;
		stickers += exchange_times;
		cout << ab[i].a << ' ' << ab[i].loss << ' ' << exchange_times << "  ";
		
		cout << n << endl;
	}

	cout << stickers << endl;

	return 0;
}

/*

n = a + e * l

*/