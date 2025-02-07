#include <stdlib.h>

#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include <vector>

using namespace std;

int main() {
	int k, g, m, qg = 0, qm = 0;

	cin >> k >> g >> m;

	for (int i = 0; i < k; i++) {
		if (qg == g) {
			qg = 0;
		} else if (qm == 0) {
			qm = m;
		} else {
			qg += qm;
			qm = 0;
			if (qg > g) {
				qm = qg - g;
				qg = g;
			}
		}
	}
	
	cout << qg << ' ' << qm << endl;

	return 0;
}