#include <algorithm>
#include <atcoder/all>
#include <cmath>
#include <cstdio>
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

vector<ll> Primes(ll m) {
	vector<bool> is_prime(m + 1, true);
	vector<ll> primes;

	for (int i = 2; i <= m; i++) {
		if (!is_prime[i]) continue;
		for (int j = i * 2; j <= m; j += i) is_prime[j] = false;
	}
	for (int i = 2; i <= m; i++) {
		if (is_prime[i]) primes.push_back(i);
	}

	return primes;
}

int main() {
	ll n;
	cin >> n;
	ll rt2_n = sqrt(n);
	ll rt8_n = sqrt(sqrt(rt2_n));

	vector<ll> primes = Primes(rt2_n);

	ll count = 0;
	for (int i = 0; i < primes.size(); i++) {
		for (int j = i + 1; j < primes.size(); j++) {
			if (primes[i] * primes[j] > rt2_n) break;
			count++;
		}
	}
	for (ll a : primes) {
		if (a > rt8_n) break;
		count++;
	}

	cout << count << endl;

	return 0;
}

/*

36 = 2^2 * 3^2
100 = 2^2 * 5^2
196 = 2^2 * 7^2

a^2 * b^2
a^8

*/