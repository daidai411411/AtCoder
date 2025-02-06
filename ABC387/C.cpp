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

int main() {
	string l_str, r_str;
	cin >> l_str >> r_str;
	vector<int> l(l_str.size()), r(r_str.size());
	for (int i = 0; i < l.size(); i++) l[i] = l_str[i] - '0';
	for (int i = 0; i < r.size(); i++) r[i] = r_str[i] - '0';

	ll count = 0;
	for (ll digits = l.size(); digits <= r.size(); digits++) {
		for (ll head = (digits == l.size() ? l[0] : 0); head <= (digits == r.size() ? r[0] : 9); head++) {
			count += pow(head, digits - 1);
		}
	}

	ll digits = l.size(), head = l[0];
	for (int digit = 1; digit <= digits; digit++) {
        cout -= () * pow(head, digits - digit);
	}

	cout << count << endl;

	return 0;
}
