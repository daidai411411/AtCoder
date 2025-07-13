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

ll Pow10(int n) {
	ll pow10 = 1;
	for (int i = 0; i < n; i++) pow10 *= 10;
	return pow10;
}

ll Num10(int len, ll half10) {
	ll num10 = half10;
	int half_len = (len + 1) / 2;
	for (int i = len % 2; i < half_len; i++) num10 = num10 * 10 + ((half10 / Pow10(i)) % 10);
	return num10;
}

vector<int> NumA(ll num10, ll a) {
	vector<int> num_a;
	while (num10 > 0) {
		num_a.push_back(num10 % a);
		num10 /= a;
	}

	return num_a;
}

bool IsPalindrome(vector<int> num) {
	bool is_palindrome = true;
	for (int i = 0; i < num.size() / 2; i++) {
		if (num[i] != num[num.size() - 1 - i]) {
			is_palindrome = false;
			break;
		}
	}
	return is_palindrome;
}

int main() {
	ll a, n;
	cin >> a >> n;

	ll sum = 0;
	for (int len = 1; len <= 12; len++) {
		int half_len = (len + 1) / 2;
		for (ll half10 = Pow10(half_len - 1); half10 < Pow10(half_len); half10++) {
			ll num10 = Num10(len, half10);
			if (num10 > n) break;
			vector<int> num_a = NumA(num10, a);
			if (IsPalindrome(num_a)) {
				sum += num10;
				// cout << num10 << ' ';
				// for (auto i = num_a.rbegin(); i != num_a.rend(); i++) cout << *i;
				// cout << endl;
			}
		}
	}

	cout << sum << endl;
	return 0;
}
