#include <stdlib.h>

#include <algorithm>
#include <cmath>
#include <iostream>
#include <list>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

int main() {
	long long n, m, k;
	cin >> n >> m >> k;
	if (n > m) swap(n, m);

	long long l = lcm(n, m);
	long long unit = l / n + l / m - 2;
	long long inunit = m / n + 1;

	long long ans = (k / unit) * l;
	k %= unit;
	if (k == 0) ans -= n;
	else {
		if (k % inunit == 0) ans += (k / inunit) * m;
		else ans += (k - k / inunit) * n;
	}

	cout << ans << endl;

	return 0;
}
