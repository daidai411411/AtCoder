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
	int n, m;
	cin >> n >> m;
	vector<int> k(m);
	vector<set<int>> food_to_dish(n + 1);
	for (int i = 0; i < m; i++) {
		cin >> k[i];
		for (int j = 0; j < k[i]; j++) {
			int a;
			cin >> a;
			food_to_dish[a].insert(i);
		}
	}
	vector<int> b(n);
	for (int& food : b) cin >> food;

	int count = 0;
	for (int food : b) {
		for (int dish : food_to_dish[food]) {
			k[dish]--;
			if (k[dish] == 0) count++;
		}
		cout << count << endl;
	}

	return 0;
}
