#include <algorithm>
#include <atcoder/all>
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
#include <unordered_set>
#include <vector>

using namespace std;
using ll = long long;

int main() {
	int N;
	cin >> N;
	vector<vector<vector<ll>>> t(N + 1, vector<vector<ll>>(N + 1, vector<ll>(N + 1, 0ll)));
	for (int x = 1; x <= N; x++) {
		for (int y = 1; y <= N; y++) {
			for (int z = 1; z <= N; z++) {
				int A;
				cin >> A;
				t[x][y][z] = t[x - 1][y][z] + t[x][y - 1][z] + t[x][y][z - 1] - t[x][y - 1][z - 1] - t[x - 1][y][z - 1] - t[x - 1][y - 1][z] + t[x - 1][y - 1][z - 1] + A;
			}
		}
	}

	int Q;
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		int lx, rx, ly, ry, lz, rz;
		cin >> lx >> rx >> ly >> ry >> lz >> rz;
		lx--;
		ly--;
		lz--;
		ll sum = t[rx][ry][rz] - t[lx][ry][rz] - t[rx][ly][rz] - t[rx][ry][lz] + t[rx][ly][lz] + t[lx][ry][lz] + t[lx][ly][rz] - t[lx][ly][lz];
		cout << sum << endl;
	}

	return 0;
}
