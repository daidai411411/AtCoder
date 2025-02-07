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
	vector<int> a(n);
	vector<int> balls(0);
	for (int i = 0; i < n; i++) {
		int ai;
		cin >> ai;
		balls.push_back(ai);

		while (true) {
			int size = balls.size();
			if (size <= 1 || balls[size - 1] != balls[size - 2]) break;
			else {
				balls.pop_back();
				balls[size - 2]++;
			}
		}
	}

	cout << balls.size() << endl;

	return 0;
}
