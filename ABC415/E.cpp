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

int main() {
	int h, w;
	cin >> h >> w;
	vector<vector<ll>> a(h, vector<ll>(w));
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) cin >> a[i][j];
	}
	return 0;
}
