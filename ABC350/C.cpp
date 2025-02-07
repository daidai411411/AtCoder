#include <stdlib.h>

#include <algorithm>
#include <cmath>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> place(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i]--;
		place[a[i]] = i;
	}
	vector<vector<int>> hist;

	for (int i = 0; i < n; i++) {
		if (a[i] == i) continue;

		hist.push_back({i, place[i]});
		swap(a[i], a[place[i]]);
		swap(place[a[i]], place[a[place[i]]]);
	}

	cout << hist.size() << endl;
	for (vector<int> h : hist) cout << h[0] + 1 << " " << h[1] + 1 << endl;

	return 0;
}
