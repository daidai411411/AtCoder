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

struct Cell {
	ll r, c;
	constexpr Cell operator*(const ll s) const { return {this->r * s, this->c * s}; }
	constexpr void operator+=(const Cell& t) {
		this->r += t.r;
		this->c += t.c;
	}
};
map<const char, const Cell> dv{{'U', {-1, 0}}, {'D', {1, 0}}, {'L', {0, -1}}, {'R', {0, 1}}};

ll CountSameCell(Cell pt, Cell pa, char dt, char da, ll l) {
	ll rt = pt.r, ct = pt.c, ra = pa.r, ca = pa.c;
	string d{{dt, da}};
	if ((d == "UU" or d == "DD" or d == "LL" or d == "RR") and rt == ra and ct == ca) return l;
	else if (d == "UD" and ct == ca and abs(rt - ra) % 2 == 0 and 0 < rt - ra and rt - ra <= 2 * l) return 1;
	else if (d == "DU" and ct == ca and abs(rt - ra) % 2 == 0 and 0 < ra - rt and ra - rt <= 2 * l) return 1;
	else if (d == "LR" and rt == ra and abs(ct - ca) % 2 == 0 and 0 < ct - ca and ct - ca <= 2 * l) return 1;
	else if (d == "RL" and rt == ra and abs(ct - ca) % 2 == 0 and 0 < ca - ct and ca - ct <= 2 * l) return 1;
	else if (d == "UL" and rt + ct == ra + ca and 0 < rt - ra and rt - ra <= l) return 1;
	else if (d == "UR" and rt - ct == ra - ca and 0 < rt - ra and rt - ra <= l) return 1;
	else if (d == "DL" and rt - ct == ra - ca and 0 < ra - rt and ra - rt <= l) return 1;
	else if (d == "DR" and rt + ct == ra + ca and 0 < ra - rt and ra - rt <= l) return 1;
	else if (d == "LU" and rt + ct == ra + ca and 0 < ra - rt and ra - rt <= l) return 1;
	else if (d == "LD" and rt - ct == ra - ca and 0 < rt - ra and rt - ra <= l) return 1;
	else if (d == "RU" and rt - ct == ra - ca and 0 < ra - rt and ra - rt <= l) return 1;
	else if (d == "RD" and rt + ct == ra + ca and 0 < rt - ra and rt - ra <= l) return 1;
	else return 0;
}

int main(void) {
	Cell pt, pa;
	ll n, m, l;
	cin >> pt.r >> pt.c >> pa.r >> pa.c >> n >> m >> l;
	vector<char> s(m), t(l), directions_t, directions_a;
	vector<ll> a(m), b(l), distances;
	for (int i = 0; i < m; i++) cin >> s[i] >> a[i];
	for (int i = 0; i < l; i++) cin >> t[i] >> b[i];

	// printf("\n  T(%lld, %lld), A(%lld, %lld)\n", pt.r, pt.c, pa.r, pa.c);
	ll ans = 0;
	for (int it = 0, ia = 0; it < m;) {
		ll min_l = min(a[it], b[ia]);
		ll same_cell_count = CountSameCell(pt, pa, s[it], t[ia], min_l);
		ans += same_cell_count;
		pt += dv[s[it]] * min_l;
		pa += dv[t[ia]] * min_l;
		// printf("%c %c %lld:\n", s[it], t[ia], min_l);
		// printf("  T(%lld, %lld), A(%lld, %lld), %lld\n", pt.r, pt.c, pa.r, pa.c, same_cell_count);
		a[it] -= min_l;
		b[ia] -= min_l;
		if (a[it] == 0) it++;
		if (b[ia] == 0) ia++;
	}

	cout << ans << endl;

	return 0;
}
