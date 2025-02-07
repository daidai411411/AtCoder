#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

constexpr int div_ceil(int dividend, int divisor) {
	return (dividend / divisor + ((dividend % divisor == 0) ? 0 : 1));
}

constexpr unsigned int to_natural(int z) {
	return ((z < 0) ? 0 : z);
}

int main(void) {
	int NS = 6, NM = 8, NL = 12;

	int N, S, M, L;
	cin >> N >> S >> M >> L;

	int total = div_ceil(N, NS) * S;
	for (int l = 0; l <= div_ceil(N, NL); l++) {
		for (int m = 0; m <= div_ceil(to_natural(N - NL * l), NM); m++) {
			int s = div_ceil(to_natural(N - NL * l - NM * m), NS);
			total = min(total, L * l + M * m + S * s);
		}
	}

	cout << total << endl;

	return 0;
}