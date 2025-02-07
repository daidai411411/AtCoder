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
	int n, a, b;
	cin >> n >> a >> b;
	set<int> busy_days_in_week;
	for (int i = 0; i < n; i++) {
		int d;
		cin >> d;
		busy_days_in_week.insert(d % (a + b));
	}

	for (auto itr = busy_days_in_week.begin(); itr != busy_days_in_week.end(); itr++) {
		int holiday_start, holiday_end;
		holiday_start = *itr + 1;
		itr++;
		if (itr != busy_days_in_week.end()) {
			holiday_end = *itr;
		} else {
			holiday_end = *(busy_days_in_week.begin()) + a + b;
		}
		itr--;

		if (holiday_end - holiday_start >= b) {
			cout << "Yes" << endl;
			return 0;
		}
	}

	cout << "No" << endl;
	return 0;
}
