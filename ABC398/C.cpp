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

int main() {
	int n;
	cin >> n;

	map<ll, int> a_to_person;
	set<ll> unique, not_unique;
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		if (unique.find(a) != unique.end()) {
			unique.erase(a);
			not_unique.insert(a);
		} else if (not_unique.find(a) == not_unique.end()) {
			unique.insert(a);
			a_to_person[a] = i;
		}
	}

	if (unique.empty()) cout << -1 << endl;
	else cout << a_to_person[*(unique.rbegin())] << endl;

	return 0;
}
