#include <stdlib.h>

#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include <vector>

using namespace std;

int main() {
	int m, n;
	string s;
	cin >> n >> m >> s;

	int am = m, al = 0, l = 0;

	for (auto c : s) {
		if (c == '0') {
			am = m;
			al = l;
		} else if (c == '1' && am > 0) {
			am--;
		} else {
			if (al == 0) {
				l++;
			} else {
				al--;
			}
		}
	}

	cout << l << endl;

	return 0;
}