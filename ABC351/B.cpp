#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<vector<char>> a(n, vector<char>(n));
	vector<vector<char>> b(n, vector<char>(n));
	for (int r = 0; r < n; r++) {
		for (int c = 0; c < n; c++) {
			cin >> a[r][c];
		}
	}
	for (int r = 0; r < n; r++) {
		for (int c = 0; c < n; c++) {
			char b;
			cin >> b;

			if (a[r][c] != b){
				cout << r + 1 << " " << c + 1 << endl;
				return 0;
			}
		}
	}

	return 0;
}
