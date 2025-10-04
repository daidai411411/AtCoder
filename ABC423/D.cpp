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

int main(void) {
	ll n, k;
	cin >> n >> k;
	vector<ll> a(n), b(n), c(n);
	for (int i = 0; i < n; i++) cin >> a[i] >> b[i] >> c[i];

	vector<ll> entering_time(n);
	priority_queue<array<ll, 3>, vector<array<ll, 3>>, greater<array<ll, 3>>> events;
	queue<ll> waiting;
	ll available = k;
	for (int i = 0; i < n; i++) events.push({a[i], 1, i});
	while (!events.empty()) {
		auto [time, type, guest] = events.top();
		events.pop();
		if (type == 1) {
			waiting.push(guest);
			// cout << time << ": come " << guest << endl;
		} else if (type == 2) {
			available += c[guest];
			// cout << time << ": exit " << guest << endl;
		}
		while (!waiting.empty() and c[waiting.front()] <= available) {
			// cout << time << ": enter " << waiting.front() << endl;
			entering_time[waiting.front()] = time;
			available -= c[waiting.front()];
			events.push({time + b[waiting.front()], 2, waiting.front()});
			waiting.pop();
		}
	}

	for (auto i : entering_time) cout << i << endl;

	return 0;
}
