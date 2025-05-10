#include <algorithm>
#include <array>
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

/*----------------------------------------------------------------------------------------------------------------------------*/
class CombMod {
   private:
	ll m_;
	vector<ll> fact_, inv_, fact_inv_;

   public:
	CombMod(const ll m, const ll n) : m_(m), fact_(n + 1), inv_(n + 1), fact_inv_(n + 1) {
		fact_[0] = fact_[1] = inv_[1] = fact_inv_[0] = fact_inv_[1] = 1;
		for (int i = 2; i <= n; i++) {
			fact_[i] = fact_[i - 1] * i % m_;
			inv_[i] = m_ - inv_[m_ % i] * (m_ / i) % m_;
			fact_inv_[i] = fact_inv_[i - 1] * inv_[i] % m_;
		}
	}

	ll Get(const ll n, const ll k) {
		return fact_[n] * (fact_inv_[k] * fact_inv_[n - k] % m_) % m_;
	}
};
